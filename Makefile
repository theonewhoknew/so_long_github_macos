NAME = so_long

LIBFT_DIR = libft

LIBFT =  $(LIBFT_DIR)/libft.a

MINI_DIR = mlx

MINI = $(MINI_DIR)/libmlx.a
	
SRCS = $(addprefix srcs/, main.c bounce_map.c struct_init.c get_things.c check_map.c check_walls.c check_path.c render_map.c \
		game.c move.c move_aux.c reset.c free_struct.c init_img.c end_game.c put_things.c move_is_valid.c put_error.c error_1.c error_2.c check_arg_error.c)

OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))

OBJECTS_DIR = objs

INC_DIR = inc

CFLAGS = -Wall -Wextra -Werror  -I $(INC_DIR) 

all: make_libft make_mini $(NAME) 

$(NAME) : $(OBJS) $(INC_DIR)/so_long.h 
	cc $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -L$(LIBFT_DIR) -lft -o $(NAME)

objs/%.o : srcs/%.c $(INC_DIR)/so_long.h libft/libft.h | $(OBJECTS_DIR)
	cc $(CFLAGS) -Imlx -c $< -o $@

$(OBJECTS_DIR) :
	mkdir -p objs

make_libft:
	@make -C $(LIBFT_DIR)

make_mini:
	@make -C $(MINI_DIR)

clean:
	@rm -rf objs
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINI_DIR)

fclean: clean
	@rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean all bonus clean fclean re