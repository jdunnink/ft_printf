#include <stdio.h>
#include <limits.h>
#include "printf.h"

static int int_rand(int max)
{
  int scale;

  scale = rand() % max;
  return (scale);
}

static intmax_t intmax_rand(intmax_t max)
{
  intmax_t scale;

  scale = rand() % max;
  return (scale);
}

static void *ptr_rand()
{
    void *ptr;

    ptr = (void*)intmax_rand(3498345333225345353);

    return (ptr);
}

static int pointer_printfcmp(const char *format, void *argument)
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
        printf("\ntestvalue --> %p\n", argument);
        printf("    MY PRINTF:      %s", my_print);
        printf("    REAL PRINTF:    %s", real_print);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        return (1);
    }

    if (res != real_res)
    {
        printf("ERROR: return values did not match!\n");
        printf("\ntestvalue --> %p\n", argument);
        printf("    myprintf output --> %i.\n", res);
        printf("    real printf output --> %i.\n", real_res);
        return (1);
    }
    free(my_print);
    free(real_print);
    return (0);
}

static int pointer_test(char *format, size_t testnum)
{
    void *test_ptr;

    while (testnum > 0)
    {
        test_ptr = ptr_rand();
        if (pointer_printfcmp(format, test_ptr) == 1)
            return (-1);
        testnum--;
    }
    return (0);
}

int     ptr_random_test(int max_width)
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
        format = ft_strjoin_free(format, "-", 1);

    if (int_rand(101) >= 50)
        width_on = 1;

    end_type = ft_strdup("p<<\n");

    if (width_on == 1)
    {
        width_int = int_rand(max_width + 1);
        width = ft_itoa_base(width_int, 10);
        format = ft_strjoin_free(format, width, 3);
    }


    format = ft_strjoin_free(format, end_type, 3);
    printf("\ntestformat --> %s\n", format);
    if (pointer_test(format, 10) == -1)
    {
        free(format);
        return (-1); 
    }
    free(format);
    return (0);
}