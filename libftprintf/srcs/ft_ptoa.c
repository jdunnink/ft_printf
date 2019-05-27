
#include "printf.h"

static int  find_size(unsigned long long n, int base)
{
    int count;

    count = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        count++;
        n /= base;
    }
    return (count);
}

char    *ft_ptoa(void *pointer, int base)
{
    char                *dest;
    unsigned long long  n;
    int                 i;

    n = (unsigned long long)pointer;
    i = find_size(n, base);
    dest = (char *)malloc(sizeof(char) * i + 1);
    if (!dest)
        return (0);
    if (pointer == 0)
        dest[0] = '0';
    while (n)
    {
        i--;
        if (n % base > 9)
            dest[i] = n % base - 10 + 'a';
        else
            dest[i] = n % base + '0';
        n /= base;
    }
    return (dest);
}