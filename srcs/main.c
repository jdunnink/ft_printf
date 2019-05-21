/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 18:24:54 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/21 18:25:04 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// verify that a correct format specifier is used.
// send the complete valid specifier to the dispatcher
// dispatcher loads tmp string with the requied info.

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
            else if (*format == 'f' || *format == 'F')
                tmp = ft_dtoa((double)va_arg(a_list, double), 6);
            else
            {
                ft_putendl("ERROR: format specifier not recognized");
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
    unsigned int test;

    test = 2342348;
    printf("\n\nreal printf: %u\n", test);
    ft_printf("My printf  : %u\n", test);

    return (0);
}
