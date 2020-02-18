/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:23:50 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/12 14:53:55 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_H__
# define __VECTOR_H__
# include "libft.h"

/*
** --------------------------- DEFINITIONS  ------------------------------------------
*/

# define VECTOR_MIN_CAPACITY        4
# define VECTOR_SUCCESS             1
# define VECTOR_ERROR               0

/*
** --------------------------- ORIENTATION OFFSET ------------------------------------
*/

# define OFFSET_NO                  0
# define OFFSET_LEFT                1
# define OFFSET_RIGHT               2

/*
** --------------------------- MACROS -----------------------------------------------
*/

# if VECTOR_SPEED <= 0
    # define VECTOR_SPEED 	    2
# endif

# define VECTOR_INC_CAPACITY(size, speed) (size << speed)

/*
** --------------------------- STRUCTURE --------------------------------------------
*/

typedef struct  s_vector {
	void		*data;
	size_t		size;
	size_t		capacity;
	size_t		element_size;
}               t_vector;

/*
** --------------------------- FUNCTIONS ----------------------------------------------
** --------------------------- CONSTRUCTOR --------------------------------------------
*/

int				vector_init(t_vector *vector, size_t capacity, size_t element_size);
int				vector_copy(t_vector *dst, const t_vector *src);

/* 
** --------------------------- MOVE --------------------------------------------------
*/

int				vector_swap(t_vector *dst, t_vector *src);
int				vector_move(t_vector *dst, t_vector *src);
int             vector_move_data(t_vector *vector, void **data);
int             vector_move_back_data(t_vector *vector, void **data, size_t size);

/*
** --------------------------- INSERTION ---------------------------------------------
*/

int				vector_push_back(t_vector *vector, void	*element);
int 			vector_push_front(t_vector *vector, void *element);
int 			vector_insert(t_vector *vector, size_t index, void *element);
int             vector_push_data(t_vector *vector, void *data, size_t size);

/*
** --------------------------- GET ELEMENT -------------------------------------------
*/

void            *vector_get_element(t_vector *element, size_t index);

/*
** --------------------------- DELETION ----------------------------------------------
*/

void            *vector_pop_back(t_vector *vector);
void			*vector_pop_front(t_vector *vector);
int				vector_erase(t_vector *vector, size_t index);
int				vector_clear(t_vector *vector);
int				vector_destroy(t_vector *vector);

/*
** --------------------------- INFORMATION -------------------------------------------
*/

int             vector_is_empty(const t_vector *vector);
size_t          vector_byte_size(const t_vector *vector);
size_t          vector_free_size(const t_vector *vector);

/*
** --------------------------- MEMORY ------------------------------------------------
*/

int 			vector_resize(t_vector *vector, size_t new_size);
int             vector_reallocate(t_vector *vector);

/*
** --------------------------- PRIVATE -----------------------------------------------
*/

void            _vector_offset(t_vector *vector, size_t index, void *element, t_uc offset_flag);

#endif
