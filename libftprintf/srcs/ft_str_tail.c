
char    *ft_str_tail(char *str)
{
	while (*(str + 1) != '\0')
		str++;
	return (str);
}