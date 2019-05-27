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

#include "printf.h"

char	*ft_strdup_exep(const char *s1, char c)
{
	char	*dest;
	char	*tmp;
	size_t	len;

	len = 0;
	tmp = (char *)s1;
	while(*tmp != '\0')
	{
		if (*tmp != c)
			len++;
		tmp++;
	}
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (0);
	dest[len] = '\0';
	tmp = dest;
	while (*s1 != '\0')
	{
		if (*s1 != c)
		{
			*dest = *s1;
			dest++;
		}
		s1++;
	}
	return (tmp);
}