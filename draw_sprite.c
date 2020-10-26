#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

void	draw_sprite_bef_draw(t_all *all, t_list_spr *tmp, t_two_point *sprs)
{
	double	spr_dir;

	spr_dir = atan2(tmp->y - all->plr.y, tmp->x - all->plr.x);
	while (spr_dir - all->plr.dir > M_PI)
		spr_dir -= 2 * M_PI;
	while (spr_dir - all->plr.dir < -M_PI)
		spr_dir += 2 * M_PI;
	sprs->spr_size.dist = sqrt(pow(all->plr.x - tmp->x, 2) +
	pow(all->plr.y - tmp->y, 2));
	sprs->spr_size.y = (int)(all->win.height / sprs->spr_size.dist * SCALE);
	sprs->spr_size.x = (int)(all->win.height / sprs->spr_size.dist * SCALE);
	sprs->spr.offset_x = (int)((spr_dir - all->plr.dir) * all->win.width /
	(M_PI / 3) + (all->win.width / 2) - sprs->spr_size.x / 2);
	sprs->spr.offset_y = (int)((double)all->win.height /
	2 - (double)sprs->spr_size.y / 2);
}

void	draw_sprite_while(t_all *all, t_two_point *s, int *i, double *all_dist)
{
	int j;
	int col;

	j = 0;
	s->spr.y = all->all_text.text_spr.height * (*i) / s->spr_size.x;
	while (j < s->spr_size.y)
	{
		if (s->spr.offset_y + j < 0 || s->spr.offset_y + j > all->win.height)
		{
			j++;
			continue;
		}
		s->spr.x = all->all_text.text_spr.width * j / s->spr_size.y;
		col = *(int *)(all->all_text.text_spr.addr +
		(s->spr.x * all->all_text.text_spr.line_l +
		s->spr.y * (all->all_text.text_spr.bpp / 8)));
		if (col > 0 && s->spr_size.dist < all_dist[s->spr.offset_x + (*i)]
		&& s->spr.offset_y + j < all->win.height)
			my_mlx_pixel_put(&all->win, s->spr.offset_x + (*i),
			s->spr.offset_y + j, col);
		j++;
	}
}

void	draw_sprite_new(t_all *all, const double *all_dist)
{
	t_two_point	s;
	t_list_spr	*tmp;
	int			i;

	ft_dist_to_spr(all);
	tmp = all->spr_coord;
	while (tmp != NULL)
	{
		draw_sprite_bef_draw(all, tmp, &s);
		i = 0;
		while (i < s.spr_size.x)
		{
			if ((s.spr.offset_x + i) < 0 ||
			(s.spr.offset_x + i) > all->win.width)
			{
				i++;
				continue;
			}
			draw_sprite_while(all, &s, &i, (double *)all_dist);
			i++;
		}
		tmp = tmp->next;
	}
}
