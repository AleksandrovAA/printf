/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:23 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/10 21:56:54 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_nbr(t_printf *p, char *s, char *pref)
{
    p->len -= (p->f & F_PRECI && *s == '0');
    p->width -= FT_MAX(p->precision, p->len);
    p->width -= ft_strlen(pref);
    buffer_set(p, ' ', !(p->f & F_ZERO) ? p->width : 0, !(p->f & F_MINUS));
	buffer_push_array(p, pref, ft_strlen(pref));
    buffer_set(p, '0', (p->f & F_ZERO) ? p->width : p->precision - p->len, SAVE);
	buffer_push_array(p, s, p->len);
    buffer_set(p, ' ', p->width, p->f & F_MINUS);
}

void print_char(t_printf *p)
{
	buffer_set(p, (p->f & F_ZERO) ? '0' : ' ', p->width - 1, !(p->f & F_MINUS));
	buffer_set(p, p->c != '%' ? (t_uc)va_arg(p->arg, int) : p->c, 1, SAVE);
	buffer_set(p, ' ', p->width - 1, p->f & F_MINUS);
}

void print_str(t_printf *p)
{
	char *str;

	str = va_arg(p->arg, char *);
    str = (!str) ? STR_NULL : str;
	p->len = ft_strlen(str);
	p->precision = p->precision ? FT_MIN(p->len, p->precision) : p->len;
    p->precision = !(p->f & F_PRECI) ? p->precision : 0;
	p->width -= p->precision;
	buffer_set(p, (p->f & F_ZERO) ? '0' : ' ', p->width, !(p->f & F_MINUS));
	buffer_push_array(p, str, p->precision); 
	buffer_set(p, ' ', p->width, p->f & F_MINUS);
}
