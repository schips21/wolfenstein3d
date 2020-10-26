char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s != 0)
		s++;
	if (*s == c)
		return ((char *)s);
	else
		return (0);
}
