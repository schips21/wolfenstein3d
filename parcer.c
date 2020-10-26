#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

int		parser(char *line, t_all *all)
{
	int i;

	i = 0;
	if (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if ((line[i] == 'R' || line[i] == 'F' || line[i] == 'C') \
		&& line[i + 1] == ' ')
			check_numb(line + i, all);
		else if (((line[i] == 'N' && line[i + 1] == 'O') \
		|| (line[i] == 'S' && line[i + 1] == 'O') \
		|| (line[i] == 'W' && line[i + 1] == 'E') \
		|| (line[i] == 'E' && line[i + 1] == 'A')) && line[i + 2] == ' ')
			check_text(line + i, all);
		else if (line[i] == 'S' && line[i + 1] == ' ')
			check_text(line + i, all);
		else if (line[i] == '1')
			return (1);
		else
			ft_error((void **)&line, 'i');
		return (-1);
	}
	else
		return (-1);
}

char	**ft_make_map(t_list **head, int size)
{
	t_list	*tmp;
	int		i;
	char	**map;

	map = (char **)ft_calloc(size + 1, sizeof(char *));
	i = -1;
	tmp = *head;
	while (tmp)
	{
		map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(head, &free);
	return (map);
}

void	ft_map_to_list(char *line, t_list **head, int fd, t_all *all)
{
	int g;

	ft_map_to_list_ut(line, all, 1);
	ft_lstadd_back(head, ft_lstnew(ft_strdup(line)));
	g = get_next_line(fd, &line);
	while (g)
	{
		if (line[0] == '\0')
			break ;
		ft_map_to_list_ut(line, all, 1);
		ft_lstadd_back(head, ft_lstnew(ft_strdup(line)));
		ft_free((void **)&line);
		g = get_next_line(fd, &line);
	}
	if (line[0] == '\0')
	{
		ft_free((void **)&line);
		while (get_next_line(fd, &line))
			ft_map_to_list_ut(line, all, 2);
		ft_map_to_list_ut(line, all, 2);
	}
	else
		ft_lstadd_back(head, ft_lstnew(ft_strdup(line)));
	ft_map_to_list_ut(line, all, 1);
	ft_free((void **)&line);
}

char	**ft_read_map(const char *argv_1, t_all *all, int flag)
{
	char	*line;
	int		fd;
	t_list	*head;

	line = NULL;
	head = NULL;
	flag = 0;
	fd = open(argv_1, O_RDONLY);
	if (fd < 0)
		ft_error((void **)&all, 'a');
	while (get_next_line(fd, &line))
	{
		flag = parser(line, all);
		if (flag == 1)
			break ;
		ft_free((void **)&line);
	}
	if (flag == 1)
	{
		ft_map_to_list(line, &head, fd, all);
		all->pars.map++;
	}
	close(fd);
	ft_free((void **)&line);
	return (ft_make_map(&head, ft_lstsize(head)));
}

int		ft_map_one(t_all *all)
{
	int x;
	int y;

	x = 0;
	while (all->map[x] != NULL)
	{
		y = 0;
		while (all->map[x][y] != '\0')
		{
			if (all->map[x][y] == ' ')
				all->map[x][y] = '1';
			y++;
		}
		if (ft_strlen(all->map[x]) < all->max_map_l)
		{
			all->map[x] = ft_strjoin_map(all->map[x], '1',
			all->max_map_l - ft_strlen(all->map[x]));
		}
		x++;
	}
	return (1);
}
