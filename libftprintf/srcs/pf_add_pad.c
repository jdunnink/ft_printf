/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_add_pad.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:02:52 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:03:19 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*pf_add_pad(size_t len, char c)
{
	char	*pad;

	pad = ft_strnew(len);
	if (!pad)
		return (0);
	ft_memset(pad, c, len);
	return (pad);
}
