/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_handle_csp.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:16:15 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:19:15 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	char	*pf_csp_width(char *arg, int width_on, int width, char *flags)
{
	char	*padding;
	char	*dest;
	size_t	ob_len;
	size_t	pad_len;

	ob_len = ft_strlen(arg);
	if (width_on == 0 || width < ob_len)
		return (arg);
	pad_len = width - ob_len;
	padding = (char*)malloc(sizeof(char) * (width - ob_len) + 1);
	if (!padding)
		return (arg);
	padding[pad_len] = '\0';
	ft_memset(padding, ' ', pad_len);
	if (ft_cinstr(flags, '-') == 1)
		dest = ft_strjoin(arg, padding);
	else
		dest = ft_strjoin(padding, arg);
	free(padding);
	free(arg);
	return (dest);
}

static	char	*pf_s_precis(char *arg, int prec_on, int precision)
{
	char *dest;

	if (prec_on == 0 || precision > ft_strlen(arg))
		return (arg);
	dest = ft_strndup(arg, precision);
	free(arg);
	return (dest);
}

int				pf_handle_csp(char **arg, t_spec info, va_list a_list)
{
	if (info.type == 'c')
		*arg = ft_ctostr((char)va_arg(a_list, int));
	else if (info.type == 's')
	{
		*arg = ft_strdup((char *)va_arg(a_list, char *));
		*arg = pf_s_precis(*arg, info.prec_on, info.precis);
	}
	else if (info.type == 'p')
		*arg = ft_strjoin("0x", ft_ptoa((void *)va_arg(a_list, void *), 16));
	else if (info.type == '%')
		*arg = ft_ctostr(info.type);
	else
		return (-1);
	*arg = pf_csp_width(*arg, info.width_on, info.width, info.flags);
	return (1);
}
