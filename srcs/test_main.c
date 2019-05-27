
#include <stdio.h>
#include "printf.h"

int main(void)
{
    char    test_char;
    char    *test_string;
    char    *test_pointer;
    short int     test_int;

    int res;
    int real_res;

    res = 0;
    real_res = 0;

    test_char = 't';
    test_string = "testing testing";
    test_pointer = test_string;
    test_int = 3456;

    res = ft_printf("MYpointer:%i\n", test_int);
    real_res = printf("RLpointer:%i\n", test_int);

    printf("my printf returns   : %i\n", res);
    printf("real printf returns : %i\n\n\n", real_res);
    return (0);
}