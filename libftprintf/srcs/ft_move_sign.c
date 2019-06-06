
#include "printf.h"

void    ft_move_sign(char *str)
{
	char tmp;
	char *iter;
	char *eval;

	eval = str;
	while (ft_isspace(*str) == 1)
		str++;
	iter = str + 1;
	while (*iter != '\0')
	{
		if (ft_issign(*iter) == 1)
		{
			tmp = *iter;
			*iter = *str;
			*str = tmp;
		}
		iter++;
	}
}