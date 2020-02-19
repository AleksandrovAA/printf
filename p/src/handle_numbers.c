/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpythago <fpythago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:23 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/19 16:17:55 by fpythago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			handle_int(t_printf *p)
{
	char		*str_int;
	char		*pref;

	if (p->m & M_LONG || p->m & M_LONG_2)
		str_int = (p->m & M_LONG) ? ft_lltoa(va_arg(p->arg, t_l))
						: ft_lltoa(va_arg(p->arg, t_ll));
	else if (p->m & M_SHORT || p->m & M_SHORT_2)
		str_int = (p->m & M_SHORT) ? ft_lltoa((t_si)va_arg(p->arg, int))
						: ft_lltoa((char)va_arg(p->arg, int));
	else
		str_int = ft_lltoa(va_arg(p->arg, int));
	p->len = ft_strlen(str_int);
	pref = (*str_int == '-' && p->len--) ? "-" : 0;
	pref = (!pref && p->f & F_PLUS) ? "+" : pref;
	pref = (!pref && p->f & F_SPACE) ? " " : pref;
	buffer_add_nbr(p, str_int + (*str_int == '-'), pref);
	ft_memdel((void **)&str_int);
}

void			handle_uint(t_printf *p)
{
	char		*str_uint;

	p->m |= (p->c == 'U') ? M_LONG : 0;
	if (p->m & M_LONG || p->m & M_LONG_2)
		str_uint = (p->m & M_LONG) ? ft_ulltoa_base(va_arg(p->arg,
						t_ul), BASE_10, 0) :
							ft_ulltoa_base(va_arg(p->arg, t_ull), BASE_10, 0);
	else if (p->m & M_SHORT || p->m & M_SHORT_2)
		str_uint = (p->m & M_SHORT) ?
				ft_ulltoa_base((t_usi)va_arg(p->arg, t_ui), BASE_10, 0) :
							ft_ulltoa_base((t_uc)va_arg(p->arg,
								t_ui), BASE_10, 0);
	else
		str_uint = ft_lltoa(va_arg(p->arg, t_ui));
	p->len = ft_strlen(str_uint);
	buffer_add_nbr(p, str_uint, 0);
	ft_memdel((void **)&str_uint);
}

void			handle_hex(t_printf *p)
{
	char		*str_hex;
	char		*pref;
	t_uc		f_upcase;

	if (p->c == 'p')
	{
		p->m |= (M_LONG_2);
		p->f &= ~(F_ZERO | F_PLUS);
	}
	if (p->m & M_LONG || p->m & M_LONG_2)
		str_hex = (p->m & M_LONG) ? ft_ulltoa_base(va_arg(p->arg,
							t_ul), BASE_16, p->c) :
			ft_ulltoa_base(va_arg(p->arg, t_ull), BASE_16, p->c);
	else if (p->m & M_SHORT || p->m & M_SHORT_2)
		str_hex = (p->m & M_SHORT) ? ft_ulltoa_base((t_usi)va_arg(p->arg,
								t_ui), BASE_16, p->c) :
			ft_ulltoa_base((t_uc)va_arg(p->arg, t_ui), BASE_16, p->c);
	else
		str_hex = ft_ulltoa_base(va_arg(p->arg, t_ui), BASE_16, p->c);
	f_upcase = ('A' <= p->c && p->c <= 'Z' && p->f & F_SHARP);
	p->len = ft_strlen(str_hex);
	pref = ((p->f & F_SHARP && *str_hex != '0') || p->c == 'p') ? "0x" : 0;
	pref = (pref && f_upcase) ? "0X" : pref;
	buffer_add_nbr(p, str_hex, pref);
	ft_memdel((void **)&str_hex);
}

void			handle_oct(t_printf *p)
{
	char		*str_oct;
	char		*pref;

	if (p->m & M_LONG || p->m & M_LONG_2)
		str_oct = (p->m & M_LONG) ? ft_ulltoa_base(va_arg(p->arg,
						t_ul), BASE_8, p->c) :
			ft_ulltoa_base(va_arg(p->arg, t_ull), BASE_8, p->c);
	else if (p->m & M_SHORT || p->m & M_SHORT_2)
		str_oct = (p->m & M_SHORT) ? ft_ulltoa_base((t_usi)va_arg(p->arg,
							t_ui), BASE_8, p->c) :
			ft_ulltoa_base((t_uc)va_arg(p->arg, t_ui), BASE_8, p->c);
	else
		str_oct = ft_ulltoa_base(va_arg(p->arg, t_ui), BASE_8, p->c);
	p->len = ft_strlen(str_oct);
	pref = (p->f & F_SHARP && p->len >= p->precision) ? "0" : 0;
	pref = (*str_oct == '0' && !(p->f & F_PRECI)) ? 0 : pref;
	buffer_add_nbr(p, str_oct, pref);
	ft_memdel((void **)&str_oct);
}

void			handle_float(t_printf *p)
{
	t_ld		real;
	t_l			i;
	t_vector	vec_float;
	char		*str_f;
	char		*pref;

	i = -1;
	real = (p->m & M_LONG_2) ? va_arg(p->arg, t_ld) : va_arg(p->arg, double);
	p->f |= (p->f & F_FZERO && !(p->f & F_MINUS)) ? F_ZERO : 0;
	pref = ((real < 0) && (real *= -1)) ? "-" : 0;
	p->precision = (!p->precision) ? STD_PRECI : p->precision;
	vector_init(&vec_float, p->precision, sizeof(char));
	str_f = ft_lltoa((t_ui)real);
	vector_move_back_data(&vec_float, (void **)&str_f, ft_strlen(str_f));
	vector_push_back(&vec_float, ".");
	while (++i <= p->precision && (str_f = ft_lltoa((t_ul)(real * 10) % 10)))
	{
		vector_move_back_data(&vec_float, (void **)&str_f, SAVE);
		real = real * 10 - (t_ui)real;
	}
    ft_round_precision(p, str_f = (char *)vec_float.data, &vec_float, i);
	//round_precision(p, str_f = (char *)vec_float.data, &vec_float);
	pref = (!pref && p->f & F_PLUS) ? "+" : pref;
	pref = (!pref && p->f & F_SPACE) ? " " : pref;
	buffer_add_nbr(p, str_f, pref);
	vector_destroy(&vec_float);
}
