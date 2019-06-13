

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

long double ft_ld_make_zero(long double value);
char        *ft_strndup(char *src, size_t nb);
char        *ft_ctostr(char c);
int         ft_cinstr(const char *str, char c);
char        *ft_stradd(char *target, char *add);
int         ft_count_cinstr(char *str, char c);
char        *ft_strdup_exep(const char *s1, char c);
char	    *ft_strdup_until(const char *s1, char end);
char        *ft_strjoin_free(char *s1, char *s2, int mode); 
size_t      ft_strlen(const char *str);
int         ft_strcmp(const char *s1, const char *s2);
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
int         ft_isspace(char c);
int         ft_issign(char c);
int         ft_isdigit(char c);
char        *ft_str_tail(char *str);
size_t      ft_count_digits(char *str);
void        ft_move_sign(char *str);
int         ft_str_only(char *str, char c);
char        *ft_strnew_c(size_t len, char c);
char		*ft_itoa_base(int value, int base);

#endif
