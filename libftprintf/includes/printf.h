

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct      s_spec
{
    char            *flags;
    unsigned int    width;
    unsigned int    width_on;
    unsigned int    precis;
    int             prec_on;
    size_t          spec_len;
    char            type;
    int             type_size;
}                   t_spec;

int         ft_printf(const char * restrict format, ...);

void        pf_flag_override(t_spec *format);
t_spec      pf_get_specinfo(char *format);
int         pf_handle_csp(char **arg, t_spec info, va_list a_list);

char        *ft_strndup(char *src, size_t nb);          // creates a duplicate string, with up to n bytes of src.
char        *ft_ctostr(char c);                         // returns a null terminated string version of the char c.
int         ft_cinstr(const char *str, char c);         // checks whether the char c is present in str, returns 1 if yes.
char        *ft_stradd(char *target, char *add);        // adds string add to *target, if target already exists.
int         ft_count_cinstr(char *str, char c);         // count the occurences of char c in str
char        *ft_strdup_exep(const char *s1, char c);    // create duplicate of s1, exept chars that match c

size_t      ft_strlen(const char *str);
char	    *ft_strjoin(char const *s1, char const *s2);
char        *ft_strcpy(char *dst, const char *src);
char        *ft_strcat(char *s1, const char *s2);
int         ft_atoi(const char *str);
char        *ft_strnew(size_t size);
void        *ft_memset(void *b, int c, size_t len);
long int	ft_labs(long int nb);
char        *ft_strdup(const char *s1);
void        ft_putchar(char c);
void        ft_putstr(char *str);

char		*ft_itoa_base(int value, int base);
char		*ft_utoa_base(unsigned int value, int base);
char		*ft_lutoa_base(unsigned long int value, int base);
char        *ft_ptoa(void *pointer, int base);

#endif