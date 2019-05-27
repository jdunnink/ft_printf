
#include "printf.h"

int ft_cinstr(const char *str, char c)
{
    size_t i;

    if (!str)
        return (0);
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}