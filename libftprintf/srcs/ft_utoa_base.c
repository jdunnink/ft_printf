/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:02:10 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:02:35 by jdunnink      ########   odam.nl         */
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
