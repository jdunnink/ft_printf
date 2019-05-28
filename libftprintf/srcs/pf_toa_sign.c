/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 11:43:59 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/03 11:04:48 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static long long   ft_llabs(long long nb)
{
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

static int  adjust_typesize(long long *value, int typesize)
{
    if (typesize == -2)
        *value = (char)*value;
    else if (typesize == -1)
        *value = (short)*value;
    else if (typesize == 0)
        *value = (int)*value;
    else if (typesize == 1)
        *value = (long)*value;
    return (typesize);
}

static	int	find_size(long long value, int base)
{
	int i;
	int neg;

	i = 0;
	neg = 0;
	if (value < 0 && base == 10)
		neg = 1;
	value = ft_labs(value);
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i + neg);
}

char				*pf_toa_sign(long long value, int base, int type_size, int alphacase)
{
	int			len;
	long long	temp;
	char		*dest;
	char		*tab;

    type_size = adjust_typesize(&value, type_size);
	temp = (long long)value;
    if (temp == -9223372036854775807)
        return ("-9223372036854775807");
    if (alphacase == 2)
	    tab = "0123456789ABCDEF";
    else
        tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	len = find_size(temp, base);
	temp = ft_llabs(temp);
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