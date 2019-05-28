/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 13:36:10 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/03 11:10:33 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strdup_until(const char *s1, char end)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	while (s1[len] != '\0' && s1[len] != end)
		len++;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest)
	{
		i = 0;
		while (s1[i] != '\0' && s1[i] != end)
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}