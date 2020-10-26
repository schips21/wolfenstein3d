NAME = cub3D

SRCS = cub3d.c draw_sprite_utils.c draw_sprite.c draw_wall_utils.c draw_wall.c key_press.c \
	list_sprite.c parce_numb.c parce_text.c parcer_utils.c parcer.c player_start.c \
	screen.c utils.c win_init.c

OBJS = $(SRCS:.c=.o)

FLAGS = $(-Wall -Wextra -Werror)

LIBFT = ./libft/libft.a

MLX = ./minilibx_mms/libmlx.dylib

HEADER = cub3d.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@gcc -g -L ./minilibx_mms/ -framework OpenGL -framework AppKit -lmlx -L ./libft/ -lft $(OBJS) -o $(NAME)

$(LIBFT):
	@make -C ./libft/

$(MLX):
	@make -C ./minilibx_mms/
	@cp ./minilibx_mms/libmlx.dylib ./

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -Imlx -c $< -o $@

clean:
	@rm -f *.o
	@make clean -C ./libft/

fclean: clean
	@rm -f $(NAME)
	@rm -f libmlx.dylib
	@rm -f ./minilibx_mms/libmlx.dylib
	@make fclean -C ./libft/

re: fclean all
