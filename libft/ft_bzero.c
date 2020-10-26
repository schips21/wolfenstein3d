#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char*)s;
	i = 0;
	while (n > 0)
	{
		temp[i] = 0;
		i++;
		n--;
	}
}
