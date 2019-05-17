
#include "libft.h"

char *ft_ctostr(char c)
{
    char *dest;
    dest = (char *)malloc(sizeof(char) * 2);
    if (!dest)
        return (0);
    dest[0] = c;
    dest[1] = '\0';
    return (dest);
}