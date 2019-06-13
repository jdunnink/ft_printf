

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define BUFF_SIZE 300

typedef struct      s_spec
{
    char            *flags;
    unsigned int    width;
    unsigned int    width_on;
    unsigned int    precis;
    int             prec_on;
    char            type;
    int             type_size;
}                   t_spec;

int         ft_printf(const char *format, ...);
int         ft_asprintf(char **dest, const char *format, ...);
int			ft_vasprintf(char **dest, const char *format, va_list a);

void        pf_flag_override(t_spec *format);          
t_spec      *pf_get_specinfo(char **format, t_spec *info);
int         pf_handle_csp(char **arg, t_spec info, va_list a_list);
int         pf_handle_idu(char **tmp, t_spec info, va_list a_list);
int         pf_handle_x(char **tmp, t_spec info, va_list a_list);
int         pf_handle_f(char **tmp, t_spec info, va_list a_list);
int			pf_handle_o(char **tmp, t_spec info, va_list a_list);

char		*pf_toa_sign(long long val, int b, int type_size, int alph);
char		*pf_toa_unsign(unsigned long long val, int b, int type_size, int a);
char        *ft_ptoa(void *pointer, int base);
char        *pf_dtoa(long double value, int precision);
char		*pf_ltoa(long int n);
void		pf_round_ld(long double value, char **dest);

#endif
