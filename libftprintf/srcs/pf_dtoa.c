/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 07:38:44 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/06/07 09:55:53 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void	round_string(char *ptr, size_t len, int *sig)
{
	if (len == 0 || *ptr == '-')
	{
		*sig = 3;
		return ;
	}
	if (*ptr >= '0' && *ptr < '9')
	{
		*ptr = (*ptr) + 1;
		return ;
	}
	else
	{
		if (*ptr != '.' && *ptr != '-')
			*ptr = '0';
		round_string(ptr - 1, len - 1, sig);
	}
	return ;
}

static void		add_round_digit(char **str)
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

static void		round_f(long double value, char **dest)
{
	int		res;
	char	*tmp;

	printf(" round_f is called with value: %Lf and string: %s\n", value, *dest);

	tmp = ft_str_tail(*dest);
	if (ft_isdigit(*tmp) == 0)
		tmp--;
	res = 0;
	if (value > 0.5 || (value == 0.5 && ft_cinstr("13579", *tmp) == 1))
	{
		round_string(tmp, ft_strlen(*dest), &res);
		if (res == 3)
			add_round_digit(dest);
	}
}

char			*pf_dtoa(long double value, int precision)
{
	char *first;
	int tmp;
	long double back_end;

	if (value < 0)
		value = value * -1;

	/* 

		alternatively, the first part can be derived by moving one digit passed the zero and then cutting off the rest.
		bringing back that digit and then casting yields the last digit of the long double format. so -->
		456.7345345.
		becomes
		45.7345345
		becomes
		0.7345345
		becomes
		7.345345
		becomes
		7

		repeat until the entire string is parsed.

	*/


	back_end = value - (unsigned long long)value;
	first = pf_toa_unsign((unsigned long long) value, 10, 2, 1);
	first = ft_stradd(first, ft_ctostr('.'));
	back_end = back_end * 10;
	while (precision > 0)
	{
		tmp = (int)back_end;
		first = ft_stradd(first, pf_ltoa(tmp));
		back_end = back_end - (int)back_end;
		back_end = back_end * 10;
		precision--;
	}
	round_f(back_end / 10, &first);
	printf(" rounding value based on backend: %Lf\n", back_end / 10);

	return (first);
}
