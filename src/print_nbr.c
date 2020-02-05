/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:11:51 by ngale             #+#    #+#             */
/*   Updated: 2020/02/05 17:02:25 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr(t_printf *p, char *s, char *pref)
{
	p->width -= ft_max(p->precision, p->len);
	p->width -= ft_strlen(pref);
	p->precision -= p->len;
	putchars(p, ' ', !(p->f & F_ZERO) ? p->width : 0, ORI_LEFT);
	p->done += ft_putstr(pref, ft_strlen(pref));
	putchars(p, '0', (p->f & F_ZERO) ? p->width : p->precision, ORI_LEFT);
	p->done += ft_putstr(s, ft_strlen(s));
	putchars(p, ' ', p->width, ORI_RIGHT);
}

void	handle_int(t_printf *p)
{
	char *str_int;
	char *pref;

	if (p->m & M_LONG || p->m & M_LONG_2)
		str_int = (p->f & M_LONG) ? ft_lltoa(va_arg(p->arg, t_l))
			: ft_lltoa(va_arg(p->arg, t_ll));
	else if (p->m & M_SHORT || p->m & M_SHORT_2)
		str_int = (p->f & M_SHORT) ? ft_lltoa((t_si)va_arg(p->arg, int))
			: ft_lltoa((char)va_arg(p->arg, int));
	else
		str_int = ft_lltoa(va_arg(p->arg, int));
	p->len = ft_strlen(str_int);
	pref = (*str_int == '-' && p->len--) ? "-" : 0;
	pref = (!pref && p->f & F_PLUS) ? "+" : pref;
	pref = (!pref && p->f & F_SPACE) ? " " : pref;
	print_nbr(p, str_int + (*str_int == '-'), pref);
	free(str_int);
}

void	handle_uint(t_printf *p)
{
	char *str_uint;

	if (p->m & M_LONG || p->m & M_LONG_2)
		str_uint = (p->f & M_LONG) ? ft_lltoa(va_arg(p->arg, t_ul))
			: ft_lltoa(va_arg(p->arg, t_ull));
	else if (p->m & M_SHORT || p->m & M_SHORT_2)
		str_uint = (p->f & M_SHORT) ? ft_lltoa((t_usi)va_arg(p->arg, t_ui))
			: ft_lltoa((t_uc)va_arg(p->arg, t_ui));
	else
		str_uint = ft_lltoa(va_arg(p->arg, t_ui));
	p->len = ft_strlen(str_uint);
	print_nbr(p, str_uint, 0);
	free(str_uint);
}

void	handle_hex(t_printf *p)
{
	char *str_hex;
	char *pref;

	if (p->c == 'p')
	{
		p->m |= M_LONG_2;
		p->f &= ~F_ZERO;
		p->f &= ~F_PLUS;
	}
	if (p->m & M_LONG || p->m & M_LONG_2)
		str_hex = (p->f & M_LONG) ? ft_ulltoa_base(va_arg(p->arg, t_ul), B_16,
				p->c) : ft_ulltoa_base(va_arg(p->arg, t_ull), B_16, p->c);
	else if (p->m & M_SHORT || p->m & M_SHORT_2)
		str_hex = (p->f & M_SHORT) ?
			ft_ulltoa_base((t_usi)va_arg(p->arg, t_ui), B_16, p->c)
			: ft_ulltoa_base((t_uc)va_arg(p->arg, t_ui), B_16, p->c);
	else
		str_hex = ft_ulltoa_base(va_arg(p->arg, t_ui), B_16, p->c);
	p->f |= ('A' <= p->c && p->c <= 'Z' && p->f & F_SHARP) ? F_UPCASE : 0;
	p->len = ft_strlen(str_hex);
	pref = (p->f & F_SHARP && *str_hex != '0') ? "0x" : 0;
	pref = (pref && p->c != 'p' && p->f && p->f & F_UPCASE) ? "0X" : pref;
	print_nbr(p, str_hex, pref);
	free(str_hex);
}

void	handle_oct(t_printf *p)
{
	char *str_oct;
	char *pref;

	if (p->m & M_LONG || p->m & M_LONG_2)
		str_oct = (p->f & M_LONG) ? ft_ulltoa_base(va_arg(p->arg, t_ul), BASE_8,
				p->c) : ft_ulltoa_base(va_arg(p->arg, t_ull), BASE_8, p->c);
	else if (p->m & M_SHORT || p->m & M_SHORT_2)
		str_oct = (p->f & M_SHORT) ?
			ft_ulltoa_base((t_usi)va_arg(p->arg, t_ui), BASE_8, p->c)
			: ft_ulltoa_base((t_uc)va_arg(p->arg, t_ui), BASE_8, p->c);
	else
		str_oct = ft_ulltoa_base(va_arg(p->arg, t_ui), BASE_8, p->c);
	p->len = ft_strlen(str_oct);
	pref = (p->f & F_SHARP && *str_oct != '0') ? "0" : 0;
	print_nbr(p, str_oct, pref);
	free(str_oct);
}
