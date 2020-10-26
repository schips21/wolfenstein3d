#include "libft/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

int		get_color(t_all *all, int x, int y)
{
	char	*dst;
	int		color;

	dst = all->win.addr + (y * all->win.line_l + x * (all->win.bpp / 8));
	color = *(int*)dst;
	return (color);
}

void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

void	pixels(t_all *all, int fd)
{
	int		i;
	int		j;
	int		color;

	i = all->win.height - 1;
	while (0 <= i)
	{
		j = 0;
		while (j < all->win.width)
		{
			color = get_color(all, j, i);
			write(fd, &color, 4);
			j++;
		}
		i--;
	}
}

void	header_bmp(t_all *all, int fd, int filesize)
{
	unsigned	char	arr[54];
	int					count;

	count = 0;
	while (count < 54)
		arr[count++] = 0;
	arr[0] = 'B';
	arr[1] = 'M';
	int_to_char(filesize, &arr[2]);
	arr[10] = (unsigned char)(54);
	arr[14] = (unsigned char)(40);
	int_to_char(all->win.width, &arr[18]);
	int_to_char(all->win.height, &arr[22]);
	arr[26] = (unsigned char)(1);
	arr[28] = (unsigned char)(32);
	write(fd, arr, 54);
}

int		save_screenshot(t_all *all)
{
	int		fd;
	int		filesize;

	filesize = ((all->win.height * all->win.width) * 4) + 54;
	if (((fd = open("screenshot.bmp", O_WRONLY | O_CREAT |
	O_TRUNC | O_APPEND, 0666))) < 0)
		return (0);
	header_bmp(all, fd, filesize);
	pixels(all, fd);
	close(fd);
	return (1);
}
