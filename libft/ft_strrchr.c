char	*ft_strrchr(const char *s, int c)
{
	int i;
	int res;
	int flag;

	i = 0;
	res = 0;
	flag = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			res = i;
			flag = 1;
		}
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	if (flag == 1)
		return ((char *)s + res);
	return (0);
}
