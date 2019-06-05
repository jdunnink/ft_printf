

#include <stdio.h>
#include <time.h>
#include "printf.h"

static float float_rand(float min, float max)
{
    float scale;
    
    scale = rand() / (float) RAND_MAX;
    return (min + scale * ( max - min ));
}

static int int_rand(int max)
{
  int scale;

  scale = rand() % max;
  return (scale);
}

static int float_printfcmp(char *format, float argument)
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
        printf("\ntestvalue --> %.30f\n", argument);
        printf("    MY PRINTF:      %s", my_print);
        printf("    REAL PRINTF:    %s", real_print);
        return (1);
    }

    if (res != real_res)
    {
        printf("ERROR: return values did not match!\n");
        printf("\ntestvalue --> %.30f\n", argument);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        return (1);
    }
    free(my_print);
    free(real_print);
    return (0);
}

static int float_test(char *format, float min, float max, size_t testnum)
{
    double test_float;

    while (testnum > 0)
    {
        test_float = float_rand(min, max);
        if (float_printfcmp(format, test_float) == 1)
            return (-1);
        testnum--;
    }
    return (0);
}

int     float_random_test(int max_width, int max_precis, int max_range)
{
    int prec_on;
    int width_on;
    int width_int;
    int precis_int;
    char *width;
    char *precision;
    char *end_type;
    char *format;

    width_on = 0;
    prec_on = 0;

    format = ft_strdup("    ||%");
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
    end_type = ft_strdup("f||\n");
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
    format = ft_strjoin(format, end_type);
    printf("\ntestformat --> %s\n", format);
    if (float_test(format, int_rand(max_range + 1) * -1, int_rand(max_range + 1), 25) == -1)
        return (-1); 
    return (0);
}