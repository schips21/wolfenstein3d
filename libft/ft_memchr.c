#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;
	size_t				i;

	temp = (const unsigned char*)s;
	i = 0;
	while (n > 0)
	{
		if (temp[i] == (unsigned char)c)
			return ((void*)temp + i);
		else
		{
			n--;
			i++;
		}
	}
	return (0);
}
