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
	printf("pf_dispatch is called\n");
	if (ft_cinstr("%csp", info.type) == 1)
	{
		printf("    pf_handle_csp is called.\n");
		return (pf_handle_csp(tmp, info, a_list));
	}
	else if (ft_cinstr("iduU", info.type) == 1)
	{
		printf("    pf_handle_idu is called.\n");
		return (pf_handle_idu(tmp, info, a_list));
	}
	else if (ft_cinstr("xX", info.type) == 1)
	{
		printf("    pf_handle_xX is called.\n");
		return (pf_handle_x(tmp, info, a_list));
	}
	else if (ft_cinstr("fF", info.type) == 1)
	{
		printf("    pf_handle_fF is called.\n");
		return (pf_handle_f(tmp, info, a_list));
	}
	else if (info.type == 'o')
	{
		printf("	pf_handle_o is called.\n");
		return (pf_handle_o(tmp, info, a_list));
	}
	printf("    format type is not currently supported.\n");
	return (-1);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	a_list;
	char	*tmp;
	size_t	total_len;
	int		res;
	t_spec	*info;

	printf("\n\nstart function --> printf is called\n");
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
			printf("\nget specinfo DONE:\n");
			if (info->width_on == 1)
				printf("    field width is enabled\n");
			if (info->prec_on == 1)
				printf("    precision is enabled\n");
			printf("    applicable flags: ||%s||\n", info->flags);
			printf("    argument type: %c\n", info->type);
			printf("    argument type_size: %i\n", info->type_size);
			printf("    spec length: %lu\n", info->spec_len);
			printf("    precision: %u\n", info->precis);
			printf("    field width: %u\n\n", info->width);
			res = pf_dispatch(&tmp, *info, a_list);
			if (res == 0 && info->type != 'd')
				total_len--;
			else if (res == -1)
				return (0);
			format = format + (info->spec_len);
			printf("\nformatting was completed successfully -> argument: %s\n\n\n", tmp);
			free(info->flags);
			free(info);
		}
		else
			tmp = ft_ctostr(*format);
		total_len += ft_strlen(tmp);
		ft_putstr(tmp);
		free(tmp);
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
