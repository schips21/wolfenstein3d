#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

t_list_spr	*ft_lstnew_spr(int x, int y)
{
	t_list_spr	*new;

	if (!(new = malloc(sizeof(t_list_spr))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

t_list_spr	*ft_lstlast_spr(t_list_spr *lst)
{
	t_list_spr *i;

	if (!lst)
		return (NULL);
	i = lst;
	while (i->next != NULL)
		i = i->next;
	return (i);
}

void		ft_lstadd_back_spr(t_list_spr **lst, t_list_spr *new)
{
	t_list_spr	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast_spr(*lst);
	tmp->next = new;
}
