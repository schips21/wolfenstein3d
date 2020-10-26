#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define SCALE 64

typedef struct			s_list_spr
{
	int					x;
	int					y;
	double				dist_spr_plr;
	struct s_list_spr	*next;
}						t_list_spr;

typedef struct			s_pars
{
	int					r;
	int					no;
	int					so;
	int					we;
	int					ea;
	int					s;
	int					f;
	int					c;
	int					map;
}						t_pars;

typedef struct			s_win
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					line_l;
	int					bpp;
	int					en;
	int					width;
	int					height;
}						t_win;

typedef struct			s_point
{
	int					x;
	int					y;
	int					x_const;
	double				dist;
	int					offset_x;
	int					offset_y;
}						t_point;

typedef struct			s_two_point
{
	t_point				spr;
	t_point				spr_size;
}						t_two_point;

typedef struct			s_plr
{
	double				x;
	double				y;
	double				dir;
	double				start;
	double				end;
}						t_plr;

typedef struct			s_two_plr
{
	t_plr				plr;
	t_plr				cur;
}						t_two_plr;

typedef struct			s_text
{
	void				*img;
	char				*addr;
	int					line_l;
	int					bpp;
	int					en;
	int					width;
	int					height;
	char				*path;
}						t_text;

typedef struct			s_all_text
{
	t_text				text_n;
	t_text				text_s;
	t_text				text_w;
	t_text				text_e;
	t_text				text_spr;
	unsigned			ceiling_col;
	unsigned			floor_col;
}						t_all_text;

typedef struct			s_all
{
	t_win				win;
	t_plr				plr;
	char				**map;
	t_all_text			all_text;
	t_list_spr			*spr_coord;
	t_pars				pars;
	int					save_flag;
	int					max_map_l;
}						t_all;

void					ft_swap_spr(t_list_spr **head, t_list_spr *tmp_sort);
void					sort_sprite(t_all *all, int t);
void					ft_dist_to_spr(t_all *all);
void					draw_sprite_bef_draw(t_all *all, t_list_spr *tmp,
						t_two_point *sprs);
void					draw_sprite_while(t_all *all, t_two_point *s,
						int *i, double *all_dist);
void					draw_sprite_new(t_all *all, const double *all_dist);
char					wall_side(t_all *all, t_plr *cur, t_plr *pre);
int						dr_w_if(t_two_plr *p, t_all *all);
void					draw_wall_while(t_two_plr *p, t_all *all,
						double **all_dist, int x_cur);
void					draw_wall(t_all *all);
void					draw_w_n(t_plr *cur, t_all *all, t_point *st_end,
						int x_cur);
void					draw_w_s(t_plr *cur, t_all *all, t_point *st_end,
						int x_cur);
void					draw_w_w(t_plr *cur, t_all *all, t_point *st_end,
						int x_cur);
void					draw_w_e(t_plr *cur, t_all *all, t_point *st_end,
						int x_cur);
void					draw_w(t_all *all, int x_cur, t_plr *cur, char side);
void					key_press_extra(int key, t_all *all);
void					key_press_extra_2(int key, t_all *all);
int						key_press(int key, t_all *all);
t_list_spr				*ft_lstnew_spr(int x, int y);
t_list_spr				*ft_lstlast_spr(t_list_spr *lst);
void					ft_lstadd_back_spr(t_list_spr **lst, t_list_spr *new);
void					parse_resol(char *line, t_all *all);
void					parse_col_ind(char *n, int *j, int *k, int *e);
void					parse_col(char *line, char cf, t_all *all);
void					check_numb(char *line, t_all *all);
void					parse_text_extra(t_all *all, char text);
void					parse_text(char *line, char text, t_all *all);
void					check_text(char *line, t_all *all);
int						map_valid_if(char **m, int x, int y, int map_len);
int						map_valid(char **m, int map_len);
void					ft_free(void **s);
void					ft_error(void **to_free, char er);
int						parser(char *line, t_all *all);
char					**ft_make_map(t_list **head, int size);
void					ft_map_to_list(char *line, t_list **head,
						int fd, t_all *all);
char					**ft_read_map(const char *argv_1, t_all *all, int flag);
int						ft_map_one(t_all *all);
void					find_plr_start_pos(t_all *all, t_point *p);
void					find_plr_start(t_all *all);
int						get_color(t_all *all, int x, int y);
void					int_to_char(int n, unsigned char *src);
void					pixels(t_all *all, int fd);
void					header_bmp(t_all *all, int fd, int filesize);
int						save_screenshot(t_all *all);
void					my_mlx_pixel_put(t_win *data, int x,
						int y, unsigned color);
int						red_cross(void);
void					pars_errors(t_all *all);
int						check_cub_ext(char *name);
void					text_init_two(t_all *all);
void					text_init(t_all *all);
void					win_init(t_all *all);
void					ft_map_to_list_ut(char *line, t_all *all, int var);
char					*ft_strjoin_map(char *s1, char c, int n);

#endif
