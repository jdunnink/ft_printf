/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 07:38:44 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:05:01 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*pf_dtoa(long double value, int precision)
{
	char	*dest;
	char	*tmp;
	char	*next;
	int		count;

	printf("	pf_toa is called with: %Lf and precision: %i\n", value, precision);	
	tmp = pf_ltoa((long)value);
	dest = ft_strjoin_free(tmp, ".", 1);
	count = 0;
	value = value - (long)value;
	if (value < 0)
		value = value * -1;
	while (precision > 0)
	{
		value = value * 10;
		tmp = pf_ltoa((long)value);
		value = value - (long)value;
		next = ft_strjoin_free(dest, tmp, 3);
		dest = next;
		precision--;
	}
	return (dest);
}
