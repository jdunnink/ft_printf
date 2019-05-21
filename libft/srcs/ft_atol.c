/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:54:24 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/03/29 12:03:47 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atol(const char *str)
{
	long int			i;
	long int			res;
	long int			neg;

	res = 0;
	i = 0;
	neg = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
					str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		++i;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}