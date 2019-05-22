/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cinstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 11:10:32 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/22 11:10:59 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_cinstr(const char *str, char c)
{
    size_t i;

    if (!str)
        return (0);
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}
