
#include "printf.h"

static char *remove_dup(char *str)
{
    int i;
    char *dest;

    printf("pf_remove_dup is called.\n");

    if (!str)
        return (0);
    i = 0;
    dest = 0;
    while (str[i] != '\0')
    {
        if (ft_cinstr(dest, str[i]) == 0)
            dest = ft_stradd(dest, ft_ctostr(str[i]));
        else if (str[i] == 'l' && ft_count_cinstr(dest, str[i]) == 1)
            dest = ft_stradd(dest, ft_ctostr(str[i]));
        else if (str[i] == 'h' && ft_count_cinstr(dest, str[i]) == 1)
            dest = ft_stradd(dest, ft_ctostr(str[i]));
        i++;
    }
    return (dest);
}

void pf_flag_override(t_spec *format)
{
    char *new_flags;

    printf("\nflag override is called with flags: %s\n", format->flags);

    if (ft_cinstr(format->flags, '-') == 1 && ft_cinstr(format->flags, '0') == 1)
    {
        printf("    flag '-' and '0' are both active --> overriding '0'\n");
        new_flags = ft_strdup_exep(format->flags, '0');
        free(format->flags);
        format->flags = new_flags;
    }
    if (ft_cinstr(format->flags, ' ') == 1 && ft_cinstr(format->flags, '+') == 1)
    {
        printf("    flag ' ' and '+' are both active --> overriding ' '\n");
        new_flags = ft_strdup_exep(format->flags, ' ');
        free(format->flags);
        format->flags = new_flags;
    }
    if (format->flags != 0 && ft_strlen(format->flags) > 1)
    {
        new_flags = remove_dup(format->flags);
        free(format->flags);
        format->flags = new_flags;
    }
}