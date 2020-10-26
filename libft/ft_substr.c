#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		j;

	i = (int)start;
	j = 0;
	if (s == 0)
		return (0);
	if (s[start] == 0 || (int)start > ft_strlen(s))
		return (ft_strdup(""));
	if ((int)start + (int)len > ft_strlen(s))
		len = ft_strlen(s) - (int)start;
	str = (char *)malloc(sizeof(char) * ((int)len + 1));
	if (str == 0)
		return (0);
	while (s[i] != 0 && j < (int)len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = 0;
	return (str);
}
