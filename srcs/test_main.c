
#include <stdio.h>
#include <time.h>
#include "printf.h"



int     float_random_test(int max_width, int max_precis, int max_range);
int     int_random_test(int max_width, int max_precis, int max_range);

static void test_float(size_t test_num)
{
    while (test_num > 0)
    {
        if(float_random_test(50, 50, 10) == -1)
            return ;
        test_num--;
    }
}

static void test_int(size_t test_num)
{
    while (test_num > 0)
    {
        if(int_random_test(30, 30, 10) == -1)
            return ;
        test_num--;
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));

    test_int(500);
    test_float(500);
    return (0);
}