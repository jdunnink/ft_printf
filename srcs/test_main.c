
#include <stdio.h>
#include <time.h>
#include "printf.h"

int     float_random_test(int max_width, int max_precis, float max_range);
int     int_random_test(int max_width, int max_precis);
int     uint_random_test(int max_width, int max_precis);


static void test_float(size_t test_num, float max_range)
{
    while (test_num > 0)
    {
        if(float_random_test(80, 80, max_range) == -1)
            return ;
        test_num--;
    }
}


static void test_int(size_t test_num)
{
    while (test_num > 0)
    {
        if(int_random_test(80, 80) == -1)
            return ;
        test_num--;
    }
}


static void test_uint(size_t test_num)
{
    while (test_num > 0)
    {
        if(uint_random_test(80, 80) == -1)
            return ;
        test_num--;
    }
}


int main(void)
{
    srand((unsigned int)time(NULL));

    test_float(500, 0);
    test_int(500);
    test_uint(500);
    return (0);
}