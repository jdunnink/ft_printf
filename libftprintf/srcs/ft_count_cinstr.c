
#include "printf.h"

int     ft_count_cinstr(char *str, char c)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (*str != '\0')
    {
        if (*str == c)
            i++;
        str++;
    }
    return (i);
}