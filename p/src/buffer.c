/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpythago <fpythago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:23 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/19 16:28:33 by fpythago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		buffer_set(t_printf *p, char c, int count, t_uc f_save)
{
	while (f_save && count-- > 0 && vector_push_back(&p->buffer, &c))
		;
}

void		buffer_push_array(t_printf *p, const char *s, size_t width)
{
	size_t	i;
	size_t	len;

	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		width = ft_min(len, width);
		while (i < width && vector_push_back(&p->buffer, (char *)s + i++))
			;
	}
}

void		buffer_add_nbr(t_printf *p, char *s, char *pref)
{
	p->len -= (p->f & F_PRECI && *s == '0');
	p->f |= (p->precision < 0) ? F_ZERO : 0;
	p->precision = (p->precision > 0) ? p->precision : 0;
	p->width -= ft_max_l(p->precision, p->len);
	p->width -= ft_strlen(pref);
	buffer_set(p, ' ', !(p->f & F_ZERO) ? p->width : 0, !(p->f & F_MINUS));
	buffer_push_array(p, pref, ft_strlen(pref));
	buffer_set(p, '0', (p->f & F_ZERO) ? p->width :
						p->precision - p->len, SAVE);
	buffer_push_array(p, s, p->len);
	buffer_set(p, ' ', p->width, p->f & F_MINUS);
}

void		buffer_add_char(t_printf *p)
{
	buffer_set(p, (p->f & F_ZERO) ? '0' : ' ', p->width - 1, !(p->f & F_MINUS));
	buffer_set(p, p->c != '%' ? (t_uc)va_arg(p->arg, int) : p->c, 1, SAVE);
	buffer_set(p, ' ', p->width - 1, p->f & F_MINUS);
}

void		buffer_add_str(t_printf *p)
{
	char	*str;

	str = va_arg(p->arg, char *);
	str = (!str) ? STR_NULL : str;
	p->len = ft_strlen(str);
	p->precision = (p->precision > 0) ? ft_min_l(p->len, p->precision) : p->len;
	p->precision = !(p->f & F_PRECI) ? p->precision : 0;
	p->width -= p->precision;
	buffer_set(p, (p->f & F_ZERO) ? '0' : ' ', p->width, !(p->f & F_MINUS));
	buffer_push_array(p, str, p->precision);
	buffer_set(p, ' ', p->width, p->f & F_MINUS);
}
