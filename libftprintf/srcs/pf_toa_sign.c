/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_toa_sign.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:42:51 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:44:54 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static intmax_t	ft_maxabs(intmax_t nb)
{
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

static int			adjust_typesize(intmax_t *value, int typesize)
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

static	int			find_size(intmax_t value, int base)
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

char				*pf_toa_sign(intmax_t value, int base, int type_size, int alphacase)
{
	int			len;
	intmax_t	temp;
	char		*dest;
	char		*tab;

	type_size = adjust_typesize(&value, type_size);
	temp = (intmax_t)value;
	if (temp < -9223372036854775807)
		return ("-9223372036854775808");
	if (alphacase == 2)
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	len = find_size(temp, base);
	temp = ft_maxabs(temp);
	dest = ft_strnew(len);
	while (len)
	{
		len--;
		dest[len] = tab[(temp % base)];
		temp /= base;
	}
	if (value < 0 && base == 10)
		dest[0] = '-';
	return (dest);
}
