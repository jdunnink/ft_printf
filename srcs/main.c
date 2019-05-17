
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
    printf("\nThe starting format string: \n");
    ft_putendl(format);

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
            else if (*format == '%')
                tmp = ft_ctostr(*format);
            else if (*format == 'p')
                tmp = ft_strjoin("0x7fff", ft_itoa_base(va_arg(a_list, int), 16));
            else if (*format == 'o')
                tmp = ft_itoa_base(va_arg(a_list, int), 8);
        }
        else
            tmp = ft_strndup((char*)format, 1);
        dest = ft_strjoin(dest, tmp);
        free(tmp);
        format++;
    }
    printf("\nEnd result: \n");
    ft_putendl(dest);
    free(dest);
    va_end (a_list);
    return (0);
}

int main(void)
{
    int octal = 10;
    ft_printf("This is a test: %p\n", &octal);
    return (0);
}