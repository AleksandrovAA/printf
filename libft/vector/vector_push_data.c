/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:34:00 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/11 17:22:23 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int     vector_push_data(t_vector *vector, void *data, size_t size)
{
    size_t i;

    i = 0;
    if (!vector || !data || !size)
        return (VECTOR_ERROR);
    while (i < size)
    {
        if (!vector_push_back(vector, data + i * vector->element_size))
            return (VECTOR_ERROR);
        i++;
    }
    return (VECTOR_SUCCESS);
}
