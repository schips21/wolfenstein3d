#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

void	parse_resol(char *line, t_all *all)
{
	char	*numb;
	int		i;
	t_point scr_size;
	int		x;
	int		y;

	i = 0;
	numb = ft_strtrim(line, " ");
	mlx_get_screen_size(all->win.mlx, &scr_size.x, &scr_size.y);
	x = ft_atoi(&numb[i], scr_size.x);
	all->win.width = (x > scr_size.x) ? scr_size.x : x;
	while (numb[i] >= '0' && numb[i] <= '9')
		i++;
	while (numb[i] == ' ')
		i++;
	y = ft_atoi(&numb[i], scr_size.y);
	all->win.height = (y > scr_size.y) ? scr_size.y : y;
	while (numb[i] >= '0' && numb[i] <= '9')
		i++;
	if (all->win.width == 0 || all->win.height == 0 || numb[i] != '\0')
		ft_error((void **)&numb, 'R');
	all->pars.r++;
	ft_free((void **)&numb);
}

void	parse_col_ind(char *n, int *j, int *k, int *e)
{
	int com;

	com = 0;
	while (n[*j] >= '0' && n[*j] <= '9')
		(*j)++;
	while (n[*j] == ' ' || (n[*j] == ',' && com == 0))
	{
		if (n[*j] == ',')
			com = 1;
		(*j)++;
	}
	*k = *j;
	while (n[*k] >= '0' && n[*k] <= '9')
		(*k)++;
	while (n[*k] == ' ' || (n[*k] == ',' && com == 1))
	{
		if (n[*k] == ',')
			com = 2;
		(*k)++;
	}
	*e = *k;
	while (n[*e] >= '0' && n[*e] <= '9')
		(*e)++;
}

void	parse_col(char *line, char cf, t_all *all)
{
	char	*n;
	int		j;
	int		k;
	int		e;
	int		rgb;

	j = 0;
	n = ft_strtrim(line, " ");
	parse_col_ind(n, &j, &k, &e);
	if (!(n[0] >= '0' && n[0] <= '9') || !(n[j] >= '0' && n[j] <= '9')
	|| !(n[k] >= '0' && n[k] <= '9') || ft_atoi(&n[0], 2555) > 255 ||
	ft_atoi(&n[j], 2555) > 255 || ft_atoi(&n[k], 2555) > 255 || n[e] != '\0')
		ft_error((void **)&n, 'c');
	rgb = ((ft_atoi(&n[0], 2555) & 0x0ff) << 16) |
			((ft_atoi(&n[j], 2555) & 0x0ff) << 8) |
			(ft_atoi(&n[k], 2555) & 0x0ff);
	if (cf == 'c')
		all->all_text.ceiling_col = rgb;
	else
		all->all_text.floor_col = rgb;
	if (cf == 'c')
		all->pars.c++;
	else
		all->pars.f++;
	ft_free((void **)&n);
}

void	check_numb(char *line, t_all *all)
{
	if (*line == 'R' && *(line + 1) == ' ')
		parse_resol(line + 2, all);
	else if (*line == 'F' && *(line + 1) == ' ')
		parse_col(line + 2, 'f', all);
	else if (*line == 'C' && *(line + 1) == ' ')
		parse_col(line + 2, 'c', all);
}
