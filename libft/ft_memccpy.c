#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*src_temp;
	unsigned char	*dest_temp;
	int				flag;
	size_t			i;

	src_temp = (unsigned char*)src;
	dest_temp = (unsigned char*)dest;
	flag = 0;
	i = 0;
	while (i < n && flag == 0)
	{
		dest_temp[i] = src_temp[i];
		if (dest_temp[i] == (unsigned char)c)
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (dest_temp + i);
	else
		return (0);
}
