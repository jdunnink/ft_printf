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

static int char_printfcmp(const char *format, char argument)
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
        printf("\ntestvalue --> %i\n", (int)argument);
        printf("    MY PRINTF:      %s", my_print);
        printf("    REAL PRINTF:    %s", real_print);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        return (1);
    }

    if (res != real_res)
    {
        printf("ERROR: return values did not match!\n");
        printf("\ntestvalue --> %i\n", (int)argument);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        return (1);
    }
    free(my_print);
    free(real_print);
    return (0);
}

static int char_test(char *format, int min, int max, size_t testnum)
{
    char test_char;

    while (testnum > 0)
    {
        test_char = char_rand(min, max);
        if (char_printfcmp(format, test_char) == 1)
            return (-1);
        testnum--;
    }
    return (0);
}

int     char_random_test(int max_width, int min, int max)
{
    int width_on;
    int width_int;

    char *width;
    char *end_type;
    char *format;

    width_on = 0;

    format = ft_strdup("    >>%");
    if(int_rand(101) >= 50)
        format = ft_strjoin_free(format, " ", 1);
    if(int_rand(101) >= 50)
        format = ft_strjoin_free(format, "+", 1);
    if(int_rand(101) >= 50)
        format = ft_strjoin_free(format, "-", 1);

    if (int_rand(101) >= 50)
        width_on = 1;

    end_type = ft_strdup("c<<\n");

    if (width_on == 1)
    {
        width_int = int_rand(max_width + 1);
        width = ft_itoa_base(width_int, 10);
        format = ft_strjoin_free(format, width, 3);
    }

    format = ft_strjoin_free(format, end_type, 3);
    printf("\ntestformat --> %s\n", format);
    if (char_test(format, min, max, 10) == -1)
    {
        free(format);
        return (-1);
    }
    free(format);
    return (0);
}