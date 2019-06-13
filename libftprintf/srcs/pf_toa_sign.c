/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_toa_sign.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:42:51 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/06/07 10:10:17 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	long long	ft_maxabs(long long nb)
{
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

static int			adjust_typesize(long long *value, int typesize)
{
	if (typesize == -2)
		*value = (char)*value;
	else if (typesize == -1)
		*value = (short)*value;
	else if (typesize == 0)
		*value = (int)*value;
	else if (typesize == 1)
		*value = (long)*value;
	else if (typesize == 2)
		*value = (long long)*value;
	return (typesize);
}

static	int			find_size(long long value, int base)
{
	int i;
	int neg;

	i = 0;
	neg = 0;
	if (value < 0 && base == 10)
		neg = 1;
	value = ft_maxabs(value);
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i + neg);
}

static char			*get_case(int alphacase)
{
	char *tab;

	if (alphacase == 2)
		tab = ft_strdup("0123456789ABCDEF");
	else
		tab = ft_strdup("0123456789abcdef");
	return (tab);
}

char				*pf_toa_sign(long long val, int b, int type_size, int alph)
{
	int			len;
	char		*dest;
	char		*tab;
	int			sign;

	if (val < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	sign = 0;
	if (val == 0)
		return (ft_ctostr('0'));
	type_size = adjust_typesize(&val, type_size);
	if (val < 0)
		sign = 1;
	tab = get_case(alph);
	len = find_size(val, b);
	val = ft_maxabs(val);
	dest = ft_strnew(len);
	while (len)
	{
		len--;
		dest[len] = tab[(val % b)];
		val /= b;
	}
	if (sign == 1 && b == 10)
		dest[0] = '-';
	free(tab);
	return (dest);
}