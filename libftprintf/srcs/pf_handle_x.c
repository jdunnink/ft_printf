/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_handle_xX.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:39:27 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:39:29 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int		check_for_zero(char *arg)
{
	while (*arg != '\0')
	{
		if (*arg != '0')
			return (0);
		arg++;
	}
	return (1);
}

static	char	*add_prefix(char *arg, char type)
{
	char *prefix;
	char *dest;

	if(check_for_zero(arg) == 1)
		return (arg);
	if (type == 'X')
		prefix = ft_strdup("0X");
	else
		prefix = ft_strdup("0x");
	dest = ft_strjoin_free(prefix, arg, 3);
	return (dest);
}

static	char	*pf_x_width(char *arg, int pad_size, char *flags)
{
	char	*pad;
	char	*dest;

	pad = pf_add_pad(pad_size, ' ');
	if (ft_cinstr(flags, '-') == 1)
		dest = ft_strjoin_free(arg, pad, 3);
	else
		dest = ft_strjoin_free(pad, arg, 3);
	return (dest);
}

static	char	*pf_x_precis(char *arg, int precis)
{
	int		arg_len;
	int		pad_len;
	char	*padding;
	char	*dest;

	arg_len = ft_strlen(arg);
	if (precis <= arg_len)
		return (arg);
	pad_len = precis - arg_len;
	padding = pf_add_pad(pad_len, '0');
	dest = ft_strjoin_free(padding, arg, 3);
	return (dest);
}

int				pf_handle_x(char **tmp, t_spec info, va_list a_list)
{
	unsigned long long res;

	res = (unsigned long long)va_arg(a_list, unsigned long long);
	if (res == 0)
		*tmp = ft_ctostr('0');
	else if (info.type == 'x')
		*tmp = pf_toa_unsign(res, 16, info.type_size, 1);
	else if (info.type == 'X')
		*tmp = pf_toa_unsign(res, 16, info.type_size, 2);
	if (info.prec_on == 1)
		*tmp = pf_x_precis(*tmp, info.precis);
	if (info.prec_on == 1 && info.precis == 0 && **tmp == '0')
		*tmp = ft_strdup_exep(*tmp, '0');
	else if (info.width_on == 1 && ft_cinstr(info.flags, '0') == 1 && info.prec_on == 0)
	{
		if (ft_cinstr(info.flags, '#') == 1 && check_for_zero(*tmp) == 0)
			*tmp = pf_x_precis(*tmp, info.width - 2);
		else
			*tmp = pf_x_precis(*tmp, info.width);
	}
	if (ft_cinstr(info.flags, '#') == 1 && res != 0)
		*tmp = add_prefix(*tmp, info.type);
	if (info.width_on == 1 && info.width > ft_strlen(*tmp))
		*tmp = pf_x_width(*tmp, info.width - ft_strlen(*tmp), info.flags);
	return (1);
}
