/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:34 by lcarmelo          #+#    #+#             */
/*   Updated: 2019/11/21 13:49:35 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF__
# define __FT_PRINTF__
# include <stdarg.h>
# include "libft.h"
# define SPECIFIIER "fdiouxXcsp"
# define FLAGS "#+-0hl*"
# define SPECIFIIER_INT "diouxXp"
# define SPECIFIIER_FLOAT "f"
# define SPECIFIIER_STR "cs"

typedef struct	s_flags
{
	int			zero;
	int 		plus;
	int			minus;
	int			oct;
	int			h;
	int			hh;
	int			l;
	int			ll;	
	int			L;
	int			width;
	int			accuracy;
}				t_flags;

int				ft_printf(const char *format, ...);
int				parse_format(va_list arg);
void			parse_arg(va_list arg);

t_flags			g_flags;
const char		*g_format;
int				g_count;
#endif
