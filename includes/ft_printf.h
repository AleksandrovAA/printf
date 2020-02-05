/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:34 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/05 17:25:24 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

/*
** --------------------------- FLAGS MASKS ------------------------------------
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
** --------------------------- MODIFERS MASKS ----------------------------------
*/
# define MODIFERS	"hl"
# define M_SHORT	(1 << 0)
# define M_SHORT_2	(1 << 1)
# define M_LONG		(1 << 2)
# define M_LONG_2	(1 << 3)

/*
** --------------------------- ALL SPECIFIER -----------------------------------
*/
# define S_INT		"dDi"
# define S_UINT		"uU"
# define S_HEX		"xXp"
# define S_OCT		"oO"
# define S_FLOAT	"fF"
# define S_CHAR		"cC"
# define S_STR 		"sS"
# define PERCENT	"%"

# define ORI_LEFT	0
# define ORI_RIGHT	1

# define B_16	    16
# define BASE_8		8

typedef struct	s_printf
{
	t_si		m;
	t_si		f;
	t_uc		c;
	t_ui		len;
	t_ui		width;
	t_l			precision;
	char		*format;
	va_list		arg;
	t_l			done;
}				t_printf;

/*
** --------------------------- FUNCTIONS --------------------------------------
*/
void			parse_modifers(t_printf *p);
void			parse_point(t_printf *p);
void			parse_flags(t_printf *p);
int				ft_printf(const char *format, ...);
void			parse_format(t_printf *p);

void			search_specifier(t_printf *p);
void			handle_specifier(t_printf *p);

void			print_nbr(t_printf *p, char *s, char *pref);
void			handle_int(t_printf *p);
void			handle_uint(t_printf *p);
void			handle_hex(t_printf *p);
void			handle_oct(t_printf *p);

void			putchars(t_printf *p, char c, int count, t_si ori);
void			handle_char(t_printf *p);
void			handle_str(t_printf *p);

#endif
