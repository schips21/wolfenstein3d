#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;

	if (!(ptr = (void *)malloc(nmemb * size)))
		return (0);
	return (ft_memset(ptr, 0, nmemb * size));
}
