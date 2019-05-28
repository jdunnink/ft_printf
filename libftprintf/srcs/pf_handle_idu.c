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

static char     *pf_idu_width(char *arg, int pad_size, char *flags)
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

static char    *pf_idu_precis(char *arg, int precis)
{
    size_t arg_len;
    size_t pad_len;
    char    *padding;
    char    *ptr;
    char    *sign;

    sign = 0;
    arg_len = ft_strlen(arg);
    if (precis <= arg_len)
        return (arg);
    ptr = arg;
    if (*arg == '-' || *arg == '+')
    {
        ptr++;
        sign = ft_strndup(arg, 1);
        arg_len--;
    }
    pad_len = precis - arg_len;
    padding = pf_add_pad(pad_len, '0');
    ptr = ft_strjoin(padding, ptr);
    free(arg);
    if (sign != 0)
    {
        arg = ft_strjoin(sign, ptr);
        free(ptr);
        free(sign);
        return (arg);
    }
    return (ptr);
}

int     pf_handle_idu(char **tmp, t_spec info, va_list a_list)
{
    char *new_tmp;

    if (ft_cinstr("id", info.type) == 1)
        *tmp = pf_toa_sign(va_arg(a_list, long long), 10, info.type_size, 1);
    else if (info.type == 'u')
        *tmp = pf_toa_unsign(va_arg(a_list, long long), 10, info.type_size, 1);
    else    
        return (-1);
    if (ft_cinstr(info.flags, '+') == 1 && **tmp != '-' && info.type != 'u')
    {
        new_tmp = ft_strjoin("+", *tmp);
        free(*tmp);
        *tmp = new_tmp;
    }
    if (info.prec_on == 1)
        *tmp = pf_idu_precis(*tmp, info.precis);
    else if (info.width_on == 1 && ft_cinstr(info.flags, '0') == 1 && info.type != 'u')
        *tmp = pf_idu_precis(*tmp, info.width - 1);
    else if (info.width_on == 1 && ft_cinstr(info.flags, '0') == 1 && info.type == 'u')
        *tmp = pf_idu_precis(*tmp, info.width);
    if (info.width_on == 1 && info.width > ft_strlen(*tmp))
        *tmp = pf_idu_width(*tmp, info.width - ft_strlen(*tmp), info.flags);
    if (ft_cinstr(info.flags, ' ') == 1 && **tmp != ' ')
    {
        new_tmp = ft_strjoin(" ", *tmp);
        free(*tmp);
        *tmp = new_tmp;
        return (0);
    }
    return (1);
}