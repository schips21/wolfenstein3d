#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

void	my_mlx_pixel_put(t_win *data, int x, int y, unsigned color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int		red_cross(void)
{
	exit(0);
}

void	pars_errors(t_all *all)
{
	if (map_valid(all->map, 0) != 1)
		ft_error((void **)&all->map, 'i');
	if (all->pars.r != 1 || all->pars.no != 1 || all->pars.so != 1 || \
	all->pars.we != 1 || all->pars.ea != 1 || all->pars.s != 1 || \
	all->pars.f != 1 || all->pars.c != 1 || *all->map == NULL || \
	all->pars.map != 1)
		ft_error((void **)&all->map, 'i');
}

int		check_cub_ext(char *name)
{
	int i;

	i = ft_strlen(name) - 1;
	if (name[i] == 'b' && name[i - 1] == 'u' &&
		name[i - 2] == 'c' && name[i - 3] == '.')
		return (1);
	return (0);
}

char	*ft_strjoin_map(char *s1, char c, int n)
{
	char	*str;
	int		i;

	if (s1 == 0)
		return (0);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
	if (str == 0)
		return (0);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (n != 0)
	{
		str[i] = c;
		i++;
		n--;
	}
	str[i] = 0;
	ft_free((void **)&s1);
	return (str);
}
