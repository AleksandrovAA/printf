/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:27:24 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/07 19:28:27 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_sqrt(size_t num)
{
	size_t root;
	size_t i;

	root = num;
	if (root + 1 < root)
		return (0);
	i = 2;
	while (i <= root)
	{
		if (i * i >= root)
			return (i);
		i++;
	}
	return (0);
}
