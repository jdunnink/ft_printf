

#include <stdio.h>
#include <time.h>
#include "printf.h"

static float ldouble_rand(long double min, long double max)
{
    long double scale;
    
    scale = rand() / (float) RAND_MAX;
    return (min + scale * ( max - min ));
}

static int int_rand(int max)
{
  int scale;

  scale = rand() % max;
  return (scale);
}

static int ldouble_printfcmp(char *format, long double argument)
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
        printf("\ntestvalue --> %.30Lf\n", argument);
        printf("    MY PRINTF:      %s", my_print);
        printf("    REAL PRINTF:    %s", real_print);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        return (1);
    }

    if (res != real_res)
    {
        printf("ERROR: return values did not match!\n");
        printf("\ntestvalue --> %.30Lf\n", argument);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        printf("    MY PRINTF:      %s", my_print);
        printf("    REAL PRINTF:    %s", real_print);
        return (1);
    }
    free(my_print);
    free(real_print);
    return (0);
}

static int ldouble_test(char *format, long double min, long double max, size_t testnum)
{
    long double test_ldouble;

    while (testnum > 0)
    {
        test_ldouble = ldouble_rand(min, max);
        if (ldouble_printfcmp(format, test_ldouble) == 1)
            return (-1);
        testnum--;
    }
    return (0);
}

int     ldouble_random_test(int max_width, int max_precis, long double max_range)
{
    int prec_on;
    int width_on;
    int width_int;
    int precis_int;
    char *width;
    char *precision;
    char *end_type;
    char *format;
    int res;

    width_on = 0;
    prec_on = 0;

    format = ft_strdup("    >>%");
    if(int_rand(101) >= 20)
        format = ft_strjoin_free(format, " ", 1);
    if(int_rand(101) >= 50)
        format = ft_strjoin_free(format, "0", 1);
    if(int_rand(101) >= 50)
        format = ft_strjoin_free(format, "+", 1);
    if(int_rand(101) >= 50)
        format = ft_strjoin_free(format, "-", 1);
    if(int_rand(101) >= 50)
        format = ft_strjoin_free(format, "#", 1);
    if(int_rand(101) >= 50)
        prec_on = 1;
    if (int_rand(101) >= 50)
        width_on = 1;
    
    end_type = ft_strdup("f<<\n");

    res = int_rand(101);
    if(res <= 10)
        end_type = ft_strjoin_free("l", end_type, 2);
    else if (res <= 90)
        end_type = ft_strjoin_free("L", end_type, 2);

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
    if (ldouble_test(format, int_rand(max_range + 1) * -1, int_rand(max_range + 1), 10) == -1)
    {
        free(format);
        return (-1); 
    }
    free(format);
    return (0);
}