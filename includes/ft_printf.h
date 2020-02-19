/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:34 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/10 17:20:44 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF__
# define __FT_PRINTF__
# include <stdarg.h>
# include "libft.h"
# include "vector.h"

/*
** --------------------------- FLAGS MASKS ---------------------------------------------
*/

# define FLAGS		" +-#0*"
# define F_SPACE 	(1 << 0)
# define F_PLUS		(1 << 1)
# define F_MINUS	(1 << 2)
# define F_SHARP	(1 << 3)
# define F_ZERO		(1 << 4)
# define F_WILDCARD	(1 << 5)
# define F_PRECI	(1 << 6)
# define F_UPCASE	(1 << 7)

/*
** --------------------------- MODIFIERS MASKS ------------------------------------------
*/

# define MODIFIERS	"hljz"
# define M_SHORT	(1 << 0)
# define M_SHORT_2	(1 << 1)
# define M_LONG		(1 << 2)
# define M_LONG_2	(1 << 3)

/*
** --------------------------- ALL SPECIFIER ------------------------------------------
*/

# define S_INT		"dDi"
# define S_UINT		"uU"
# define S_HEX		"xXp"
# define S_OCT		"oO"
# define S_FLOAT	"fF"
# define S_CHAR		"cC%"
# define S_STR 		"sS"

/*
** --------------------------- NUMBER SYSTEM ------------------------------------------
*/

# define BASE_16	16
# define BASE_10    10
# define BASE_8		8

/*
** --------------------------- OTHER --------------------------------------------------
*/

# define STR_NULL 	"(null)"
# define BUF_SIZE 	16 
# define SAVE 		1
# define STD_PRECI  6

/*
** --------------------------- STRUCTURE -----------------------------------------------
*/

typedef struct	s_printf
{
	t_uc		m;
	t_uc		f;
	t_uc		c;
	t_ui		len;
	t_l    		width;
	t_l			precision;
	char		*format;
	t_vector 	buffer;
	va_list 	arg;
}				t_printf;

/*
** --------------------------- FUNCTIONS -----------------------------------------------
*/

int				ft_printf(const char *format, ...);

/*
** --------------------------- PARSE FORMAT --------------------------------------------
*/

void			parse_format(t_printf *);
void			parse_flags(t_printf *p);
void			parse_point(t_printf *p);
void     		parse_modifiers(t_printf *p);
void			parse_specifier(t_printf *p);
void			handle_specifier(t_printf *p);

/*
** --------------------------- HANDLE NUMBERS ------------------------------------------
*/

void			handle_int(t_printf *p);
void			handle_uint(t_printf *p);
void			handle_hex(t_printf *p);
void			handle_oct(t_printf *p);
void            handle_float(t_printf *p);

/*
** --------------------------- FLOATS ---------------------------------------------------
*/

t_ll ft_round_digit(char **str, t_vector *vec_float, t_ll i, t_ll shift);
void ft_round_precision(t_printf *p, char **str, t_vector *vec_float, t_ll i);

/*
** --------------------------- PRINT ----------------------------------------------------
*/

void 			print_nbr(t_printf *p, char *s, char *pref);
void			print_char(t_printf *p);
void			print_str(t_printf *p);

/*
** --------------------------- BUFFER --------------------------------------------------
*/

void			buffer_set(t_printf *p, char c, int count, t_uc f_print);
void			buffer_push_array(t_printf *p, const char *s, size_t width);

#endif
