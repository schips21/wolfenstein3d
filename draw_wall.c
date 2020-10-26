#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

void	draw_w_n(t_plr *cur, t_all *all, t_point *st_end, int x_cur)
{
	int x_text;
	int y_text;
	int col;

	x_text = (int)((double)((int)cur->x % SCALE) *
	((double)all->all_text.text_n.width / (double)SCALE));
	while (st_end->x < st_end->y && st_end->x < all->win.height - 1)
	{
		if (st_end->x < 0 || st_end->x > all->win.height)
		{
			st_end->x++;
			continue;
		}
		y_text = (int)((double)all->all_text.text_n.height *
		(double)(st_end->x - st_end->x_const) /
		(double)(st_end->y - st_end->x_const));
		col = *(int *)(all->all_text.text_n.addr + (y_text *
		all->all_text.text_n.line_l + x_text *
		(all->all_text.text_n.bpp / 8)));
		my_mlx_pixel_put(&all->win, x_cur, st_end->x++, col);
	}
}

void	draw_w_s(t_plr *cur, t_all *all, t_point *st_end, int x_cur)
{
	int x_text;
	int y_text;
	int col;

	x_text = (int)((double)((int)cur->x % SCALE) *
	((double)all->all_text.text_s.width / (double)SCALE));
	while (st_end->x < st_end->y && st_end->x < all->win.height - 1)
	{
		if (st_end->x < 0 || st_end->x > all->win.height)
		{
			st_end->x++;
			continue;
		}
		y_text = (int)((double)all->all_text.text_s.height *
		(double)(st_end->x - st_end->x_const) /
		(double)(st_end->y - st_end->x_const));
		col = *(int *)(all->all_text.text_s.addr +
		(y_text * all->all_text.text_s.line_l + x_text *
		(all->all_text.text_s.bpp / 8)));
		my_mlx_pixel_put(&all->win, x_cur, st_end->x++, col);
	}
}

void	draw_w_w(t_plr *cur, t_all *all, t_point *st_end, int x_cur)
{
	int x_text;
	int y_text;
	int col;

	x_text = (int)((double)((int)cur->y % SCALE) *
	((double)all->all_text.text_w.width / (double)SCALE));
	while (st_end->x < st_end->y && st_end->x < all->win.height - 1)
	{
		if (st_end->x < 0 || st_end->x > all->win.height)
		{
			st_end->x++;
			continue;
		}
		y_text = (int)((double)all->all_text.text_w.height *
		(double)(st_end->x - st_end->x_const) /
		(double)(st_end->y - st_end->x_const));
		col = *(int *)(all->all_text.text_w.addr +
		(y_text * all->all_text.text_w.line_l +
		x_text * (all->all_text.text_w.bpp / 8)));
		my_mlx_pixel_put(&all->win, x_cur, st_end->x++, col);
	}
}

void	draw_w_e(t_plr *cur, t_all *all, t_point *st_end, int x_cur)
{
	int x_text;
	int y_text;
	int col;

	x_text = (int)((double)((int)cur->y % SCALE) *
	((double)all->all_text.text_e.width / (double)SCALE));
	while (st_end->x < st_end->y && st_end->x < all->win.height - 1)
	{
		if (st_end->x < 0 || st_end->x > all->win.height)
		{
			st_end->x++;
			continue;
		}
		y_text = (int)((double)all->all_text.text_e.height *
		(double)(st_end->x - st_end->x_const) /
		(double)(st_end->y - st_end->x_const));
		col = *(int *)(all->all_text.text_e.addr +
		(y_text * all->all_text.text_e.line_l + x_text *
		(all->all_text.text_e.bpp / 8)));
		my_mlx_pixel_put(&all->win, x_cur, st_end->x++, col);
	}
}

void	draw_w(t_all *all, int x_cur, t_plr *cur, char side)
{
	t_point	st_end;
	int		ceil_i;
	int		fl_i;

	st_end.x = (int)((double)all->win.height / 2.0 -
			((double)all->win.height / cur->end * (double)SCALE) / 2.0);
	st_end.y = (int)((double)all->win.height / 2.0 +
			((double)all->win.height / cur->end * (double)SCALE) / 2.0);
	ceil_i = 0;
	while (ceil_i < st_end.x)
		my_mlx_pixel_put(&all->win, x_cur, ceil_i++, all->all_text.ceiling_col);
	st_end.x_const = st_end.x;
	if (side == 'N')
		draw_w_n(cur, all, &st_end, x_cur);
	else if (side == 'S')
		draw_w_s(cur, all, &st_end, x_cur);
	else if (side == 'W')
		draw_w_w(cur, all, &st_end, x_cur);
	else if (side == 'E')
		draw_w_e(cur, all, &st_end, x_cur);
	fl_i = st_end.y;
	while (fl_i < all->win.height - 1)
		my_mlx_pixel_put(&all->win, x_cur, fl_i++, all->all_text.floor_col);
}
