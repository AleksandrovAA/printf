/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:04:43 by ngale             #+#    #+#             */
/*   Updated: 2020/02/11 19:04:46 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ll ft_pow(t_ll base, size_t e)
{
    t_ll res;

    res = 1;
    while (e-- >= 0)
        res *= base;
    return (res);
}

//char *ft_round(char **main, char **frac, int prec)
//{
//    int i;
//    char *tmp;
//
//    i = 0;
//    if ((*frac)[prec + 1] >= 5)
//    {
//        if (prec >= 1)
//        {
//            (*frac)[prec]++;
//            //*frac[6] = '\0';
//            //ft_bzero();
//            //tmp = *frac;
//            //*frac = ft_memalloc(6);
//            ft_strclr(*frac + prec);
//        }
//        else if (prec == 0 && (*frac)[prec] > 4)
//        {
//            while (*main[i])
//                i++;
//            *main[i]++;
//        }
//    }
//    return (*frac);
//}

void ft_round(char *str_m, char *str_fr, int prec)
{
    //char *str_m;
    //char *str_fr;
    char *tmp;
    int i;

    //str_m = ft_lltoa(main);
    //str_fr = ft_lltoa(fract);
    i = 0;
    if (str_fr[prec] >= 5)
    {
        if (prec >= 1)
        {
            str_fr[prec - 1] = (str_fr[prec - 1] + 1 - '0') % 10 + '0';
            ft_strclr(str_fr + prec);
        }
        else if (prec == 0 && str_fr[prec] > 4)
        {
            while (str_m[i])
                i++;
            str_m[i]++;
        }
    }

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:32:44 by ngale             #+#    #+#             */
/*   Updated: 2020/02/05 18:32:47 by ngale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //

//static char *ft_main(int shift, t_ull m)
//{
//    t_ll mi;
//    t_ll res;
//
//    ft_ll_new(&mi);
//    ft_ll_new(&res);
//    ft_ll_plus2(&mi, 1);
//    while (shift)
//    {
//        if ((m & (1ull << (64ull - (long)shift--))) && shift <= 63)
//        ft_ll_plus(&res, mi);
//        ft_ll_mul(&mi, 2);
//    }
//    return (ft_print_part(res, 'm'));
//}
//
//static char *ft_fract(int shift, t_ull m)
//{
//    t_lnum fi;
//    t_lnum res;
//
//    ft_lnum_new(&fi);
//    ft_lnum_new(&res);
//    ft_lnum_plus2(&res, 1);
//    ft_lnum_plus2(&fi, 1);
//    while (shift)
//    {
//        if ((m & (1ull << (shift-- - 64ull))) && shift <= 64)
//        ft_lnum_plus(&res, fi);
//        ft_lnum_mul(&res, 10);
//        ft_lnum_mul(&fi, 5);
//    }
//    return (ft_print_part(res, 'f'));
//}

void ft_bigint_ul(int e, t_ull m, char **main, char **frac)
{
    *main = ft_itoa(m >> (63 - (e - 16383)));
    *frac = *frac; //to cart
    //*frac = ft_fract(63 - (e - 16383), m);
}

//void max_min(int e, t_ull m, char **main, char **frac)
//{
//    *main = (e - 16383 < 0) ? ft_itoa(0) : ft_main(e - 16383 + 1, m);
//    *frac = (e - 16383 < 0) ? ft_fract(63 - (e - 16383), m) : ft_itoa(0);
////    if (e - 16383 < 0)
////    {
////        *main = ft_itoa(0);
////        *frac = ft_fract(63 - (e - 16383), m);
////    }
////    else if (e - 16383 > 63)
////    {
////        *main = ft_main_p(e - 16383 + 1, m);
////        *frac = ft_itoa(0);
////    }
//}

void len_frac_less_prec(int n, char **frac)
{
    char *tmp_c;
    char *tmp_prec;

    ft_bzero((void *)tmp_c, n);
    tmp_prec = *frac;
    *frac = ft_strjoin(tmp_prec, tmp_c);
    free(tmp_prec);
    free(tmp_c);
}

void ft_round(char *str_m, char *str_fr, int prec)
{
    // char *str_m;
    // char *str_fr;
    char *tmp;
    int i;

    // str_m = ft_lltoa(main);
    // str_fr = ft_lltoa(fract);
    i = 0;
    if (str_fr[prec] >= 5)
    {
        if (prec >= 1)
        {
            str_fr[prec - 1] = (str_fr[prec - 1] + 1 - '0') % 10 + '0';
            ft_strclr(str_fr + prec);
        }
        else if (prec == 0 && str_fr[prec] > 4)
        {
            while (str_m[i])
                i++;
            str_m[i]++;
        }
    }

}

static char *ft_ldouble(int s, int e, t_ull m, int prec) {
    int tmp;
    char *main;
    char *frac;

    if (e == 0 && m == 0) {
        main = ft_itoa(0);
        frac = ft_itoa(0);
    }
    else if (e - 16383 >= 0 && e - 16383 < 64)
        ft_bigint_ul(e, m, &main, &frac);
//    else if ((e - 16383 < 0) || (e - 16383 > 63))
//        max_min(e, m, &main, &frac);
    if ((tmp = ft_strlen(frac)) > prec)
        ft_round(&main, &frac, prec);
    else
        len_frac_less_prec(prec - tmp, &frac);
//    (prec != 0 && s == 1) ? main = ft_un(main, "-") : 0;
//    prec != 0 ? main = ft_un(main, ".") : 0;
//    prec != 0 ? main = ft_un(main, frac) : 0;
    free(frac);
    return (main);
}


/* void handle_float(t_printf *p)
{
    t_f f;
//    t_ll main;
//    t_ll fract;
    char *except;

    f = (t_lf)va_arg(p->arg, t_lf);
    except = (f == 1.0 / 0.0) ? "inf" : 0; //width
    except = (f == -1.0 / 0.0) ? "-inf" : 0;
    except = (f == 0.0 / 0) ? "nan" : 0;
    p->precision = (!p->precision) ? 6 : p->precision;
//    main = f;
//    f -= main;
//    ((fract = f * ft_pow(10, p->precision + 1)) < 0) ? fract *= -1 : 1;
    s = ((*(t_uint128 *) & f) >> 79) & 1;
    e = ((*(t_uint128 *) & f) >> 64) & 0x7FFF;
    m = (*(t_uint128 *) & f) & 0xFFFFFFFFFFFFFFFF;
    //ft_round(ft_lltoa(main), ft_lltoa(fract), p->precision);
    //ft_ldouble(s, e, m, p->precision);
}*/

void handle_float(t_printf *p)
{
    t_f f;
//    t_ll main;
//    t_ll fract;
    char *except;

    f = (t_lf)va_arg(p->arg, t_lf);
    except = (f == 1.0 / 0.0) ? "inf" : 0; //width
    except = (f == -1.0 / 0.0) ? "-inf" : 0;
    except = (f == 0.0 / 0) ? "nan" : 0;
    p->precision = (!p->precision) ? 6 : p->precision;

//    main = f;
//    f -= main;
//    ((fract = f * ft_pow(10, p->precision + 1)) < 0) ? fract *= -1 : 1;
    int s = ((*(t_uint128 *) & f) >> 79) & 1;
    t_ll e = ((*(t_uint128 *) & f) >> 64) & 0x7FFF;
    t_ull m = (*(t_uint128 *) & f) & 0xFFFFFFFFFFFFFFFF;
    //ft_round(ft_lltoa(main), ft_lltoa(fract), p->precision);
    //ft_ldouble(s, e, m, p->precision);
}

//typedef union u_float
//{
//    long double ld_float;
//    char c_float[16];
//}           t_float;
//
//int main() //побитовая визуализация
//{
//    t_float a;
//
//    a.ld_float = 17.25;
//    for (int i = 0; i < 10; i++)
//    {
//        printf("byte %d   ", i);
//        for (int b = 0; b < 8; b++)
//        {
//            printf("%d", (a.c_float[i] & (1 << b)) != 0);
//        }
//        printf("\n");
//    }
//    return 0;
//}