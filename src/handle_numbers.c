/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:23 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/10 21:56:50 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "vector.h"

void handle_int(t_printf *p)
{
    char *str_int;
    char *pref;

    if (p->m & M_LONG || p->m & M_LONG_2)
        str_int = (p->m & M_LONG) ? ft_lltoa(va_arg(p->arg, t_l)) : ft_lltoa(va_arg(p->arg, t_ll));
    else if (p->m & M_SHORT || p->m & M_SHORT_2)
        str_int = (p->m & M_SHORT) ? ft_lltoa((t_si)va_arg(p->arg, int)) : ft_lltoa((char)va_arg(p->arg, int));
    else
        str_int = ft_lltoa(va_arg(p->arg, int));
    p->len = ft_strlen(str_int);
    pref = (*str_int == '-' && p->len--) ? "-" : 0;
    pref = (!pref && p->f & F_PLUS) ? "+" : pref;
    pref = (!pref && p->f & F_SPACE) ? " " : pref;
    print_nbr(p, str_int + (*str_int == '-'), pref);
    free(str_int);
}

void handle_uint(t_printf *p)
{
    char *str_uint;

    p->m |= (p->c == 'U') ?  M_LONG : 0;
    if (p->m & M_LONG || p->m & M_LONG_2)
        str_uint = (p->m & M_LONG) ? ft_ulltoa_base(va_arg(p->arg, t_ul), BASE_10, 0) :
                                     ft_ulltoa_base(va_arg(p->arg, t_ull), BASE_10, 0);
    else if (p->m & M_SHORT || p->m & M_SHORT_2)
        str_uint = (p->m & M_SHORT) ? ft_ulltoa_base((t_usi)va_arg(p->arg, t_ui), BASE_10, 0) :
                                      ft_ulltoa_base((t_uc)va_arg(p->arg, t_ui), BASE_10, 0);
    else
        str_uint = ft_lltoa(va_arg(p->arg, t_ui));
    p->len = ft_strlen(str_uint);
    print_nbr(p, str_uint, 0);
    free(str_uint);
}

void handle_hex(t_printf *p)
{
    char *str_hex;
    char *pref;

    if (p->c == 'p')
    {
    	p->m |= (M_LONG_2);
        p->f &= ~(F_ZERO | F_PLUS);
    }
    if (p->m & M_LONG || p->m & M_LONG_2)
        str_hex = (p->m & M_LONG) ? ft_ulltoa_base(va_arg(p->arg, t_ul), BASE_16, p->c) :
                                    ft_ulltoa_base(va_arg(p->arg, t_ull), BASE_16, p->c);
    else if (p->m & M_SHORT || p->m & M_SHORT_2)
        str_hex = (p->m & M_SHORT) ? ft_ulltoa_base((t_usi)va_arg(p->arg, t_ui), BASE_16, p->c) :
                                     ft_ulltoa_base((t_uc)va_arg(p->arg, t_ui), BASE_16, p->c);
    else
        str_hex = ft_ulltoa_base(va_arg(p->arg, t_ui), BASE_16, p->c);
    p->f |= ('A' <= p->c && p->c <= 'Z' && p->f & F_SHARP) ? F_UPCASE : 0;
    p->len = ft_strlen(str_hex);
    pref = ((p->f & F_SHARP && *str_hex != '0') || p->c == 'p') ? "0x" : 0;
    pref = (pref && p->f && p->f & F_UPCASE) ? "0X" : pref;
    print_nbr(p, str_hex, pref); 
    free(str_hex);
}

void handle_oct(t_printf *p)
{
	char *str_oct;
    char *pref;

	if (p->m & M_LONG || p->m & M_LONG_2)
		str_oct = (p->m & M_LONG) ? ft_ulltoa_base(va_arg(p->arg, t_ul), BASE_8, p->c) : 
                                    ft_ulltoa_base(va_arg(p->arg, t_ull), BASE_8, p->c);
	else if (p->m & M_SHORT || p->m & M_SHORT_2)
		str_oct = (p->m & M_SHORT) ? ft_ulltoa_base((t_usi)va_arg(p->arg, t_ui), BASE_8, p->c) :
                                     ft_ulltoa_base((t_uc)va_arg(p->arg, t_ui), BASE_8, p->c);
	else
		str_oct = ft_ulltoa_base(va_arg(p->arg, t_ui), BASE_8, p->c);
	p->len = ft_strlen(str_oct);
    pref = (p->f & F_SHARP && p->len >= p->precision) ? "0" : 0;
    pref = (*str_oct == '0' && !(p->f & F_PRECI)) ? 0 : pref;
    print_nbr(p, str_oct, pref);
	free(str_oct);
}

void ft_round_digit(char **str, t_vector *vec_float, t_ll i, t_ll shift)
{
    char *str_float;

    str_float = *str;
    if (str_float[i] > '4')
    {
        i -= shift;
        if ((str_float[i + shift] == '5' && ((str_float[i] - '0') & 1)) || str_float[i + shift] > '5')
        {
            while (str_float[i] == '9')
            {
                (i > -1) ? str_float[i--] = '0' : i++;
                (str_float[0] == '0') ? vector_push_front(vec_float, (void *) &str_float[0]) : 0;
                (str_float[0] == '0') ? str_float[0] = '1' : 0;
            }
            str_float[i]++;
        }
    }
}

void ft_round_precision(t_printf *p, char **str, t_vector *vec_float, t_ll i)
{
    char *str_float;

    str_float = *str;
    if (p->f & F_PRECI)
    {
        i = ft_strchri(str_float, '.') + 1;
        ft_round_digit(&str_float, vec_float, i, 2);
        p->precision = 0;
        str_float[ft_strchri(str_float, '.') + ((p->f & F_SHARP) != 0)] = '\0';
        p->f &= ~F_PRECI;
    }
    else
    {
        i = ft_strchri(str_float, '.') + p->precision + 1;
        ft_round_digit(&str_float, vec_float, i, 1);
        (str_float[i] == '.') ? i-- : 0;
        ft_round_digit(&str_float, vec_float, i, 1);
        str_float[ft_strchri(str_float, '.') + p->precision + 1] = '\0';
    }
}

void handle_float(t_printf *p)
{
    t_ld real;
    t_vector vec_float;
    char *str_float;
    char *pref;
    t_ll i;

    pref = 0;
    i = 0;
    real = (p->m & M_LONG_2) ? va_arg(p->arg, t_ld) : va_arg(p->arg, double);
    p->f |= (p->f & F_ZERO && !(p->f & F_MINUS)) ? F_ZERO : 0;
    if (real < 0.)
    {
        pref = "-";
        p->len--;
        real = -real;
    }
    p->precision = (!p->precision) ? STD_PRECI : p->precision;
    vector_init(&vec_float, p->precision, sizeof(char));
    str_float = ft_lltoa((t_ui)real);
    vector_move_back_data(&vec_float, (void **)&str_float, ft_strlen(str_float));
    vector_push_back(&vec_float, ".");
    while ((long)i <= p->precision)
    {
        str_float = ft_lltoa((t_ul)(real * 10) % 10);
        vector_move_back_data(&vec_float, (void **)&str_float, SAVE);
        real = real * 10 - (t_ui)real;
        i++;
    }
    str_float = (char *)vec_float.data;
    ft_round_precision(p, &str_float, &vec_float, i);
    p->len = ft_strlen(str_float);
    pref = (!pref && p->f & F_PLUS) ? "+" : pref;
    pref = (!pref && p->f & F_SPACE) ? " " : pref;
    print_nbr(p, str_float, pref);
    vector_destroy(&vec_float);
}