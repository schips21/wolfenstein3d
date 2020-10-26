#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *i;

	if (!lst)
		return (NULL);
	i = lst;
	while (i->next != NULL)
		i = i->next;
	return (i);
}
