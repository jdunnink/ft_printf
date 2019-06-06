
#include <stdio.h>
#include <time.h>
#include "printf.h"

int     ldouble_random_test(int max_width, int max_precis, long double max_range);
int     int_random_test(int max_width, int max_precis);
int     uint_random_test(int max_width, int max_precis);
int     uint_random_test_zero(int max_width, int max_precis);
int     int_random_test_zero(int max_width, int max_precis);
int     char_random_test(int max_width, int min, int max);
int     string_random_test(int max_width, int max_precis, int min, int max);
int     ptr_random_test(int max_width);

static int test_ldouble(size_t test_num, int max_range)
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


// tests for percentage sign
// test for regular double (float) --> try L and l flags


int main(void)
{
    srand((unsigned int)time(NULL));
    int test_size;

    test_size = 100;

    if(test_ldouble(test_size, 1) == -1)
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

    return (0);
}