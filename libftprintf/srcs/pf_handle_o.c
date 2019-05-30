
#include "printf.h"

static	char	*add_prefix(char *arg)
{
	char *prefix;
	char *dest;

	prefix = ft_strdup("0");
	dest = ft_strjoin_free(prefix, arg, 3);
	return (dest);
}

static	char	*pf_o_width(char *arg, int pad_size, char *flags)
{
	char	*pad;
	char	*dest;

	pad = pf_add_pad(pad_size, ' ');
	if (ft_cinstr(flags, '-') == 1)
		dest = ft_strjoin_free(arg, pad, 3);
	else
		dest = ft_strjoin_free(pad, arg, 3);
	return (dest);
}

static	char	*pf_o_precis(char *arg, int precis)
{
	int	arg_len;
	int	pad_len;
	char	*padding;
	char	*dest;

	arg_len = ft_strlen(arg);
	if (precis <= arg_len)
		return (arg);
	pad_len = precis - arg_len;
	padding = pf_add_pad(pad_len, '0');
	dest = ft_strjoin_free(padding, arg, 3);
	return (dest);
}

int				pf_handle_o(char **tmp, t_spec info, va_list a_list)
{
    unsigned long long res;

	res = (unsigned long long)va_arg(a_list, unsigned long long);
	if (res == 0)
        *tmp = ft_ctostr('0');
	else
    	*tmp = pf_toa_unsign(res, 8, info.type_size, 1);
    if (info.prec_on == 1)
		*tmp = pf_o_precis(*tmp, info.precis);
	else if (info.width_on == 1 && ft_cinstr(info.flags, '0') == 1)
	{
		if (ft_cinstr(info.flags, '#') == 1)
			*tmp = pf_o_precis(*tmp, info.width - 1);
		else
			*tmp = pf_o_precis(*tmp, info.width);
	}
	if (info.prec_on == 1 && info.precis == 0 && **tmp == '0')
		*tmp = ft_strdup_exep(*tmp, '0');
	if (ft_cinstr(info.flags, '#') == 1 && *tmp[0] != '0')
		*tmp = add_prefix(*tmp);
	if (info.width_on == 1 && info.width > ft_strlen(*tmp))
		*tmp = pf_o_width(*tmp, info.width - ft_strlen(*tmp), info.flags);
	return (1);
}