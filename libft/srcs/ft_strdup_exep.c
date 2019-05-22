/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup_exep.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 11:06:08 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/22 11:06:10 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_exep(const char *s1, char c)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while(s1[i] != '\0')
	{
		if (s1[i] != c)
			len++;
		i++;
	}
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest)
	{
		i = 0;
		len = 0;
		while (s1[len] != '\0')
		{
			if (s1[len] != c)
			{
				dest[i] = s1[len];
				i++;
			}
			len++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}