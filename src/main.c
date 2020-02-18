#include "ft_printf.h"
#include "vector.h"
#include <stdio.h>

typedef long double t_ld;
typedef unsigned long t_ul;
typedef unsigned char t_uc;

typedef union u_float
{
    t_ld ld_float;
    char c_float[10];
}            t_float;


typedef struct s_float_flags
{
    short sign;
    short exp;
    t_ll mant;
    short x;
}                        t_float_flags;

int main(void)
{
//    t_float m_float;
//    int b;
//
//    //m_float.ld_float = 0.046875;
//    m_float.ld_float = -17.25;
//    for (int i = 0; i < 10; i++)
//    {
//        printf("byte %d\t", i);
//        //print_byte(m_float.c_float[i]);
//        for (b = 0; b < 8; b++)
//            printf("%d", (m_float.c_float[i] & (1 << b)) != 0);
//        printf("\n");
//    }
//
//    t_float_flags flags;
//
//    flags.sign = (short)(m_float.c_float[9] >> 7) != 0;
//    printf("%d\n", flags.sign);
//    m_float.c_float[9] = m_float.c_float[9] & 127; //sign
//    for (b = 0; b < 8; b++)
//        printf("%d", (m_float.c_float[9] & (1 << b)) != 0);
//    printf("\n");
//    unsigned char tmp;
//    flags.exp = (short)m_float.c_float[9] << 8;
//    for (int i = 14; i >= 0; i--)
//        printf("%d", (flags.exp & (1 << i)) != 0);
//    printf(" -1\n");
//    tmp = (m_float.c_float[8] << 8) >> 8;
//    for (int i = 14; i >= 0; i--)
//        printf("%d", (tmp & (1 << i)) != 0);
//    printf(" -2\n");
//
//    flags.exp |= tmp;
//    for (int i = 14; i >= 0; i--)
//        printf("%d", (flags.exp & (1 << i)) != 0);
//    flags.x = (flags.exp - (1 << 14)) + 1;
//    printf("\n%hi\n", flags.x);
    //printf("%.0f\n", 17.333333333333);
    printf("%.0f\n", 0.5);
    ft_printf("%.0f\n", 0.5);
    printf("%#.0f\n", 999.5);
    ft_printf("%#.0f\n", 999.5);
    printf("%.3f\n", 7.5275);
    ft_printf("%.3f\n", 7.5275);
    return (0);
}