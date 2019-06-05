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

static	char	*pf_idu_precis(char *arg, int pad_size, char c)
{
	char	*pad;
	char	*dest;

	pad = pf_add_pad(pad_size, c);
	dest = ft_strjoin_free(pad, arg, 3);
	return (dest);
}

static	char	*pf_idu_width(char *arg, int pad_size, t_spec info)
{
	char	*pad;
	char	*dest;
	char	c;

	c = ' ';
	if (ft_cinstr(info.flags, '0') == 1 && info.prec_on == 0)
		c = '0';
	pad = pf_add_pad(pad_size, c);
	if (ft_cinstr(info.flags, '-') == 1)
		dest = ft_strjoin_free(arg, pad, 3);
	else
		dest = ft_strjoin_free(pad, arg, 3);
	return (dest);
}

static void		swap_signs(char *str)
{
	char tmp;
	char *iter;
	char *eval;
	eval = str;
	while (*str == ' ')
		str++;
	iter = str + 1;
	while (*iter != '\0' && *iter != '.' && ft_cinstr(" 0-+", *iter) == 1)
	{
		if (*iter == '-' || *iter == '+')
		{
			tmp = *iter;
			*iter = *str;
			*str = tmp;
		}
		iter++;
	}
}

static size_t		count_digits(char *str)
{
	size_t count;

	count = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			count++;
		str++;
	}
	return (count);
}

static void	move_space(char *str)
{
	int digits;
	char tmp;
	char *swap;

	swap = str;
	digits  = count_digits(str);
	if (*str == ' ')
		return ;
	while (*str != '\0' && digits > 0)
	{
		if (*str == ' ')
		{
			tmp = *str;
			*str = *swap;
			*swap = tmp;
		}
		str++;
		digits--;
	}
}		

int				pf_handle_idu(char **tmp, t_spec info, va_list a_list)
{
	size_t res;

	if (ft_cinstr("id", info.type) == 1)
		*tmp = pf_toa_sign(va_arg(a_list, intmax_t), 10, info.type_size, 1);
	else if (ft_cinstr("uU", info.type) == 1)
		*tmp = pf_toa_unsign(va_arg(a_list, unsigned long long), 10, info.type_size, 1);
	if (**tmp == '\0' && info.prec_on == 0)
		*tmp = ft_ctostr('0');
	if (info.prec_on == 1 && info.precis == 0 && **tmp == '0')
		*tmp = ft_ctostr('\0');
	if (ft_cinstr(info.flags, '+') == 1 && **tmp != '-' && ft_cinstr("Uu", info.type) == 0)
		*tmp = ft_strjoin_free("+", *tmp, 2);
	res = count_digits(*tmp);
	if (info.prec_on == 1 && info.precis > res)
		*tmp = pf_idu_precis(*tmp, info.precis - res, '0');
	if (ft_cinstr(info.flags, ' ') && ft_cinstr(*tmp, '-') == 0 && ft_cinstr("Uu", info.type) == 0)
		*tmp = ft_strjoin_free(" ", *tmp, 2);
	res = ft_strlen(*tmp);
	if (info.width_on == 1 && info.width > res)
		*tmp = pf_idu_width(*tmp, info.width - res, info);
	swap_signs(*tmp);
	if (ft_cinstr(info.flags, ' ') == 1)
		move_space(*tmp);
	return (1);
}
