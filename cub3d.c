#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

void	main_two(t_all *all)
{
	pars_errors(all);
	ft_map_one(all);
	win_init(all);
	find_plr_start(all);
}

void	ft_start(int argc, char **argv, t_all *all)
{
	if (argc < 2 || check_cub_ext(argv[1]) == 0)
		ft_error((void **)&all, 'a');
	if (argc > 2)
	{
		if (argc == 3 && ft_strncmp("--save", argv[2], 6) == 0 &&
			ft_strncmp("--save", argv[2], ft_strlen(argv[2])) == 0)
			all->save_flag = 1;
		else
			ft_error((void **)&all, 'a');
	}
}

int		main(int argc, char **argv)
{
	t_all	all;

	ft_bzero(&all, sizeof(all));
	ft_start(argc, argv, &all);
	if (argc == 2 || all.save_flag == 1)
		all.map = ft_read_map(argv[1], &all, 0);
	else
		ft_error((void **)&all, 'm');
	main_two(&all);
	draw_wall(&all);
	if (all.save_flag == 1)
	{
		save_screenshot(&all);
		red_cross();
	}
	mlx_put_image_to_window(all.win.mlx, all.win.win, all.win.img, 0, 0);
	mlx_do_sync(all.win.mlx);
	mlx_hook(all.win.win, 2, (1L << 0), &key_press, &all);
	mlx_hook(all.win.win, 17, (1L << 0), &red_cross, &all);
	mlx_loop(all.win.mlx);
	return (0);
}
