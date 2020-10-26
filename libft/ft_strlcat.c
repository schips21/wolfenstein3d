#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t d_len;
	size_t s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (d_len >= size)
		return (size + s_len);
	while (src[i] != 0 && d_len + i < size - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = 0;
	return (d_len + s_len);
}
