
#include <stdio.h>
#include <limits.h>
#include "printf.h"

static long long int int_rand(long long int max)
{
  long long int scale;

  scale = rand() % max;
  return (scale);
}

static int int_printfcmp(const char *format, long long int argument)
{
    int res;
    int real_res;

    char *real_print;
    char *my_print;

    res = 0;
    real_res = 0;

    real_res = asprintf(&real_print, format, argument);
    ft_putstr(real_print);
    res = ft_asprintf(&my_print, format, argument);
    ft_putstr(my_print);

    if (ft_strcmp(my_print, real_print) != 0)
    {
        printf("\nERROR:  output strings do not match!\n");
        printf("\ntestvalue --> %lli\n", argument);
        printf("    MY PRINTF:      %s", my_print);
        printf("    REAL PRINTF:    %s", real_print);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        free(my_print);
        free(real_print);
        return (1);
    }

    if (res != real_res)
    {
        printf("ERROR: return values did not match!\n");
        printf("\ntestvalue --> %lli\n", argument);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        free(my_print);
        free(real_print);
        return (1);
    }
    free(my_print);
    free(real_print);
    return (0);
}

static int int_test(char *format, long long int min, long long int max, size_t testnum)
{
    long long int test_int;

    while (testnum > 0)
    {
        if (int_rand(101) >= 50)
            test_int = int_rand(max);
        else
            test_int = (int_rand(min * -1) * -1);
        if (int_printfcmp(format, test_int) == 1)
            return (-1);
        testnum--;
    }
    return (0);
}

int     int_random_test(int max_width, int max_precis)
{
    int prec_on;
    int width_on;
    int width_int;
    int precis_int;
    char *width;
    char *precision;
    char *end_type;
    char *format;
    int random;
    long long range;

    width_on = 0;
    prec_on = 0;

    format = ft_strdup("    >>%");
//    if(int_rand(101) >= 50)
//        format = ft_strjoin_free(format, " ", 1);
    if(int_rand(101) >= 50)
        format = ft_strjoin_free(format, "0", 1);
//    if(int_rand(101) >= 50)
//        format = ft_strjoin_free(format, "+", 1);
    if(int_rand(101) >= 50)
        format = ft_strjoin_free(format, "-", 1);
//    if(int_rand(101) >= 50)
//        format = ft_strjoin_free(format, "#", 1);
    if(int_rand(101) >= 50)
        prec_on = 1;
    if (int_rand(101) >= 50)
        width_on = 1;

    random = int_rand(101);
    if (random <= 50)
        end_type = ft_strdup("i<<\n");
    else
        end_type = ft_strdup("d<<\n");


    range = LLONG_MAX;
/*
    random = int_rand(101);
    if(random <= 20)
    {
        range = CHAR_MAX;
        end_type = ft_strjoin_free("hh", end_type, 2);
    }
    else if(random <= 40)
    {
        range = SHRT_MAX;
        end_type = ft_strjoin_free("h", end_type, 2);
    }
    else if(random <= 60)
    {
        range = LONG_MAX;
        end_type = ft_strjoin_free("l", end_type, 2);
    }
    else if (random <= 80)
    {
        range = LLONG_MAX;
        end_type = ft_strjoin_free("ll", end_type, 2);
    }
*/

    if (width_on == 1)
    {
        width_int = int_rand(max_width + 1);
        width = ft_itoa_base(width_int, 10);
        format = ft_strjoin_free(format, width, 3);
    }
    if (prec_on == 1)
    {
        precis_int = int_rand(max_precis + 1);
        precision = ft_itoa_base(precis_int, 10);
        format = ft_strjoin_free(format, ".", 1);
        format = ft_strjoin_free(format, precision, 3);
    }
    format = ft_strjoin_free(format, end_type, 3);
    printf("\ntestformat --> %s\n", format);
    if (int_test(format, range * - 1, range, 25) == -1)
    {
        free(format);
        return (-1); 
    }
    free(format);
    return (0);
}