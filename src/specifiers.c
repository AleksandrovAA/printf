/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:30:16 by ngale             #+#    #+#             */
/*   Updated: 2020/02/05 16:46:17 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_specifier(t_printf *p)
{
	p->c = *p->format;
	if (ft_strchr(S_INT, p->c))
		handle_int(p);
	else if (ft_strchr(S_UINT, p->c))
		handle_uint(p);
	else if (ft_strchr(S_HEX, p->c))
		handle_hex(p);
	else if (ft_strchr(S_OCT, p->c))
		handle_oct(p);
	else if (ft_strchr(S_CHAR, p->c))
		handle_char(p);
	else if (ft_strchr(S_STR, p->c))
		handle_str(p);
	else if (ft_strchr(PERCENT, p->c))
		print_nbr(p, 0, "%");
	else
		return ;
}

void	handle_specifier(t_printf *p)
{
	p->f = 0;
	p->m = 0;
	p->width = 0;
	p->precision = 0;
	parse_flags(p);
	parse_modifers(p);
	parse_flags(p);
	parse_point(p);
	search_specifier(p);
}
