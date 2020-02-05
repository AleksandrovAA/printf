/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:23 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/05 17:05:48 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			parse_modifers(t_printf *p)
{
	while (1)
	{
		if (*p->format == 'h')
			p->m |= (1 << (p->format[1] == 'h' && p->format++));
		else if (*p->format == 'l')
			p->m |= (1 << (2 + (p->format[1] == 'l' && p->format++)));
		else
			return ;
		p->format++;
	}
}

void			parse_point(t_printf *p)
{
	if (ft_isdigit(*p->format))
	{
		p->width = ft_atoi(p->format);
		while (ft_isdigit(*p->format))
			++p->format;
	}
	if (*p->format == '.')
	{
		++p->format;
		p->precision = ft_atoi(p->format);
		while (ft_isdigit(*p->format))
			++p->format;
		p->f |= F_PRECI;
		p->f &= ~F_ZERO;
	}
}

void			parse_flags(t_printf *p)
{
	int			n;

	while ((n = ft_strchri(FLAGS, *p->format) > -1) && p->format++)
		p->f |= (1 << n);
	p->f &= (p->f & F_PLUS) ? (~F_SPACE) : 0xFFFF;
	if (p->f & F_WILDCARD && (p->width = va_arg(p->arg, int) < 0))
	{
		p->f |= F_MINUS;
		p->width = -p->width;
	}
}

void			parse_format(t_printf *p)
{
	while (*p->format)
	{
		if (*p->format == '%')
		{
			p->format++;
			if (*p->format)
				handle_specifier(p);
		}
		else
			p->done += ft_putchar(*p->format);
		p->format++;
	}
}

int				ft_printf(const char *format, ...)
{
	t_printf	p;

	ft_bzero(&p, sizeof(p));
	p.format = (char *)format;
	va_start(p.arg, format);
	parse_format(&p);
	va_end(p.arg);
	return (p.done);
}
