#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

void	parse_text_extra(t_all *all, char text)
{
	if (text == 'n')
		all->pars.no++;
	if (text == 's')
		all->pars.so++;
	if (text == 'w')
		all->pars.we++;
	if (text == 'e')
		all->pars.ea++;
	if (text == 'r')
		all->pars.s++;
}

void	parse_text(char *line, char text, t_all *all)
{
	char	*text_path;

	text_path = ft_strtrim(line, " ");
	if (text_path[0] == ' ' || !text_path)
		ft_error((void **)&text_path, 't');
	if (text == 'n')
		all->all_text.text_n.path = ft_strdup(text_path);
	if (text == 's')
		all->all_text.text_s.path = ft_strdup(text_path);
	if (text == 'w')
		all->all_text.text_w.path = ft_strdup(text_path);
	if (text == 'e')
		all->all_text.text_e.path = ft_strdup(text_path);
	if (text == 'r')
		all->all_text.text_spr.path = ft_strdup(text_path);
	parse_text_extra(all, text);
	ft_free((void **)&text_path);
}

void	check_text(char *line, t_all *all)
{
	if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		parse_text(line + 3, 'n', all);
	else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		parse_text(line + 3, 's', all);
	else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		parse_text(line + 3, 'w', all);
	else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		parse_text(line + 3, 'e', all);
	else if (*line == 'S' && *(line + 1) == ' ')
		parse_text(line + 2, 'r', all);
}
