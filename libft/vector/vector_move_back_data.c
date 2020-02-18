/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_move_back_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:58:44 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/12 14:34:21 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int     vector_move_back_data(t_vector *vector, void **data, size_t size)
{
    if (!vector_push_data(vector, *data, size))
        return (VECTOR_ERROR);
    ft_memdel(data);
    return (VECTOR_SUCCESS);
}
