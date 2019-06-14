
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

/*

static int test_ldouble(size_t test_num, long long int max_range)
{
    while (test_num > 0)
    {
        if(ldouble_random_test(80, 80, max_range) == -1)
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

*/

int main(void)
{
    srand((unsigned int)time(NULL));

    int test_size;

    test_size = 1000;

    if(test_double(test_size, 1) == - 1)
        return (0);

    if(test_double(test_size, 10) == - 1)
        return (0);

    if(test_double(test_size, 100) == - 1)
        return (0);

    if(test_double(test_size, 1000) == - 1)
        return (0);

    if(test_double(test_size, 10000) == - 1)
        return (0);

    if(test_double(test_size, 100000) == - 1)
        return (0);

    if(test_double(test_size, 1000000) == - 1)
        return (0);

    if(test_double(test_size, 10000000) == - 1)
        return (0);

    if(test_double(test_size, 100000000) == - 1)
        return (0);

    if(test_double(test_size, 1000000000) == - 1)
        return (0);

    if(test_double(test_size, 10000000000) == - 1)
        return (0);

/*

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

*/
    int res;
    int real_res;

    long double test;
    
    test = 0.53343453453453455235345345345;

    res = ft_printf("%+-#28.48Lf\n", test);
    real_res = printf("%+-#28.48Lf\n", test);

    return (0);
}