#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char*)destination;
	while (n > 0)
	{
		*temp = (unsigned char)c;
		temp++;
		n--;
	}
	return (destination);
}
