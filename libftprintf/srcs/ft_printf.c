/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 07:38:44 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/27 07:38:45 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int     pf_handle_idu(char **tmp, t_spec info, va_list a_list)
{
    if (ft_cinstr("id", info.type) == 1)
        *tmp = pf_idtoa((long long)va_arg(a_list, long long), info.type_size);
    else if (ft_cinstr("u", info.type) == 1)
        *tmp = pf_utoa((unsigned long long)va_arg(a_list, unsigned long long), info.type_size);
    else    
        return (-1);
    return (1);
}

static int pf_dispatch(char **tmp, t_spec info, va_list a_list)
{
    printf("pf_dispatch is called\n");

    if (ft_cinstr("%csp", info.type) == 1)
        return (pf_handle_csp(tmp, info, a_list));
    else if (ft_cinstr("idu", info.type) == 1)
        return (pf_handle_idu(tmp, info, a_list));
    printf("    format type is not currently supported.\n");
    return (0);
}

int ft_printf(const char * restrict format, ...)
{
    va_list a_list;
    char *tmp;
    char *dest;
    t_spec info;

    printf("\n\nstart function --> printf is called\n");

    dest = 0;
    tmp = 0;
    va_start (a_list, format);
    while (*format != '\0')
    {
        if (*format == '%')
        {
            info = pf_get_specinfo((char*)format);
            pf_flag_override(&info);
            printf("\nget formetspec DONE:\n");    
            if(info.width_on == 1)
                printf("    field width is enabled\n");
            if(info.prec_on == 1)
                printf("    precision is enabled\n");
            printf("    applicable flags: %s\n", info.flags);
            printf("    argument type: %c\n", info.type);
            printf("    argument type_size: %i\n", info.type_size);
            printf("    spec length: %lu\n", info.spec_len);
            printf("    precision: %u\n", info.precis);
            printf("    field width: %u\n\n", info.width);
            if (pf_dispatch(&tmp, info, a_list) != 1)
                return (0);
            format = format + (info.spec_len);
            printf("formatting was completed successfully -> the argument: %s\n\n\n", tmp);
        }
        else
            tmp = ft_ctostr(*format);
        dest = ft_stradd(dest, tmp);
        format++;
    }
    va_end(a_list);
    ft_putstr(dest);
    return (ft_strlen(dest));
}


