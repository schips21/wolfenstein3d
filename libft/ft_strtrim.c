#include "libft.h"

static int	trim_one(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	f_trim(int start, int end, char *str, char const *s1)
{
	int i;

	i = 0;
	while (start + i <= end)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = 0;
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	start = 0;
	while (trim_one(s1[start], set) == 1)
		start++;
	if (start == (int)ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (trim_one(s1[end], set) == 1 && end > start)
		end--;
	if (start == end && !(start == 0 && end == 0))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (str == 0)
		return (0);
	f_trim(start, end, str, s1);
	return (str);
}
