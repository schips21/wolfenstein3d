#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (ft_strlen(l) == 0)
		return ((char *)b);
	while (b[i] != 0 && i < len)
	{
		j = 0;
		while (b[i + j] == l[j] && (i + j) < len && l[j] != 0)
			j++;
		if (l[j] == 0)
			return ((char *)(b + i));
		i++;
	}
	return (0);
}
