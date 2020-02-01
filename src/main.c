#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    //ft_printf("%7p", "hello");
    int m = 78;
    printf("%p\n", &m);
    ft_printf("%p\n", &m);

    char *s = "gg";
    printf("%p\n", &s[0]);
    ft_printf("%p\n", &s[0]);

    int po;
    printf("%#20x\n", po);
    ft_printf("%#20x\n", po);
    //printf("\\");
    return (0);
}
