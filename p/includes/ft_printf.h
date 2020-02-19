/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpythago <fpythago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:34 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/19 13:44:57 by fpythago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include "vector.h"
# define FLAGS		" +-#0*"
# define F_SPACE 	1
# define F_PLUS		2
# define F_MINUS	4
# define F_SHARP	8
# define F_ZERO		16
# define F_WILDCARD	32
# define F_PRECI	64
# define F_FZERO	128

# define MODIFIERS	"hljzL"
# define M_SHORT	1
# define M_SHORT_2	2
# define M_LONG		4
# define M_LONG_2	8

# define S_INT		"dDi"
# define S_UINT		"uU"
# define S_HEX		"xXp"
# define S_OCT		"oO"
# define S_FLOAT	"fF"
# define S_CHAR		"cC%"
# define S_STR 		"sS"

# define BASE_16	16
# define BASE_10    10
# define BASE_8		8

# define STR_NULL 	"(null)"
# define BUF_SIZE 	16
# define STD_PRECI  6
# define SAVE 		1

typedef struct	s_printf
{
	t_uc		m;
	t_uc		f;
	t_uc		c;
	t_ui		len;
	t_l			width;
	t_l			precision;
	char		*format;
	t_vector	buffer;
	va_list		arg;
}				t_printf;

int				ft_printf(const char *format, ...);

void			parse_format(t_printf *p);
void			parse_flags(t_printf *p);
void			parse_point(t_printf *p);
void			parse_modifiers(t_printf *p);
void			parse_specifier(t_printf *p);
void			handle_specifier(t_printf *p);

void			handle_int(t_printf *p);
void			handle_uint(t_printf *p);
void			handle_hex(t_printf *p);
void			handle_oct(t_printf *p);
void			handle_float(t_printf *p);

void			buffer_add_nbr(t_printf *p, char *s, char *pref);
void			buffer_add_char(t_printf *p);
void			buffer_add_str(t_printf *p);
void			buffer_set(t_printf *p, char c, int count, t_uc f_print);
void			buffer_push_array(t_printf *p, const char *s, size_t width);

t_ll            ft_round_digit(char **str, t_vector *vec_float, t_ll i, t_ll shift);
void            ft_round_precision(t_printf *p, char **str, t_vector *vec_float, t_ll i);

#endif
