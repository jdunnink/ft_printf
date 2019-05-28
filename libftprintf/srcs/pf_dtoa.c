/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 07:38:44 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/27 07:38:45 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *pf_dtoa(double value, int precision)
{
    char *dest;
    char *tmp;
    char *next;
    int count;

    tmp = pf_ltoa((long)value);
    dest = ft_strjoin(tmp, ".");
    free(tmp);
    count = 0;
    value = value - (long)value;
    if (value < 0)
        value = value * -1;
    while(precision > 0)
    {
        count++;
        value = value * 10;
        if (count == 1)
        {
            count = 0;
            tmp = pf_ltoa((long)value);
            value = value - (long)value;
            next = ft_strjoin(dest, tmp);
            free(dest);
            free(tmp);
            dest = next;
        }
        precision--;
    }
    return (dest);
}