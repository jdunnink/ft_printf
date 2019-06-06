
#include "printf.h"

size_t	ft_count_digits(char *str)
{
	size_t count;

	count = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 1)
			count++;
		str++;
	}
	return (count);
}