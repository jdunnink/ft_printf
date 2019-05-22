

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct      s_fspec
{
    char            *flags;
    unsigned int    width;
    unsigned int    width_on;
    unsigned int    precis;
    int             prec_on;
    size_t          len;
    char            format;
}                   t_fspec;

#endif