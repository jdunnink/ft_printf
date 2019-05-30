/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_handle_fF.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:19:35 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:26:30 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	char	*pf_f_width(char *arg, int pad_size, char *flags, char c)
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

static	char	*pf_f_width_sign(char *arg, int pad_size, char *flags, char c)
{
	char	*pad;
	char	*dest;
	char	*sign;
	char	*tmp;

	sign = 0;
	if (*arg == '-' || *arg == '+')
	{
		tmp = arg + 1;
		sign = ft_ctostr(*arg);
	}
	else
		tmp = arg;
	pad = pf_add_pad(pad_size, c);
	if (ft_cinstr(flags, '-') == 1)
		dest = ft_strjoin(tmp, pad);
	else
		dest = ft_strjoin(pad, tmp);
	free(pad);
	free(arg);
	if (sign != 0)
	{
		arg = ft_strjoin_free(sign, dest, 3);
		return (arg);
	}
	return (dest);
}

static	char	*add_dot(char *arg)
{
	char	*ptr;

	ptr = arg;
	while (ft_cinstr("-+0123456789", *ptr) == 1)
		ptr++;
	if (*ptr == '\0')
	{
		ptr = ft_strjoin_free(arg, ".", 1);
		return (ptr);
	}
	if (*ptr == ' ')
	{
		*ptr = '.';
		return (arg);
	}
	return (arg);
}

int				pf_handle_f(char **tmp, t_spec info, va_list a_list)
{
	if (info.precis == 0 && info.prec_on == 1)
		info.precis = 0;
	else if (info.precis == 0 && info.prec_on == 0)
		info.precis = 6;
	if ((info.type == 'f' || info.type == 'F') && info.type_size == 2)
		*tmp = pf_dtoa(va_arg(a_list, long double), info.precis);
	else if (info.type == 'f' || info.type == 'F')
		*tmp = pf_dtoa(va_arg(a_list, double), info.precis);
	if (info.prec_on == 1 && info.precis == 0)
		*tmp = ft_strdup_until(*tmp, '.');
	if (ft_cinstr(info.flags, '+') && **tmp != '-')
		*tmp = ft_strjoin_free("+", *tmp, 2);
	if (ft_cinstr(*tmp, '.') == 0 && ft_cinstr(info.flags, '#') == 1)
		*tmp = add_dot(*tmp);
	if (ft_cinstr(info.flags, ' ') == 1)
		*tmp = ft_strjoin_free(" ", *tmp, 2);
	if (info.width_on == 1 && info.width > ft_strlen(*tmp) && ft_cinstr(info.flags, '0') == 0)
		*tmp = pf_f_width(*tmp, info.width - ft_strlen(*tmp), info.flags, ' ');
	else if (info.width_on == 1 && info.width > ft_strlen(*tmp) && ft_cinstr(info.flags, '0') == 1)
		*tmp = pf_f_width_sign(*tmp, info.width - ft_strlen(*tmp), info.flags, '0');
	return (1);
}
