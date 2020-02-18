/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:29:34 by ngale             #+#    #+#             */
/*   Updated: 2020/02/18 18:29:45 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_round_digit(char **str, t_vector *vec_float, t_ll i, t_ll shift)
{
    char *str_float;

    str_float = *str;
    if (str_float[i] > '4')
    {
        i -= shift;
        if ((str_float[i + shift] == '5' && ((str_float[i] - '0') & 1)) || str_float[i + shift] > '5')
        {
            while (str_float[i] == '9')
            {
                (i > -1) ? str_float[i--] = '0' : i++;
                (str_float[0] == '0') ? vector_push_front(vec_float, (void *) &str_float[0]) : 0;
                (str_float[0] == '0') ? str_float[0] = '1' : 0;
            }
            str_float[i]++;
        }
    }
}

void ft_round_precision(t_printf *p, char **str, t_vector *vec_float, t_ll i)
{
    char *str_float;

    str_float = *str;
    if (p->f & F_PRECI)
    {
        i = ft_strchri(str_float, '.') + 1;
        ft_round_digit(&str_float, vec_float, i, 2);
        p->precision = 0;
        str_float[ft_strchri(str_float, '.') + ((p->f & F_SHARP) != 0)] = '\0';
        p->f &= ~F_PRECI;
    }
    else
    {
        i = ft_strchri(str_float, '.') + p->precision + 1;
        ft_round_digit(&str_float, vec_float, i, 1);
        (str_float[i] == '.') ? i-- : 0;
        ft_round_digit(&str_float, vec_float, i, 1);
        str_float[ft_strchri(str_float, '.') + p->precision + 1] = '\0';
    }
}

void handle_float(t_printf *p)
{
    t_ld real;
    t_vector vec_float;
    char *str_float;
    char *pref;
    t_ll i;

    pref = 0;
    i = 0;
    real = (p->m & M_LONG_2) ? va_arg(p->arg, t_ld) : va_arg(p->arg, double);
    p->f |= (p->f & F_ZERO && !(p->f & F_MINUS)) ? F_ZERO : 0;
    if (real < 0.)
    {
        pref = "-";
        p->len--;
        real = -real;
    }
    p->precision = (!p->precision) ? STD_PRECI : p->precision;
    vector_init(&vec_float, p->precision, sizeof(char));
    str_float = ft_lltoa((t_ui)real);
    vector_move_back_data(&vec_float, (void **)&str_float, ft_strlen(str_float));
    vector_push_back(&vec_float, ".");
    while ((long)i <= p->precision)
    {
        str_float = ft_lltoa((t_ul)(real * 10) % 10);
        vector_move_back_data(&vec_float, (void **)&str_float, SAVE);
        real = real * 10 - (t_ui)real;
        i++;
    }
    str_float = (char *)vec_float.data;
    ft_round_precision(p, &str_float, &vec_float, i);
    p->len = ft_strlen(str_float);
    pref = (!pref && p->f & F_PLUS) ? "+" : pref;
    pref = (!pref && p->f & F_SPACE) ? " " : pref;
    print_nbr(p, str_float, pref);
    vector_destroy(&vec_float);
}
