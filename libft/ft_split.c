#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (s[i] == c && s[i] != 0)
		i++;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			res++;
			while (s[i] == c && s[i] != 0)
				i++;
		}
		else
			i++;
	}
	if (s[i] == 0 && s[i - 1] != c && s[i - 1] != 0)
		res++;
	return (res);
}

static char	*alloc_words(char const *s, char c)
{
	int		i;
	int		count;
	char	*temp;

	i = 0;
	count = 0;
	while (s[i] == c && s[i] != 0)
		i++;
	while (s[i] != c && s[i] != 0)
	{
		i++;
		count++;
	}
	temp = (char *)malloc(sizeof(char) * (count + 1));
	if (temp == 0)
		return (0);
	ft_strlcpy(temp, (s + i - count), count + 1);
	return (temp);
}

static int	free_str(int i, char **str)
{
	while (i > 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		words_c;
	int		i;
	int		j;

	if (s == 0)
		return (0);
	words_c = count_words(s, c);
	str = (char **)malloc(sizeof(*str) * (words_c + 1));
	if (str == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < words_c)
	{
		while (s[j] == c)
			j++;
		str[i] = alloc_words((s + j), c);
		if (str[i] == 0)
			free_str(i, str);
		j += ft_strlen(str[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
