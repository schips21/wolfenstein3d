#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

void	text_init_two(t_all *all)
{
	all->all_text.text_w.img = mlx_xpm_file_to_image(all->win.mlx,
	all->all_text.text_w.path, &all->all_text.text_w.width,
	&(all->all_text.text_w.height));
	if (all->all_text.text_w.img == NULL)
		ft_error((void **)all, 't');
	all->all_text.text_w.addr = mlx_get_data_addr(all->all_text.text_w.img,
	&all->all_text.text_w.bpp, &all->all_text.text_w.line_l,
	&all->all_text.text_w.en);
	all->all_text.text_e.img = mlx_xpm_file_to_image(all->win.mlx,
	all->all_text.text_e.path, &all->all_text.text_e.width,
	&(all->all_text.text_e.height));
	if (all->all_text.text_e.img == NULL)
		ft_error((void **)all, 't');
	all->all_text.text_e.addr = mlx_get_data_addr(all->all_text.text_e.img,
	&all->all_text.text_e.bpp, &all->all_text.text_e.line_l,
	&all->all_text.text_e.en);
	all->all_text.text_spr.img = mlx_xpm_file_to_image(all->win.mlx,
	all->all_text.text_spr.path, &all->all_text.text_spr.width,
	&(all->all_text.text_spr.height));
	if (all->all_text.text_spr.img == NULL)
		ft_error((void **)all, 't');
	all->all_text.text_spr.addr = mlx_get_data_addr(all->all_text.text_spr.img,
	&all->all_text.text_spr.bpp, &all->all_text.text_spr.line_l,
	&all->all_text.text_spr.en);
}

void	text_init(t_all *all)
{
	all->all_text.text_n.img = mlx_xpm_file_to_image(all->win.mlx,
	all->all_text.text_n.path, &all->all_text.text_n.width,
	&(all->all_text.text_n.height));
	if (all->all_text.text_n.img == NULL)
		ft_error((void **)all, 't');
	all->all_text.text_n.addr = mlx_get_data_addr(all->all_text.text_n.img,
	&all->all_text.text_n.bpp, &all->all_text.text_n.line_l,
	&all->all_text.text_n.en);
	all->all_text.text_s.img = mlx_xpm_file_to_image(all->win.mlx,
	all->all_text.text_s.path, &all->all_text.text_s.width,
	&(all->all_text.text_s.height));
	if (all->all_text.text_s.img == NULL)
		ft_error((void **)all, 't');
	all->all_text.text_s.addr = mlx_get_data_addr(all->all_text.text_s.img,
	&all->all_text.text_s.bpp, &all->all_text.text_s.line_l,
	&all->all_text.text_s.en);
	text_init_two(all);
}

void	win_init(t_all *all)
{
	all->win.mlx = NULL;
	all->win.win = NULL;
	all->win.mlx = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx, all->win.width,
	all->win.height, "cub3D");
	all->win.img = mlx_new_image(all->win.mlx, all->win.width,
	all->win.height);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bpp,
	&all->win.line_l, &all->win.en);
	text_init(all);
}
