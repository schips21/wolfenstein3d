#include "libft.h"

static int		ft_plus(const char *str, int i, int max)
{
	int ans;

	ans = 0;
	while (str[i] >= '0' && str[i] <= '9' && ans / 10 < max)
	{
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	return (ans);
}

int				ft_atoi(const char *nptr, int max)
{
	int i;
	int ans;

	i = 0;
	ans = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
	|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ans = ft_plus(nptr, i, max);
		if (ans > max)
			return (max);
	}
	return (ans);
}
