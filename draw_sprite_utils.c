#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

void	ft_swap_spr(t_list_spr **head, t_list_spr *tmp_sort)
{
	t_list_spr	*tmp;

	tmp = tmp_sort->next;
	if (*head == tmp_sort)
	{
		tmp_sort->next = tmp_sort->next->next;
		tmp->next = tmp_sort;
		*head = tmp;
	}
	else
	{
		tmp = *head;
		while (tmp->next != tmp_sort)
			tmp = tmp->next;
		tmp->next = tmp_sort->next;
		tmp_sort->next = tmp->next->next;
		tmp->next->next = tmp_sort;
	}
}

void	sort_sprite(t_all *all, int t)
{
	t_list_spr	*tmp_sort;

	while (t)
	{
		tmp_sort = all->spr_coord;
		t = 0;
		while (tmp_sort->next)
		{
			if (tmp_sort->dist_spr_plr < tmp_sort->next->dist_spr_plr)
			{
				ft_swap_spr(&all->spr_coord, tmp_sort);
				t = 1;
			}
			else
				tmp_sort = tmp_sort->next;
		}
	}
}

void	ft_dist_to_spr(t_all *all)
{
	t_list_spr	*tmp;

	tmp = all->spr_coord;
	while (tmp->next != NULL)
	{
		tmp->dist_spr_plr = sqrt(pow(all->plr.x - tmp->x, 2) + \
				pow(all->plr.y - tmp->y, 2));
		tmp = tmp->next;
	}
	tmp->dist_spr_plr = sqrt(pow(all->plr.x - tmp->x, 2) + \
				pow(all->plr.y - tmp->y, 2));
	sort_sprite(all, 1);
}
