/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_byte_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:37:05 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/07 17:33:36 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

size_t    vector_byte_size(const t_vector *vector)
{
    return ((vector) ? (vector->size * vector->element_size) : VECTOR_ERROR);
}
