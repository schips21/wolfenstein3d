#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

void	find_plr_start_pos(t_all *all, t_point *p)
{
	if (all->map[p->y][p->x] == 'S')
		all->plr.dir = M_PI_2;
	if (all->map[p->y][p->x] == 'N')
		all->plr.dir = 3 * M_PI_2;
	if (all->map[p->y][p->x] == 'E')
		all->plr.dir = 0;
	if (all->map[p->y][p->x] == 'W')
		all->plr.dir = M_PI;
}

void	find_plr_start(t_all *all)
{
	t_point	point;

	ft_bzero(&point, sizeof(t_point));
	all->spr_coord = NULL;
	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			if (ft_strchr("SNEW", all->map[point.y][point.x]) != 0)
			{
				all->plr.x = point.x * SCALE + SCALE / 2;
				all->plr.y = point.y * SCALE + SCALE / 2;
				find_plr_start_pos(all, &point);
			}
			else if (all->map[point.y][point.x] == '2')
			{
				ft_lstadd_back_spr(&all->spr_coord,
				ft_lstnew_spr(point.x * SCALE + SCALE / 2,
				point.y * SCALE + SCALE / 2));
			}
			point.x++;
		}
		point.y++;
	}
}
