/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_toa_unsign.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:45:37 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:47:07 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	adjust_typesize(unsigned long long *value, int typesize)
{
	if (typesize == -2)
		*value = (unsigned char)*value;
	else if (typesize == -1)
		*value = (unsigned short)*value;
	else if (typesize == 0)
		*value = (unsigned int)*value;
	else if (typesize == 1)
		*value = (unsigned long)*value;
	return (typesize);
}

static int	find_size(unsigned long long value, int base)
{
	int i;

	i = 0;
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

char		*pf_toa_unsign(unsigned long long value, int base, int type_size, int alphacase)
{
	int			len;
	char		*dest;
	char		*tab;

	type_size = adjust_typesize(&value, type_size);
	if (value == 0)
		return (ft_ctostr('0'));
	if (alphacase == 2)
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	len = find_size(value, base);
	dest = ft_strnew(len);
	while (len)
	{
		len--;
		dest[len] = tab[(value % base)];
		value /= base;
	}
	return (dest);
}
