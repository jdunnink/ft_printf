#include <stdio.h>
#include <limits.h>
#include "printf.h"

static int int_rand(int max)
{
  int scale;

  scale = rand() % max;
  return (scale);
}

static int int_rand_range(int min, int max)
{
    int num;

    num = rand() % (max + 1 - min) + min;
    return (num);
}

static int char_rand(int min, int max)
{
    char scale;

    scale = int_rand_range(min, max);
    return (scale);
}

static char *string_rand(int min, int max)
{
    char *string;
    int len;
    int i;

    len = int_rand_range(min, max);
    string = ft_strnew(len);
    i = 0;
    while (i < len)
    {
        string[i] = char_rand(33, 127);
        i++;
    }
    return (string);
}


static int string_printfcmp(const char *format, char *argument)
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
        printf("\ntestvalue --> %s\n", argument);
        printf("    MY PRINTF:      %s", my_print);
        printf("    REAL PRINTF:    %s", real_print);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        return (1);
    }

    if (res != real_res)
    {
        printf("ERROR: return values did not match!\n");
        printf("\ntestvalue --> %s\n", argument);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        return (1);
    }
    free(my_print);
    free(real_print);
    return (0);
}

static int string_test(char *format, int min, int max, size_t testnum)
{
    char *test_string;

    while (testnum > 0)
    {
        test_string = string_rand(min, max);
        if (string_printfcmp(format, test_string) == 1)
            return (-1);
        free(test_string);
        testnum--;
    }
    return (0);
}

int     string_random_test(int max_width, int max_precis, int min, int max)
{
    int width_on;
    int width_int;

    char *width;
    char *precision;
    int precis_int;
    int prec_on;
    char *end_type;
    char *format;

    width_on = 0;
    prec_on = 0;

    format = ft_strdup("    >>%");
//    if(int_rand(101) >= 50)
//        format = ft_strjoin_free(format, " ", 1);
//    if(int_rand(101) >= 50)
//        format = ft_strjoin_free(format, "+", 1);
    if(int_rand(101) >= 50)
        format = ft_strjoin_free(format, "-", 1);

    if (int_rand(101) >= 50)
        width_on = 1;
    if (int_rand(101) >= 50)
        prec_on = 1;

    end_type = ft_strdup("s<<\n");

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
    if (string_test(format, min, max, 10) == -1)
    {
        free(format);
        return (-1); 
    }
    free(format);
    return (0);
}