#include "libft.h"

static void	mem_else(size_t n, unsigned char *d, const unsigned char *s)
{
	size_t i;

	i = 1;
	while (i <= n)
	{
		d[n - i] = s[n - i];
		i++;
	}
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_temp;
	const unsigned char	*src_temp;
	size_t				i;

	dest_temp = (unsigned char*)dest;
	src_temp = (const unsigned char*)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (dest);
	if (src_temp > dest_temp)
	{
		while (i < n)
		{
			dest_temp[i] = src_temp[i];
			i++;
		}
	}
	else
	{
		mem_else(n, dest_temp, src_temp);
	}
	return (dest);
}
