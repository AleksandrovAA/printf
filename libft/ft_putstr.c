/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:05:17 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/09/27 16:05:19 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *s, int width)
{
	int i;
	int count;
	int len;

	count = 0;
	if (s && width > -1)
	{
		i = 0;
		len = ft_strlen(s);
		width = (width > 0) ? ft_min(len, width) : 0;
		while (i < width)
			count += ft_putchar(s[i++]);
	}
	return (count);
}
