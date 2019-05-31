/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_handle_idu.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:29:31 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:33:39 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	count_digits(char *str)
{
	size_t digits;
	size_t i;

	digits = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= '9' && str[i] >= '0')
			digits++;
		i++;
	}
	return (digits);
}

static	char	*pf_idu_width(char *arg, int pad_size, char *flags, char c)
{
	char	*pad;
	char	*dest;

	pad = pf_add_pad(pad_size, c);
	if (ft_cinstr(flags, '-') == 1)
		dest = ft_strjoin_free(arg, pad, 3);
	else
		dest = ft_strjoin_free(pad, arg, 3);
	return (dest);
}

static	char	*pf_idu_precis(char *arg, int precis, int mode)
{
	int		arg_len;
	int		pad_len;
	char	*padding;
	char	*ptr;
	char	*sign;

	sign = 0;
	if (mode == 2)
		arg_len = count_digits(arg);
	else
		arg_len = ft_strlen(arg);
	if (precis <= arg_len)
		return (arg);
	ptr = arg;
	if (*arg == '-' || *arg == '+')
	{
		ptr++;
		sign = ft_strndup(arg, 1);
	}
	pad_len = precis - arg_len;
	padding = pf_add_pad(pad_len, '0');
	ptr = ft_strjoin(padding, ptr);
	free(arg);
	if (sign != 0)
	{
		arg = ft_strjoin_free(sign, ptr, 3);
		return (arg);
	}
	return (ptr);
}

int				pf_handle_idu(char **tmp, t_spec info, va_list a_list)
{
	if (ft_cinstr("id", info.type) == 1)
		*tmp = pf_toa_sign(va_arg(a_list, intmax_t), 10, info.type_size, 1);
	else if (ft_cinstr("uU", info.type) == 1)
		*tmp = pf_toa_unsign(va_arg(a_list, unsigned long long), 10, info.type_size, 1);
	if (**tmp == '\0')
		*tmp = ft_ctostr('0');
	if (ft_cinstr(info.flags, '+') == 1 && **tmp != '-' && info.type != 'u')
		*tmp = ft_strjoin_free("+", *tmp, 2);
	if (info.prec_on == 1 && info.precis > count_digits(*tmp))
		*tmp = pf_idu_precis(*tmp, info.precis, 2);
	if (info.width_on == 1 && ft_cinstr(info.flags, '0') == 1)
		*tmp = pf_idu_precis(*tmp, info.width, 1);
	if (info.width_on == 1 && ft_cinstr(info.flags, '0') == 0 && info.width > ft_strlen(*tmp))
	{
		if (ft_cinstr(info.flags, ' ') == 1 && ft_cinstr(info.flags, '-') == 1)
			*tmp = pf_idu_width(*tmp, info.width - ft_strlen(*tmp) - 1, info.flags, ' ');
		else
			*tmp = pf_idu_width(*tmp, info.width - ft_strlen(*tmp), info.flags, ' ');
	}
	if (ft_cinstr(info.flags, ' ') == 1 && **tmp != ' ' && **tmp != '-')
	{
		if (count_digits(*tmp) > info.precis && **tmp < '1')
			**tmp = ' ';
		else
			*tmp = ft_strjoin_free(" ", *tmp, 2);
	}
	return (1);
}
