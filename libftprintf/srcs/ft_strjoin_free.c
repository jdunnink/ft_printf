
#include "printf.h"

char	*ft_strjoin_free(char *s1, char *s2, int mode)
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
        if (mode == 1 || mode == 3)
		    free(s1);
        if (mode == 2 || mode == 3)
		    free(s2);
	}
	return (dest);
}