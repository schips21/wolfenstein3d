#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_temp;
	const unsigned char	*s2_temp;
	size_t				i;

	s1_temp = (const unsigned char *)s1;
	s2_temp = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1_temp[i] == s2_temp[i] && i < n - 1)
	{
		i++;
	}
	return (s1_temp[i] - s2_temp[i]);
}
