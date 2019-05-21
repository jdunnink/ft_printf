/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 16:31:12 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/21 16:31:13 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int ft_round(double value)
{
    if (value < 0)
        value = value * -1;
    if (value * 10 >= 5)
        return (1);
    return (0);
}

char *ft_dtoa(double value, int precision)
{
    int len;
    char *dest;
    char *first;
    char *second;

    first = ft_ltoa((long)value);
    value = value - (long)value;
    while(precision > 0)
    {
        value = value * 10;
        precision--;
    }
    if (value != 0)
    {
        if (value < 0)
            value = value * -1;
        if (ft_round(value - (long)value) == 1)
            value = value + 1;
        second = ft_ltoa((long)value);
    }
    else
        second = ft_strdup("000000");
    dest = ft_strjoin(first, ".");
    free(first);
    first = ft_strjoin(dest, second);
    free(dest);
    free(second);
    return (first);
}