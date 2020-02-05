/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:17:15 by ngale             #+#    #+#             */
/*   Updated: 2020/02/05 17:03:10 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchars(t_printf *p, char c, int count, t_si ori)
{
	if (!count)
		return ;
	if (ori == ORI_LEFT && !(p->f & F_MINUS))
		while (count-- > 0)
			p->done += ft_putchar(c);
	else if (ori == ORI_RIGHT && (p->f & F_MINUS))
		while (count-- > 0)
			p->done += ft_putchar(c);
}

void	handle_char(t_printf *p)
{
	putchars(p, ' ', p->width - 1, ORI_LEFT);
	p->done += ft_putchar((t_uc)va_arg(p->arg, int));
	putchars(p, ' ', p->width - 1, ORI_RIGHT);
}

void	handle_str(t_printf *p)
{
	char *str;

	str = va_arg(p->arg, char *);
	p->len = ft_strlen(str);
	p->precision = p->precision ? ft_min(p->len, p->precision) : (t_l)p->len;
	p->width -= p->precision;
	putchars(p, ' ', p->width, ORI_LEFT);
	p->done += ft_putstr(str, p->precision);
	putchars(p, ' ', p->width, ORI_RIGHT);
}
