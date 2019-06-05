/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 07:38:44 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:05:01 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


static int		find_round(long double value)
{
	long long int	tmp;
	size_t			count;

	tmp = 0;
	count = 0;
	while (count <= 10)
	{
		value = value * 10;
		tmp = tmp * 10;
		tmp += (long long)value;
		value -= (long long)value;
		if (tmp == 0)
			return (0);
		count++;
	}
	if (tmp % 10 >= 5)
		tmp = tmp + (10 - (tmp % 10));
	while (tmp > 999999)
	{
		tmp = tmp / 10;
		count--;
	}
	if (tmp == 500000)
		return (2);
	else if (tmp >= 500000)
		return (1);
	return (0);
}

static void roundstr_recurs(char *ptr, size_t len, int *sig)
{
	if (len == 0 || *ptr == '-')
	{
		*sig = 3;
		return ;
	}
	if (*ptr < '9' && *ptr >= '0')
	{
		*ptr = (*ptr) + 1;
		return ;
	}
	else
	{
		if (*ptr != '.' && *ptr != '-')
			*ptr = '0';
		roundstr_recurs(ptr - 1, len - 1, sig);
	}
	return ;
}
static char *find_last_char(char *str)
{
	while (*(str + 1) != '\0')
		str++;
	return (str);
}

static void	add_round_digit(char **str)
{
	char *tmp;

	tmp = *str;
	if (**str != '-')
		*str = ft_strjoin_free("1", *str, 2);
	else
	{
		tmp = ft_strdup(tmp + 1);	
		free(*str);
		*str = ft_strjoin_free("-1", tmp, 2);
	}
}

char	*pf_dtoa(long double value, int precision)
{
	char	*dest;
	char	*sign;
	char	*tmp;
	int res;

	sign = 0;
	tmp = 0;
	if (value < 0 && value > -1)
		sign = ft_strdup("-");
	tmp = pf_ltoa((long)value);
	dest = ft_strjoin_free(tmp, ".", 1);
	value = value - (long)value;
	if (value < 0)
		value = value * -1;
	while (precision > 0)
	{
		precision--;
		value = value * 10;
		tmp = pf_ltoa((long)value);
		dest = ft_strjoin_free(dest, tmp, 3);
		value -= (long)value;
	}
	res = find_round(value);
	tmp = find_last_char(dest);
	if (res == 1 || (res == 2 && ft_cinstr("7", *tmp) == 1))
	{
		roundstr_recurs(tmp, ft_strlen(dest), &res);
		if (res == 3)
			add_round_digit(&dest);
	}
	res = find_round(value);
	tmp--;
	if (*(tmp + 1) == '.' && ft_cinstr("13579", *tmp) == 1 && res == 2)
	{
		roundstr_recurs(tmp, ft_strlen(dest), &res);
		if (res == 3)
			add_round_digit(&dest);
	}
	if (sign != 0)
		dest = ft_strjoin_free(sign, dest, 3);
	return (dest);
}
