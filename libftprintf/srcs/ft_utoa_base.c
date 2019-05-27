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

static	long	int	ft_find_size(unsigned long int value, int base)
{
	int i;
	int neg;

	i = 0;
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

char				*ft_utoa_base(unsigned int value, int base)
{
	int			len;
	long int	temp;
	char		*dest;
	char		*tab;

	temp = (unsigned long int)value;
	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_find_size(temp, base);
	dest = ft_strnew(len);
	while (len)
	{
		len--;
		dest[len] = tab[(temp % base)];
		temp /= base;
	}
	return (dest);
}