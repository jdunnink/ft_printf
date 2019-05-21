
// %c	character
// %s	a string of characters
// %p   pointer adress

// %d	decimal (integer) number (base 10)
// %e	exponential floating-point number
// %f	floating-point number
// %i	integer (base 10)
// %o	octal number (base 8)
// %u	unsigned decimal (integer) number
// %x	number in hexadecimal (base 16)
// %%	print a percent sign
// \%	print a percent sign

#include "printf.h"

int ft_printf(const char * restrict format, ...)
{
    va_list a_list;
    char *tmp;
    char *dest;

    dest = (char*)malloc(sizeof(char) * 1);
    dest[0] = '\0';
    va_start (a_list, format);
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')   
                tmp = ft_ctostr((char)va_arg(a_list, int));
            else if (*format == 's')
                tmp = ft_strdup((char *)va_arg(a_list, char *));
            else if (*format == 'i' || *format == 'd')
                tmp = ft_itoa_base((int)va_arg(a_list, int), 10);
            else if (*format == 'u')
                tmp = ft_uitoa((unsigned int)va_arg(a_list, unsigned int));
            else if (*format == '%')
                tmp = ft_ctostr(*format);
            else if (*format == 'p')
                tmp = ft_strjoin("0x7fff", ft_itoa_base(va_arg(a_list, int), 16));
            else if (*format == 'x')
                tmp = ft_itoa_base(va_arg(a_list, int), 16);
            else if (*format == 'X')
                tmp = ft_itoa_base_uc(va_arg(a_list, int), 16);
            else if (*format == 'o')
                tmp = ft_itoa_base(va_arg(a_list, int), 8);
            else
            {
                ft_putendl("ERROR: format specifier not renognized");
                return (-1);
            }
        }
        else
            tmp = ft_strndup((char*)format, 1);
        dest = ft_strjoin(dest, tmp);
        free(tmp);
        format++;
    }
    ft_putstr(dest);
    free(dest);
    va_end (a_list);
    return (0);
}

int main(void)
{
    int test = 2334;
    ft_printf("\nMy printf  : %p\n", &test);
    printf("Real printf: %p\n\n", &test);
    return (0);
}