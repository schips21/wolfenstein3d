#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

char	wall_side(t_all *all, t_plr *cur, t_plr *pre)
{
	if (all->map[(int)(pre->y / SCALE)][(int)(cur->x / SCALE)] == '1')
	{
		if (cur->x - pre->x < 0)
			return ('W');
		else
			return ('E');
	}
	else
	{
		if (cur->y - pre->y > 0)
			return ('S');
		else
			return ('N');
	}
}

int		dr_w_if(t_two_plr *p, t_all *all)
{
	if ((all->map[(int)(p->cur.y / SCALE)][(int)(p->cur.x / SCALE)] == '1') ||
	((all->map[(int)((p->cur.y + 1) / SCALE)][(int)((p->cur.x + 1)
	/ SCALE)] == '1') && (all->map[(int)((p->cur.y + 1) /
	SCALE)][(int)((p->cur.x - 1) / SCALE)] == '1')) ||
	((all->map[(int)((p->cur.y - 1) / SCALE)][(int)((p->cur.x +
	1) / SCALE)] == '1') && (all->map[(int)((p->cur.y - 1) /
	SCALE)][(int)((p->cur.x - 1) / SCALE)] == '1')))
		return (1);
	else
		return (0);
}

void	draw_wall_while(t_two_plr *p, t_all *all, double **all_dist, int x_cur)
{
	t_plr		pre;
	int			s;

	s = SCALE;
	p->cur.x = p->plr.x;
	p->cur.y = p->plr.y;
	while (p->cur.end)
	{
		pre.x = p->cur.x;
		pre.y = p->cur.y;
		p->cur.x = p->plr.x + p->cur.end * cos(p->plr.start);
		p->cur.y = p->plr.y + p->cur.end * sin(p->plr.start);
		if (dr_w_if(p, all) == 1)
		{
			(*all_dist)[x_cur] = p->cur.end;
			p->cur.end *= cos(p->plr.start - p->plr.dir);
			draw_w(all, x_cur, &p->cur, wall_side(all, &p->cur, &pre));
			break ;
		}
		p->cur.end += 1;
	}
}

void	draw_wall(t_all *all)
{
	t_two_plr	plr_cur;
	int			x_cur;
	double		*all_dist;

	plr_cur.plr = all->plr;
	plr_cur.plr.start = plr_cur.plr.dir - M_PI / 3 / 2;
	plr_cur.plr.end = plr_cur.plr.dir + M_PI / 3 / 2;
	x_cur = 0;
	all_dist = malloc(sizeof(double) * (all->win.width + 1));
	while (plr_cur.plr.start < plr_cur.plr.end)
	{
		plr_cur.cur.end = 1;
		draw_wall_while(&plr_cur, all, &all_dist, x_cur);
		x_cur++;
		plr_cur.plr.start += M_PI / 3 / all->win.width;
	}
	all_dist[x_cur] = '\0';
	if (all->spr_coord)
		draw_sprite_new(all, all_dist);
	ft_free((void **)&all_dist);
}
