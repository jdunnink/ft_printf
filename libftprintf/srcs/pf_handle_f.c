/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_handle_fF.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 18:19:35 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/28 18:26:30 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	char	*pf_strjoin_free(char *s1, char *s2)
{
	char	*dest;
	size_t	destlen;

	if (!s1 || !s2)
		return (NULL);
	dest = NULL;
	destlen = ft_strlen(s1) + ft_strlen(s2);
	if (s1 && s2)
	{
		dest = (char*)malloc(sizeof(char) * (destlen + 1));
		if (!dest)
			return (NULL);
		ft_strcpy(dest, s1);
		ft_strcat(dest, s2);
		free(s1);
		free(s2);
	}
	return (dest);
}

static	char	*pf_f_width(char *arg, int pad_size, char *flags, char c)
{
	char	*pad;
	char	*dest;

	pad = pf_add_pad(pad_size, c);
	if (ft_cinstr(flags, '-') == 1)
		dest = pf_strjoin_free(arg, pad);
	else
		dest = pf_strjoin_free(pad, arg);
	return (dest);
}

static	char	*pf_f_width_sign(char *arg, int pad_size, char *flags, char c)
{
	char	*pad;
	char	*dest;
	char	*sign;
	char	*tmp;

	if (*arg == '-' || *arg == '+')
	{
		tmp = arg + 1;
		sign = ft_ctostr(*arg);
	}
	else
		tmp = arg;
	pad = pf_add_pad(pad_size, c);
	if (ft_cinstr(flags, '-') == 1)
		dest = ft_strjoin(tmp, pad);
	else
		dest = ft_strjoin(pad, tmp);
	free(pad);
	free(arg);
	if (sign != 0)
	{
		arg = pf_strjoin_free(sign, dest);
		return (arg);
	}
	return (dest);
}

static	char	*add_dot(char *arg)
{
	char	*ptr;
	char	*dest;

	ptr = arg;
	while (ft_cinstr("-+0123456789", *ptr) == 1)
		ptr++;
	if (*ptr == '\0')
	{
		ptr = ft_strjoin(arg, ".");
		free(arg);
		return (ptr);
	}
	if (*ptr == ' ')
	{
		*ptr = '.';
		return (arg);
	}
	return (arg);
}

int				pf_handle_f(char **tmp, t_spec info, va_list a_list)
{
	char	*new_tmp;
	char	*pad;

	pad = 0;
	if (info.precis == 0 && info.prec_on == 1)
		info.precis = 0;
	else if (info.precis == 0 && info.prec_on == 0)
		info.precis = 6;
	if (info.type == 'f' || info.type == 'F')
		*tmp = pf_dtoa((double)va_arg(a_list, double), info.precis);
	if (info.prec_on == 1 && info.precis == 0)
		*tmp = ft_strdup_until(*tmp, '.');
	if (ft_cinstr(info.flags, '+') && **tmp != '-')
		*tmp = pf_strjoin_free(ft_strdup("+"), *tmp);
	if (ft_cinstr(*tmp, '.') == 0 && ft_cinstr(info.flags, '#') == 1)
		*tmp = add_dot(*tmp);
	if (ft_cinstr(info.flags, ' ') == 1)
		*tmp = pf_strjoin_free(ft_strdup(" "), *tmp);
	if (info.width_on == 1 && info.width > ft_strlen(*tmp) && ft_cinstr(info.flags, '0') == 0)
		*tmp = pf_f_width(*tmp, info.width - ft_strlen(*tmp), info.flags, ' ');
	else if (info.width_on == 1 && info.width > ft_strlen(*tmp) && ft_cinstr(info.flags, '0') == 1)
		*tmp = pf_f_width_sign(*tmp, info.width - ft_strlen(*tmp), info.flags, '0');
	return (1);
}
