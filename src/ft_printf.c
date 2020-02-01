/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:23 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/29 22:30:41 by fpythago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void processing_width(char c, int w)
{
    int i;

    i = -1;
    while (++i < w)
        ft_putchar(c);
}

static void type_oct(char c)
{
    if (g_flags.oct || c == 'p')
    {
        g_flags.oct = 0;
        if (c == 'x' || c == 'p')
            g_flags.oct = 2;
        else if (c == 'X')
            g_flags.oct = 2;
        else if (c == 'o')
            g_flags.oct = 1;
    }
}

static void print_int(char c, char *s_int)
{
    if ((g_flags.oct && s_int[0] != '0') || c == 'p')
    {
        if (c == 'x' || c == 'p')
            ft_putstr("0x");
        else if (c == 'X')
            ft_putstr("0X");
        else if (c == 'o')
            ft_putchar('0');
    }
    if (g_flags.oct && s_int[0] == '0')
        g_flags.oct = 0;
    if (s_int[0] != '-' && g_flags.plus && !g_flags.minus)
        ft_putchar('+');
    ft_putstr(s_int);
}

static int proccesing_sign(char c)
{
    if (c == '-')
        ft_putchar('-');
    else if (g_flags.plus)
        ft_putchar('+');
    else
        return (0);
    return (1);
}

static void proccesing_int_flag(char c, char *s_int)
{
    type_oct(c);
    if (g_flags.minus)
    {
        print_int(c, s_int);
        processing_width(' ', g_flags.width - ft_strlen(s_int) - g_flags.oct);
    }
    else
    {
        g_flags.minus = g_flags.zero ? proccesing_sign(s_int[0]) : 0;
        processing_width(g_flags.zero ? '0' : ' ', g_flags.width - ft_strlen(s_int) - g_flags.minus - g_flags.oct);
        print_int(c, s_int + (g_flags.minus && s_int[0] == '-'));
    }
}

static int  proccesing_int(char c, va_list arg)
{
    char *s_int;

    if (c == 'd' || c == 'i')
    {
        if (g_flags.ll)
            s_int = ft_lltoa(va_arg(arg, t_ll));
        else if (g_flags.l)
            s_int = ft_lltoa(va_arg(arg, t_l));
        else
            s_int = ft_lltoa(va_arg(arg, int));
    }
    else if (c == 'u')
    {
        if (g_flags.ll)
            s_int = ft_lltoa(va_arg(arg, t_ull));
        else if (g_flags.l)
            s_int = ft_lltoa(va_arg(arg, t_ul));
        else
            s_int = ft_lltoa(va_arg(arg, t_ui));
    }
    else if (c == 'o')
    { 
        if (g_flags.ll)
            s_int = ft_ulltoa_base(va_arg(arg, t_ull), 8, 'o');
        else if (g_flags.l)
            s_int = ft_ulltoa_base(va_arg(arg, t_ul), 8, 'o');
        else
            s_int = ft_uitoa_base(va_arg(arg, int), 8, 'o');
    }
    else if (c == 'x' || c == 'p')
    {
        if (g_flags.ll || c == 'p') //
            s_int = ft_ulltoa_base(va_arg(arg, t_ull), 16, 'x');
        else if (g_flags.l)
            s_int = ft_ulltoa_base(va_arg(arg, t_ul), 16, 'x');
        else
            s_int = ft_uitoa_base(va_arg(arg, int), 16, 'x');
    }
    else if (c == 'X')
    {
        if (g_flags.ll)
            s_int = ft_ulltoa_base(va_arg(arg, t_ull), 16, 'X');
        else if (g_flags.l)
            s_int = ft_ulltoa_base(va_arg(arg, t_ul), 16, 'X');
        else
            s_int = ft_uitoa_base(va_arg(arg, int), 16, 'X');
    }
    else
        return (0);
    proccesing_int_flag(c, s_int);
    free(s_int);
    return (1);
}

static int  belongs_set(char c, char *s)
{
    int     len;

    len = ft_strlen(s);
    while (--len >= 0)
        if (c == s[len])
            return (1);
    return (0);
}

static void  print_float(double real)
{
    int byte;

    byte = -1;
    if (!g_flags.accuracy)
        g_flags.accuracy = 6;
    ft_putnbr((t_ui)real);
    ft_putchar('.');
    while (++byte < g_flags.accuracy)
    {
        real *= 10;
        ft_putnbr((int)real % 10);
    }
}

void ft_putstri(char *str)
{
    int i;
    int len;

    i = -1;
    len = ft_strlen(str);
    if (g_flags.accuracy)
        len = ft_min(len, g_flags.accuracy);
    while (++i < len)
        ft_putchar(str[i]);
}

static void proccesing_str_flag(char *s_str) //
{
    if (g_flags.minus)
    {
        ft_putstri(s_str);
        processing_width(' ', g_flags.width - ft_strlen(s_str));
    }
    else
    {
        processing_width(' ', g_flags.width - ft_strlen(s_str));
        ft_putstri(s_str);
    }
}

static int  proccesing_str(char c, va_list arg) //
{
    char *s_str;

    if (c == 'c')
    {
        if (g_flags.minus)
        {
            ft_putchar(va_arg(arg, int));
            processing_width(' ', g_flags.width - 1);
        }
        else
        {
            processing_width(' ', g_flags.width - 1);
            ft_putchar(va_arg(arg, int));
        }
        return (1);
    }
    else
        s_str = va_arg(arg, char *);
    proccesing_str_flag(s_str);
    return (1);
}



static char parse_flags_ap(va_list arg)
{
    while (*g_format && !belongs_set(*g_format, SPECIFIIER))
    {
        if (*g_format == '*' || ft_isdigit(*g_format))
            if ((g_flags.accuracy = ft_atoi(g_format)) == 0)
                g_flags.accuracy = va_arg(arg, int);
        g_format++;
    }
    return (*g_format);
}

static char parse_flags(va_list arg)
{
    while (*g_format && !belongs_set(*g_format, SPECIFIIER))
    {
        if (*g_format == '0')
            g_flags.zero = 1;
        else if (*g_format == '+')
            g_flags.plus = 1;
        else if (*g_format == '-')
            g_flags.minus = 1;
        else if (*g_format == '#')
            g_flags.oct = 1;
        else if (*g_format == '*' || ft_isdigit(*g_format))
        {
            if ((g_flags.width = ft_atoi(g_format)) == 0)
                g_flags.width = va_arg(arg, int);
            g_format += ft_strlen(ft_lltoa(g_flags.width)) - 1;
        }
        else if (*g_format == 'l')
            g_flags.l = (g_flags.ll = g_flags.l) ? 0 : 1;
        else if (*g_format == 'h')
            g_flags.h = (g_flags.hh = g_flags.h) ? 0 : 1;
        else if (*g_format == '.')
            return parse_flags_ap(arg);
        g_format++;
    }
    return (*g_format);
}

void     parse_arg(va_list arg)
{
    char c;

    c = parse_flags(arg);
    if (c == '%')
        ft_putchar('%');
    else if (belongs_set(c, SPECIFIIER_INT))
    {
        proccesing_int(c, arg);
    }
    else if (belongs_set(c, SPECIFIIER_FLOAT))
    {
        print_float(va_arg(arg, double));
    }
    else if (belongs_set(c, SPECIFIIER_STR))
    {
        proccesing_str(c, arg);
    }
}

static int search_specifier(void)
{
    int i;

    i = 0;
    while (g_format[i] && g_format[i] != '%')
    {
        if (belongs_set(g_format[i], SPECIFIIER))
            return (1);
        i++;
    }
    return (0);
}

int     parse_format(va_list arg)
{
    char *pf;

    while (*g_format)
    {
        if (*g_format == '%')
        {
            g_format++;
            ft_bzero(&g_flags, sizeof(g_flags));
            if (search_specifier())
				parse_arg(arg);
            else
                ft_putchar('%');
        }
        else
        {
            pf = (char *)g_format;
            while (*g_format && *g_format != '%')
                g_format++;
            write(1, pf, g_format - pf);
            g_format--;
        }
        g_format++;
    }
    return (1);
}

int     ft_printf(const char *format, ...)
{
    va_list arg;
    int		done;

    g_format = format;
    va_start(arg, format);
    done = parse_format(arg);
    va_end(arg);
    return (done);
}
