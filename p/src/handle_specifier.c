/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpythago <fpythago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:41:49 by fpythago          #+#    #+#             */
/*   Updated: 2020/02/17 17:08:00 by fpythago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_specifier(t_printf *p)
{
	p->f = 0;
	p->m = 0;
	p->width = 0;
	p->precision = 0;
	parse_flags(p);
	parse_point(p);
	parse_modifiers(p);
	parse_flags(p);
	parse_specifier(p);
}
