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

static	int	find_size(long long value)
{
	int i;
	int neg;

	i = 0;
	while (value > 0)
	{
		value /= 10;
		i++;
	}
	return (i);
}

char				*pf_idtoa(long long value, int type_size)
{
	int			len;
	long long int	temp;
	char		*dest;
	char		*tab;

	if (type_size == -2)
		temp = (char)value;
	else if (type_size == -1)
		temp = (short)value;
	else if (type_size == 0)
		temp = (int)value;
	else if (type_size == 1)
		temp = (long)value;
	else if (type_size == 2)
		temp = value;
	len = ft_find_size(temp);
	dest = ft_strnew(len);
	while (len)
	{
		len--;
		dest[len] = temp % 10 + '0';
		temp /= 10;
	}
	return (dest);
}