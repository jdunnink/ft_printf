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

static void flag_override(t_fspec *format)
{
    char *new_flags;

    if (ft_cinstr(format->flags, '-') == 1 && ft_cinstr(format->flags, '0') == 1)
    {
        new_flags = ft_strdup_exep(format->flags, '0');
        free(format->flags);
        format->flags = new_flags;
    }
    if (ft_cinstr(format->flags, ' ') == 1 && ft_cinstr(format->flags, '+') == 1)
    {
        new_flags = ft_strdup_exep(format->flags, ' ');
        free(format->flags);
        format->flags = new_flags;
    }
}

static void    pad_field_width(char **field, t_fspec inf)
{
    char *pad_field;
    char *new_field;
    int     pad_len;

    pad_len = 0;
    pad_field = NULL;
    pad_len = inf.width - ft_strlen(*field);
    while (pad_len > 0)
    {
        if (pad_field == NULL)
            pad_field = ft_ctostr('0');
        else
            pad_field = ft_strjoin("0", pad_field);
        pad_len--;
    }
    if (ft_cinstr(inf.flags, '0') == 0)
        ft_memset(pad_field, ' ', ft_strlen(pad_field));
    if (ft_cinstr(inf.flags, '-') == 1)
        *field = ft_strjoin(*field, pad_field);
    else if (((*field[0] == '-') || (*field[0] == '+')) && ft_cinstr(inf.flags, '0') == 1)
    {
        new_field = ft_ctostr(*field[0]);
        new_field = ft_strjoin(new_field, pad_field);
        new_field = ft_strjoin(new_field, (*field)+ 1);
        *field = new_field;
    }
    else
        *field = ft_strjoin(pad_field, *field);
}

static t_fspec get_formatspec(char **format)
{
    char    *spec;
    char    *precision;
    char    *width;
    size_t  len;
    t_fspec *inf;

    spec = *format;
    len = 1;
    spec++;
    inf = (t_fspec*)malloc(sizeof(t_fspec));
    width = 0;
    precision = 0;
    inf->flags = 0;
    inf->width = 0;
    inf->precis = 0;
    inf->width = 0;
    inf->width_on = 0;
    inf->prec_on = 0;
    while (*spec != '\0')
    {
        if (ft_cinstr("#-+0 cspdiouXxfF123456789.", *spec) == 0)
            break;
        if (*spec == '.')
            inf->prec_on = 1;
        if (ft_cinstr("123456789", *spec) == 1 && inf->prec_on == 0)
            inf->width_on = 1;
        if (ft_cinstr("%cspdiouXxfF", *spec) == 1)
        {
            inf->format = *spec;
            inf->len = len;
            if (inf->prec_on == 1 && precision != 0)
            {
                inf->precis = ft_atol(precision);
                free(precision);
            }
            if (inf->width_on == 1 && width != 0)
            {
                inf->width = ft_atol(width);
                free(width);
            }
            if(inf->flags != 0)
                flag_override(inf);
            return (*inf);
        }
        if (ft_cinstr("#-+0 ", *spec) == 1 && inf->width_on == 0 && inf->prec_on == 0)
        {
            if (inf->flags == NULL)
                inf->flags = ft_ctostr(*spec);
            else
            {
                if (ft_cinstr(inf->flags, *spec) == 0)
                    inf->flags = ft_strjoin(inf->flags, ft_ctostr(*spec));
            }
        }
        if (inf->prec_on == 1 && ft_cinstr("0123456789", *spec) == 1)
        {
            if (precision == NULL)
                precision = ft_ctostr(*spec);
            else
                precision = ft_strjoin(precision, ft_ctostr(*spec));
        }
        if (inf->prec_on == 0 && ft_cinstr("0123456789", *spec) == 1 && inf->width_on == 1)
        {
            if (width == NULL)
                width = ft_ctostr(*spec);
            else
                width = ft_strjoin(width, ft_ctostr(*spec));
        }
        len++;
        spec++;
    }
    inf->len = 1;
    inf->format = 0;
    return (*inf);
}

static int format_disp(char **tmp, t_fspec inf, va_list a_list)
{
    char type;

    type = inf.format;
    if (type == 'c')
        *tmp = ft_ctostr((char)va_arg(a_list, int));
    else if (type == 's')
        *tmp = ft_strdup((char *)va_arg(a_list, char *));
    else if (type == 'i' || type == 'd')
    {
        *tmp = ft_itoa_base((int)va_arg(a_list, int), 10);
        if (ft_cinstr(inf.flags, '+') == 1 && **tmp != '-')
            *tmp = ft_strjoin("+", *tmp);
    }
    else if (type == 'u')
        *tmp = ft_uitoa((unsigned int)va_arg(a_list, unsigned int));
    else if (type == '%')
        *tmp = ft_ctostr(type);
    else if (type == 'p')
        *tmp = ft_strjoin("0x7fff", ft_itoa_base(va_arg(a_list, int), 16));
    else if (type == 'x')
    {
        *tmp = ft_itoa_base(va_arg(a_list, int), 16);
        if (**tmp != '0' && ft_cinstr(inf.flags, '#') == 1)
            *tmp = ft_strjoin("0x", *tmp);
    }
    else if (type == 'X')
    {
        *tmp = ft_itoa_base_uc(va_arg(a_list, int), 16);
        if (**tmp != '0' && ft_cinstr(inf.flags, '#') == 1)
            *tmp = ft_strjoin("0X", *tmp);
    }
    else if (type == 'o')
    {
        if (ft_cinstr(inf.flags, '#') == 1)
            *tmp = ft_strjoin("0", ft_itoa_base(va_arg(a_list, int), 8));
        else
            *tmp = ft_itoa_base(va_arg(a_list, int), 8);
    }
    else if (type == 'f' || type == 'F')
    {
        if (inf.prec_on == 0 && inf.precis == 0)
            inf.precis = 6;
        *tmp = ft_dtoa((double)va_arg(a_list, double), inf.precis);
        if (ft_cinstr(inf.flags, '+') == 1 && **tmp != '-')
            *tmp = ft_strjoin("+", *tmp);
        if (inf.prec_on == 1 && inf.precis == 0)
            *tmp = ft_strdup_until(*tmp, '.');
    }
    else
        return (-1);
    if (inf.width_on == 1 && ft_cinstr("di", inf.format) == 1)
        pad_field_width(tmp, inf);
    return (1);
}

int ft_printf(const char * restrict format, ...)
{
    va_list a_list;
    char *tmp;
    char *dest;
    t_fspec inf;

    dest = (char*)malloc(sizeof(char) * 1);
    dest[0] = '\0';
    va_start (a_list, format);
    while (*format != '\0')
    {
        if (*format == '%')
        {
            inf = get_formatspec((char**)&format);
            if (inf.format == 0)
                return (2);
            if(format_disp(&tmp, inf, a_list) == -1)
                    return (1);
            format = format + (inf.len);
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