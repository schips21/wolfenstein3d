int		ft_strchr_s(const char *s, char *c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (c[j])
		{
			if (s[i] == c[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
