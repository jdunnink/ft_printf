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

static  char *add_prefix(char *arg, char type)
{
    char *prefix;
    char *dest;

    if (type == 'X')
        prefix = ft_strdup("0X");
    else
        prefix = ft_strdup("0x");
    dest = ft_strjoin(prefix, arg);
    free(arg);
    free(prefix);
    return (dest);
}

static char     *pf_xX_width(char *arg, int pad_size, char *flags)
{
    char    *pad;
    char    *dest;

    pad = pf_add_pad(pad_size, ' ');
    if (ft_cinstr(flags, '-') == 1)
        dest = ft_strjoin(arg, pad);
    else
        dest = ft_strjoin(pad, arg);
    free(pad);
    free(arg);
    return (dest);
}

static char    *pf_xX_precis(char *arg, int precis)
{
    size_t arg_len;
    size_t pad_len;
    char    *padding;
    char    *dest;

    arg_len = ft_strlen(arg);
    if (precis <= arg_len)
        return (arg);
    pad_len = precis - arg_len;
    padding = pf_add_pad(pad_len, '0');
    dest = ft_strjoin(padding, arg);
    free(arg);
    return (dest);
}

int     pf_handle_xX(char **tmp, t_spec info, va_list a_list)
{
    if (info.type == 'x')
        *tmp = pf_toa_unsign((unsigned long long)va_arg(a_list, unsigned long long), 16, info.type_size, 1);
    else if (info.type == 'X')
        *tmp = pf_toa_unsign((unsigned long long)va_arg(a_list, unsigned long long), 16, info.type_size, 2);
    else
        return (-1);
    if (info.prec_on == 1)
        *tmp = pf_xX_precis(*tmp, info.precis);
    else if (info.width_on == 1 && ft_cinstr(info.flags, '0') == 1)
        *tmp = pf_xX_precis(*tmp, info.width);
    if (ft_cinstr(info.flags, '#') == 1)
        *tmp = add_prefix(*tmp, info.type);
    if (info.width_on == 1 && info.width > ft_strlen(*tmp))
        *tmp = pf_xX_width(*tmp, info.width - ft_strlen(*tmp), info.flags);
    return (1);
}