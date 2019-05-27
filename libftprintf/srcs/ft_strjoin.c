
#include "printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	}
	return (dest);
}