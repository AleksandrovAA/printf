/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:46:57 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/07 17:29:35 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void    *vector_pop_front(t_vector *vector)
{
    void *element;

    if (!vector)
        return (NULL);
    element = vector->data;
    _vector_offset(vector, 0, NULL, OFFSET_LEFT); 
	vector->size--;
    return (element);
}

