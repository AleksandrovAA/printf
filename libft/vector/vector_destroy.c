/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:37:29 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/07 14:37:31 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int vector_destroy(t_vector *vector)
{
    if (!vector)
        return (VECTOR_ERROR);
    ft_memdel(&vector->data);
    return (VECTOR_SUCCESS);
}

