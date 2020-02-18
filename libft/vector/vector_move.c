/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:37:52 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/12 14:34:28 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int vector_move(t_vector *dst, t_vector *src)
{
    if (!src || !vector_destroy(dst))
        return (VECTOR_ERROR);
    *dst = *src;
    src->data = 0;
    return (VECTOR_SUCCESS);
}
