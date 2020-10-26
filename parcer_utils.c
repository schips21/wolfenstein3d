#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

int		map_valid_if(char **m, int x, int y, int map_len)
{
	if (m[x][y] == '0' || m[x][y] == '2' || ft_strchr("SNEW", m[x][y]))
	{
		if (x == 0 || x == map_len - 1)
			return (-1);
		else if (m[x][y + 1] == ' ' || m[x][y - 1] == ' ' ||
		m[x + 1][y] == ' ' || m[x - 1][y] == ' ' || m[x][y + 1] == '\0' ||
		m[x][y - 1] == '\0' || m[x + 1][y] == '\0' || m[x - 1][y] == '\0' ||
		ft_strlen(m[x - 1]) < y || (m[x + 1] != NULL &&
		ft_strlen(m[x + 1]) < y))
			return (-1);
	}
	return (1);
}

int		map_valid(char **m, int map_len)
{
	int x;
	int y;
	int plr;

	x = 0;
	plr = 0;
	while (m[map_len] != NULL)
		map_len++;
	while (m[x] != NULL)
	{
		y = 0;
		while (m[x][y] != '\0')
		{
			if (ft_strchr("SNEW", m[x][y]))
				plr++;
			if (map_valid_if(m, x, y, map_len) == -1)
				return (-1);
			if (ft_strchr("SNEW012 ", m[x][y]) == 0)
				return (-1);
			y++;
		}
		x++;
	}
	return (plr);
}

void	ft_free(void **s)
{
	free(*s);
	*s = NULL;
}

void	ft_error(void **to_free, char er)
{
	if (er != 'a')
		ft_free(to_free);
	if (er == 'R')
		ft_putstr_fd("Error\nInvalid Resolution", 2);
	if (er == 'i')
		ft_putstr_fd("Error\nInvalid Map", 2);
	if (er == 't')
		ft_putstr_fd("Error\nInvalid texture path", 2);
	if (er == 'c')
		ft_putstr_fd("Error\nInvalid Colour", 2);
	if (er == 'a')
		ft_putstr_fd("Error\nInvalid Arguments", 2);
	if (er == 'm')
		ft_putstr_fd("Error\nI need map", 2);
	exit(0);
}

void	ft_map_to_list_ut(char *line, t_all *all, int var)
{
	char *str;

	if (var == 1)
	{
		if (ft_strlen(line) > all->max_map_l)
			all->max_map_l = ft_strlen(line);
	}
	else if (var == 2)
	{
		if (ft_strncmp(str = ft_strtrim(line, " "), "\0", 1))
			ft_error((void**)&line, 'i');
		ft_free((void**)&str);
	}
}
