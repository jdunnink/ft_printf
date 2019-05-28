/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ctostr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 17:45:38 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 17:46:07 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_ctostr(char c)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * 2);
	if (!dest)
		return (0);
	dest[0] = c;
	dest[1] = '\0';
	return (dest);
}
