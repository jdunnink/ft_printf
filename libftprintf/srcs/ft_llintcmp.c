
int ft_llintcmp(long long int one, long long int two)
{
    if (one == two)
		return (0);
	else if (one > two)
		return (1);
	return (-1);
}