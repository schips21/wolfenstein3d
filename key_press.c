#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

void	key_press_extra(int key, t_all *all)
{
	if (key == 0)
	{
		if (all->map[(int)((all->plr.y - cos(all->plr.dir) * 40) /
		SCALE)][(int)(all->plr.x / SCALE)] != '1')
			all->plr.y -= cos(all->plr.dir) * 8;
		if (all->map[(int)((all->plr.y) / SCALE)][(int)((all->plr.x +
		sin(all->plr.dir) * 40) / SCALE)] != '1')
			all->plr.x += sin(all->plr.dir) * 8;
	}
	else if (key == 2)
	{
		if (all->map[(int)((all->plr.y + cos(all->plr.dir) * 40) /
		SCALE)][(int)(all->plr.x / SCALE)] != '1')
			all->plr.y += cos(all->plr.dir) * 8;
		if (all->map[(int)((all->plr.y) / SCALE)][(int)((all->plr.x -
		sin(all->plr.dir) * 40) / SCALE)] != '1')
			all->plr.x -= sin(all->plr.dir) * 8;
	}
}

void	key_press_extra_2(int key, t_all *all)
{
	if (key == 1)
	{
		if (all->map[(int)((all->plr.y - sin(all->plr.dir) * 40)
		/ SCALE)][(int)(all->plr.x / SCALE)] != '1')
			all->plr.y -= sin(all->plr.dir) * 8;
		if (all->map[(int)((all->plr.y) / SCALE)][(int)((all->plr.x -
		cos(all->plr.dir) * 40) / SCALE)] != '1')
			all->plr.x -= cos(all->plr.dir) * 8;
	}
	else if (key == 123)
	{
		all->plr.dir -= 0.1;
		if (all->plr.dir < 0)
			all->plr.dir += 2 * M_PI;
	}
	else if (key == 124)
	{
		all->plr.dir += 0.1;
		if (all->plr.dir > 2 * M_PI)
			all->plr.dir -= 2 * M_PI;
	}
	else if (key == 53)
		exit(0);
}

int		key_press(int key, t_all *all)
{
	mlx_clear_window(all->win.mlx, all->win.win);
	if (key == 13)
	{
		if (all->map[(int)((all->plr.y + sin(all->plr.dir) * 40)
		/ SCALE)][(int)(all->plr.x / SCALE)] != '1')
			all->plr.y += sin(all->plr.dir) * 8;
		if (all->map[(int)((all->plr.y) / SCALE)][(int)((all->plr.x +
		cos(all->plr.dir) * 40) / SCALE)] != '1')
			all->plr.x += cos(all->plr.dir) * 8;
	}
	else if (key == 1)
		key_press_extra_2(key, all);
	else if (key == 0 || key == 2)
		key_press_extra(key, all);
	else if (key == 123 || key == 124 || key == 53)
		key_press_extra_2(key, all);
	draw_wall(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	mlx_do_sync(all->win.mlx);
	return (0);
}
