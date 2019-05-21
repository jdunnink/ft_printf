/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 17:11:34 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/03 11:04:32 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long int		is_negative(long int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (-1);
	}
	else
		return (0);
}

static size_t	find_length(long int value, long int neg)
{
	size_t len;

	len = 2;
	while (value /= 10)
		len++;
	if (neg == -1)
		return (len + 1);
	else
		return (len);
}

char			*ft_ltoa(long int n)
{
	char			*dest;
	long int		neg;
	long int		temp;
	long int		ll;
	size_t			len;

	ll = (long)n;
	neg = 0;
	temp = ll;
	neg = is_negative(&ll);
	len = find_length(ll, neg);
	dest = (char*)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	len--;
	dest[len] = '\0';
	while (len > 0)
	{
		len--;
		dest[len] = 48 + (ll % 10);
		ll = ll / 10;
	}
	if (neg == -1)
		dest[0] = '-';
	return (dest);
}