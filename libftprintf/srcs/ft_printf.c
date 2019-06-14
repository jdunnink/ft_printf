/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 08:08:05 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/06/14 08:08:31 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	char	*dest;
	int		len;
	va_list	a_list;

	dest = 0;
	va_start(a_list, format);
	len = ft_vasprintf(&dest, format, a_list, 0);
	va_end(a_list);
	return (len);
}
