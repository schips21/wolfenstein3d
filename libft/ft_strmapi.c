#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (s == 0 || f == 0)
		return (0);
	str = ft_strdup(s);
	if (str == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
