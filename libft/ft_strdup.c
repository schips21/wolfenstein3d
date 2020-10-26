#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
