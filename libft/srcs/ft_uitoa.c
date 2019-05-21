/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uitoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 10:39:01 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/22 15:12:51 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	find_length(unsigned int value)
{
	size_t len;

	len = 2;
	while (value /= 10)
		len++;
	return (len);
}

char			*ft_uitoa(unsigned int n)
{
	char			*dest;
	unsigned int	temp;
	size_t			len;

	temp = n;
	len = find_length(n);
	dest = (char*)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	len--;
	dest[len] = '\0';
	while (len > 0)
	{
		len--;
		dest[len] = 48 + (n % 10);
		n = n / 10;
	}
	return (dest);
}