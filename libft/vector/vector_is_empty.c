/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_is_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:16:07 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/07 16:20:33 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int     vector_is_empty(const t_vector *vector)
{
        if (!vector)
            return (VECTOR_ERROR);
        return (!vector->size);
}
