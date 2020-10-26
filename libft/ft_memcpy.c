#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *temp;
	unsigned char *src2;

	temp = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	if (dest == 0 && src == 0)
		return (dest);
	while (n > 0)
	{
		*temp = *src2;
		temp++;
		src2++;
		n--;
	}
	return (dest);
}
