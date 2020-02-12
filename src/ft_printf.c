/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:49:23 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/02/05 19:22:28 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>



int         ft_printf(const char *format, ...)
{
    t_printf p;

    ft_bzero(&p , sizeof(p));
	vector_init(&p.buffer, BUF_SIZE, sizeof(char));
    va_start(p.arg, format);
    p.format = (char *)format;
    parse_format(&p);
	vector_destroy(&p.buffer);
    va_end(p.arg);
    return (p.buffer.size);
}
