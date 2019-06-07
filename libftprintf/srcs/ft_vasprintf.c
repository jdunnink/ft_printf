#include "printf.h"

static	int	pf_dispatch(char **tmp, t_spec info, va_list a_list)
{
	if (ft_cinstr("%csp", info.type) == 1)
		return (pf_handle_csp(tmp, info, a_list));
	else if (ft_cinstr("idu", info.type) == 1)
		return (pf_handle_idu(tmp, info, a_list));
	else if (ft_cinstr("xX", info.type) == 1)
		return (pf_handle_x(tmp, info, a_list));
	else if (info.type == 'f')
		return (pf_handle_f(tmp, info, a_list));
	else if (info.type == 'o')
		return (pf_handle_o(tmp, info, a_list));
	return (-1);
}

static	int	read_specifier(char **format, va_list a_list, char **tmp, int *sig)
{
	t_spec	*info;
	int		res;

	*sig = 1;
	res = 1;
	info = NULL;
	*format = *format + 1;
	info = pf_get_specinfo(format, info);
	res = pf_dispatch(tmp, *info, a_list);
	free(info->flags);
	free(info);
	if (res == 0)
		write(1, 0, 1);
	return (res);
}

static void		write_buf(char **buf, size_t *total, size_t *curr, int *sig)
{
	write(1, *buf, *curr);
	free(*buf);
	*buf = 0;
	*total += *curr;
	*curr = 0;
	*sig = 0;
}

int			ft_vasprintf(char **dest, const char *format, va_list a)
{
	char	*tmp;
	size_t	total_len;
	size_t	curr_len;
	int sig;
	int res;

	*dest = 0;
	total_len = 0;
	curr_len = 0;
	tmp = 0;
	sig = 0;
	res = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			res = read_specifier((char**)&format, a, &tmp, &sig);
			if (res == 0)
				curr_len++;
			else if (res == -1)
				return (0);
		}
		else
			tmp = ft_ctostr(*format);
		curr_len += ft_strlen(tmp);
		*dest = ft_stradd(*dest, tmp);
		if (curr_len >= BUFF_SIZE || *(format + 1) == '\0' || sig == 1)
			write_buf(dest, &total_len, &curr_len, &sig);
		format++;
	}
	return (total_len);
}