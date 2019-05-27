
#include "printf.h"

char *ft_stradd(char *target, char *add)
{
    char *dest;

    if (target == 0)
        return (add);
    dest = ft_strjoin(target, add);
    free(target);
    free(add);
    return (dest);
}