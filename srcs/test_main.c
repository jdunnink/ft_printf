
#include <stdio.h>
#include "printf.h"

int main(void)
{
    double  test;

    int res;
    int real_res;

    res = 0;
    real_res = 0;

    test = -2938;

    res = ft_printf("%-#10.0f\n", test);
    real_res = printf("%-#10.0f\n", test);

    printf("my printf returns   : %i\n", res);
    printf("real printf returns : %i\n\n\n", real_res);
    return (0);
}

