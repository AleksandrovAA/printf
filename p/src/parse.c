/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpythago <fpythago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:23 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/19 17:34:11 by fpythago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			parse_modifiers(t_printf *p)
{
	while (ft_strchr(MODIFIERS, *p->format))
	{
		if (*p->format == 'h')
			p->m |= (1 << (p->format[1] == 'h' && p->format++));
		else if (*p->format == 'l')
			p->m |= (1 << (2 + (p->format[1] == 'l' && p->format++)));
		else
			p->m |= M_LONG_2;
		p->format++;
	}
}

void		parse_point(t_printf *p)
{
	if (ft_isdigit(*p->format))
	{
		p->width = ft_atoi(p->format);
		while (ft_isdigit(*p->format))
			++p->format;
	}
	while (*p->format == '.')
	{
		++p->format;
		p->precision = (*p->format == '*') ? va_arg(p->arg, int) :
											ft_atoi(p->format);
		while (ft_isdigit(*p->format) || (*p->format == '*'))
			++p->format;
		p->f |= (!p->precision) ? F_PRECI : 0;
		p->f &= (~F_ZERO);
	}
	p->f &= (!p->precision && p->f & F_MINUS) ? (~F_ZERO) : 0xFFFF;
}

void			parse_flags(t_printf *p)
{
	int		n;

	while (((n = ft_strchri(FLAGS, *p->format)) > -1) && p->format++)
		p->f |= (1 << n);
	p->f |= (p->f & F_ZERO) ? F_FZERO : 0;
	p->f &= (p->f & F_PLUS) ? (~F_SPACE) : 0xFFFF;
	p->f &= (p->f & F_PRECI) ? (~F_ZERO) : 0xFFFF;
	if (p->f & F_WILDCARD && ((p->width = va_arg(p->arg, int)) < 0))
	{
		p->f |= F_MINUS;
		p->width = -p->width;
	}
	p->f &= ~F_WILDCARD;
}

void			parse_specifier(t_printf *p)
{
	p->c = *p->format;
	if (ft_strchr(S_INT, p->c))
		handle_int(p);
	else if (ft_strchr(S_FLOAT, p->c))
		handle_float(p);
	else if (ft_strchr(S_UINT, p->c))
		handle_uint(p);
	else if (ft_strchr(S_HEX, p->c))
		handle_hex(p);
	else if (ft_strchr(S_OCT, p->c))
		handle_oct(p);
	else if (ft_strchr(S_CHAR, p->c))
		buffer_add_char(p);
	else if (ft_strchr(S_STR, p->c))
		buffer_add_str(p);
	else if (p->c)
		vector_push_back(&p->buffer, &p->c);
	else
		p->format--;
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
			else
				continue ;
		}
		else
			buffer_set(p, *p->format, 1, SAVE);
		p->format++;
	}
	write(1, (char *)p->buffer.data, vector_byte_size(&p->buffer));
}
