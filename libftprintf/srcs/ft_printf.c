/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 07:38:44 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:40:47 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int	pf_dispatch(char **tmp, t_spec info, va_list a_list)
{
	if (ft_cinstr("%csp", info.type) == 1)
		return (pf_handle_csp(tmp, info, a_list));
	else if (ft_cinstr("iduU", info.type) == 1)
		return (pf_handle_idu(tmp, info, a_list));
	else if (ft_cinstr("xX", info.type) == 1)
		return (pf_handle_x(tmp, info, a_list));
	else if (ft_cinstr("fF", info.type) == 1)
		return (pf_handle_f(tmp, info, a_list));
	else if (info.type == 'o')
		return (pf_handle_o(tmp, info, a_list));
	return (-1);
}

int			ft_asprintf(char **dest, const char *restrict format, ...)
{
	va_list	a_list;
	char	*tmp;
	size_t	total_len;
	int		res;
	t_spec	*info;

	*dest = 0;
	total_len = 0;
	tmp = 0;
	va_start(a_list, format);
	while (*format != '\0')
	{
		res = 0;
		if (*format == '%')
		{
			info = pf_get_specinfo((char*)format, info);
			pf_flag_override(info);
			res = pf_dispatch(&tmp, *info, a_list);
			if (res == -1)
				return (0);
			format = format + (info->spec_len);
			free(info->flags);
			free(info);
		}
		else
			tmp = ft_ctostr(*format);
		total_len += ft_strlen(tmp);
		if (*dest == 0)
			*dest = tmp;
		else
			*dest = ft_strjoin_free(*dest, tmp, 3);
		if (res == -3)
		{
			total_len++;
			ft_putchar('\0');
		}
		format++;
	}
	va_end(a_list);
	return (total_len);
}
