/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:07:56 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 13:03:32 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 400
# define MLX_ERROR 1
# define ERROR -1
# define SUCCESS 0
# define W 13
# define A 0
# define S 1
# define D 2
# define R 15
# define ESC 53
# define PIXEL 80
# define UP	1
# define RIGHT	2
# define DOWN	3
# define LEFT	4
# define NO_ARG_ERROR 9
# define ARG_ERROR 10
# define EXT_ERROR 11
# define EXIT_ERROR 12
# define POS_ERROR 13
# define COIN_ERROR 14
# define CHAR_ERROR 15
# define RECT_ERROR 16
# define WALL_ERROR 17
# define PATH_ERROR 18

typedef struct s_img
{
	void	*wall;	
	void	*tile;
	void	*coin;
	void	*door;
	void	*player;
	void	*player_at_door;
	void	*player_at_open_door;
}				t_img;

typedef struct s_game
{	
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	char	**map;
	char	**visited;
	char	*path;
	char	*relative_path;
	int		width;
	int		height;
	int		col;
	int		row;
	int		exit;
	int		path_exit;
	int		coins;
	int		path_coins;
	int		position;
	int		row_pos;
	int		col_pos;
	int		moves;
	int		victory;
}				t_game;

void	bounce_map(t_game *map, char *path);
void	fill_struct(t_game *map, char *path);
void	initialize_struct(t_game *map);
void	get_row_col(t_game *map);
void	get_coins(t_game *map);
void	get_exit(t_game *map);
void	get_position(t_game *map);
int		check_extension(char *path);
int		check_map(int argc, char *path, t_game *map);
int		check_walls(t_game *map);
void	get_pos_coord(t_game *map);
int		check_path(t_game *map);
void	run_game(t_game *map);
void	render_map(t_game *game, int x, int y);
void	put_tiles(t_game *game, int col_px, int row_px);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_to_door(t_game *game, int col_pos, int row_pos);
void	move_to_open_door(t_game *game, int col_pos, int row_pos);
void	put_door(t_game *game, int col_pos, int row_pos);
void	find_coin(t_game *game);
void	reset(t_game *game);
void	free_struct(t_game *game);
void	init_img(t_game *game);
void	check_move(t_game *game, int direction);
void	end_game(t_game *game);
void	move_player(t_game *game, int col_px, int row_px);
void	put_walls(t_game *game, int col_px, int row_px);
void	put_tiles(t_game *game, int col_px, int row_px);
void	put_coins(t_game *game, int col_px, int row_px);
void	put_player_or_exit(t_game *game, int col_px, int row_px, char c);
int		move_is_valid(t_game *game, int direction);
void	print_map(t_game *game);
void	put_error(int code);
void	put_no_arg_error(void);
void	put_arg_error(void);
void	put_ext_error(void);
void	put_exit_error(void);
void	put_pos_error(void);
void	put_coin_error(void);
void	put_char_error(void);
void	put_rect_error(void);
void	put_wall_error(void);
void	put_path_error(void);
int		check_arg_error(int argc);
void	free_map(t_game *game);

#endif