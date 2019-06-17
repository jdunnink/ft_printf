
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include "printf.h"

int     ldouble_random_test(int max_width, int max_precis, long long int max_range);
int     double_random_test(int max_width, int max_precis, int max_range);

int     int_random_test(int max_width, int max_precis);
int     uint_random_test(int max_width, int max_precis);
int     uint_random_test_zero(int max_width, int max_precis);
int     int_random_test_zero(int max_width, int max_precis);
int     char_random_test(int max_width, int min, int max);
int     string_random_test(int max_width, int max_precis, int min, int max);
int     ptr_random_test(int max_width);

/*

static long double ldouble_rand(long double min, long double max)
{
    long double scale;
    
    scale = rand() / (long double) RAND_MAX;
    return (min + scale * ( max - min ));
}

*/

static int test_double(size_t test_num, long long int max_range)
{
    while (test_num > 0)
    {
        if(double_random_test(80, 80, max_range) == -1)
            return (-1);
        test_num--;
    }
    return (1);
}

static int test_int(size_t test_num)
{
    while (test_num > 0)
    {
        if(int_random_test(80, 80) == -1)
            return (-1);
        test_num--;
    }
    return (1);
}

static int test_uint(size_t test_num)
{
    while (test_num > 0)
    {
        if(uint_random_test(80, 80) == -1)
            return (-1);
        test_num--;
    }
    return (1);
}

static int test_uint_zero(size_t test_num)
{
    while (test_num > 0)
    {
        if(uint_random_test_zero(80, 80) == -1)
            return (-1);
        test_num--;
    }
    return (1);
}

static int test_int_zero(size_t test_num)
{
    while (test_num > 0)
    {
        if(int_random_test_zero(80, 80) == -1)
            return (-1);
        test_num--;
    }
    return (1);
}

static int test_char(size_t test_num, int min, int max)
{
    while (test_num > 0)
    {
        if(char_random_test(80, min, max) == -1)
            return (-1);
        test_num--;
    }
    return (1);
}

static int test_string(size_t test_num, int min, int max)
{
    while (test_num > 0)
    {
        if(string_random_test(100, 100, min, max) == -1)
            return (-1);
        test_num--;
    }
    return (1);
}

static int test_ptr(size_t test_num)
{
    while (test_num > 0)
    {
        if(ptr_random_test(100) == -1)
            return (-1);
        test_num--;
    }
    return (1);
}


int main(void)
{
    srand((unsigned int)time(NULL));

    int test_size;

    test_size = 10000;

    if(test_double(test_size / 10, 1) == - 1)
        return (0);

    if(test_double(test_size / 10, 10) == - 1)
        return (0);

    if(test_double(test_size / 10, 100) == - 1)
        return (0);

    if(test_double(test_size / 10 , 1000) == - 1)
        return (0);

    if(test_double(test_size / 10, 10000) == - 1)
        return (0);

    if(test_double(test_size / 10, 100000) == - 1)
        return (0);

    if(test_double(test_size / 10, 1000000) == - 1)
        return (0);

    if(test_double(test_size / 10, 10000000) == - 1)
        return (0);

    if(test_double(test_size / 10, 100000000) == - 1)
        return (0);

    if(test_double(test_size / 10, 1000000000) == - 1)
        return (0);

    if(test_double(test_size / 10, 10000000000) == - 1)
        return (0);

    if(test_int(test_size) == - 1)
        return (0);

    if(test_uint(test_size * 3) == -1)
        return (0);

    if(test_uint_zero(test_size * 20) == -1)
        return (0);

    if (test_int_zero(test_size * 20) == -1)
        return (0);

    if (test_char(test_size * 20, 1, 127) == -1)
        return (0);

    if (test_string(test_size * 10, 0, 50) == -1)
        return (0);

    if (test_ptr(test_size * 10) == -1)
        return (0);

    /*

    int res;
    int real_res;

    res = ft_printf("%+-#28.48Lf\n", (long double)LLONG_MAX);
    real_res = printf("%+-#28.48Lf\n", (long double)LLONG_MAX);

    if (res != real_res)
        return (0);

    res = ft_printf("%+-#28.48Lf\n", (long double)LLONG_MIN);
    real_res = printf("%+-#28.48Lf\n", (long double)LLONG_MIN);

    if (res != real_res)
        return (0);

    res = ft_printf("%+-#28.48Lf\n", (long double)ULLONG_MAX);
    real_res = printf("%+-#28.48Lf\n", (long double)ULLONG_MAX);

    if (res != real_res)
        return (0);

    res = ft_printf("%+-#28.48Lf\n", ((long double)ULLONG_MAX * -1));
    real_res = printf("%+-#28.48Lf\n", ((long double)ULLONG_MAX * -1));

    if (res != real_res)
        return (0);

    long double test;
    long double min;
    long double max;
    
    test = 0;
    min = -1;
    max = 1;
    res = 0;
    real_res = 0;
    while (res == real_res && min > ((long double)ULLONG_MAX * -1) && max < (long double)ULLONG_MAX)
    {
        test = ldouble_rand(min, max);
        res = ft_printf("%+-#28.48Lf\n", test);
        real_res = printf("%+-#28.48Lf\n", test);
        min = min * 1.01;
        max = max * 1.01;
    }

    max = 1;
    min = -1;
    int count;
    count = 100000;

    while (res == real_res && count > 0)
    {
        test = ldouble_rand(min, max);
        res = ft_printf("%+#28.15Lf\n", test);
        real_res = printf("%+#28.15Lf\n", test);
        count--;
    }

    while (res == real_res && count < 1000000 && max < ULLONG_MAX)
    {
        test = ldouble_rand(min, max);
        res = ft_printf("%+#28.18Lf\n", test);
        real_res = printf("%+#28.18Lf\n", test);
        min = min * 1.01;
        max = max * 1.01;
        count++;
    }

    min = -10;
    max = 10;

    while (res == real_res && count > 0)
    {
        test = ldouble_rand(min, max);
        res = ft_printf("%+#28.100Lf\n", test);
        real_res = printf("%+#28.100Lf\n", test);
        count--;
    }

    min = min * 10;
    max = max * 10;

    while (res == real_res && count < 1000)
    {
        test = ldouble_rand(min, max);
        res = ft_printf("%+#28.50Lf\n", test);
        real_res = printf("%+#28.50Lf\n", test);
        count++;
    }

    */

    return (0);
}