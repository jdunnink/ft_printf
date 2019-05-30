
#include <stdio.h>
#include "printf.h"

float   float_rand(float min, float max)
{
    float scale = rand() / (float) max;
    return (min + scale * (max - min));
}

int main(void)
{
    long double test;

    int res;
    int real_res;
    size_t test_counter;
    size_t fail_counter;

    res = 0;
    real_res = 0;
    test_counter = 1000;
    fail_counter = 0;
    while (test_counter > 0)
    {
        test = float_rand(0, 999.999);
        res = ft_printf("%+20.7Lf\n", test);
        real_res = printf("%+20.7Lf\n", test);
        printf("my printf returns   : %i\n", res);
        printf("real printf returns : %i\n\n\n", real_res);
        if (res != real_res)
            fail_counter++;
        printf("    current failures: %lu\n", fail_counter);
        test_counter--;
    }
    return (0);
}