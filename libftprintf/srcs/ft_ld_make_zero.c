
long double ft_ld_make_zero(long double value)
{
	if (value > 1000000000000000000)
		value = value - value;
	while (value > 100000000000000000)
		value = value - 100000000000000000;
	while (value > 10000000000000000)
		value = value - 10000000000000000;
	while (value > 1000000000000000)
		value = value - 1000000000000000;
	while (value > 100000000000000)
		value = value - 100000000000000;
	while (value > 10000000000000)
		value = value - 10000000000000;
	while (value > 1000000000000)
		value = value - 1000000000000;
	while (value > 100000000000)
		value = value - 100000000000;
	while (value > 10000000000)
		value = value - 10000000000;
	while (value > 1000000000)
		value = value - 1000000000;
	while (value > 100000000)
		value = value - 100000000;
	while (value > 10000000)
		value = value - 10000000;
	while (value > 10000000)
		value = value - 10000000;
	value = value - (int)value;
	return (value);
}
