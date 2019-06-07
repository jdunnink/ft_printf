
#include "printf.h"

int     ft_printf(const char *format, ...)
{
    char    *dest;
    int     len;
    va_list a_list;

    va_start(a_list, format);
    len = ft_vasprintf(&dest, format, a_list);
    va_end(a_list);
    return (len);
}