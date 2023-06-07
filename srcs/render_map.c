#include "libft/libft.h"
#include "inc/so_long.h"
#include <mlx.h>

void put_walls(t_game *game, int col_px, int row_px)
{	
	game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm", &(game->width), &(game->height));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, col_px, row_px);
}

void put_tiles(t_game *game, int col_px, int row_px)
{
	game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/tile.xpm", &(game->width), &(game->height));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, col_px, row_px);
}

void put_coins(t_game *game, int col_px, int row_px)
{
	game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/coin.xpm", &(game->width), &(game->height));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, col_px, row_px);;
}

void put_player_or_exit(t_game *game, int col_px, int row_px, char c)
{	
	if (c == 'P')
		game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/character.xpm", &(game->width), &(game->height));
	else
		game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/door.xpm", &(game->width), &(game->height));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, col_px, row_px);
}

void render_map(t_game *game, int x, int y)
{	
	int col_px;
	int row_px;

	col_px = 0;
	row_px = 0;
	while (y < game->row)
	{	
		while (x < game->col)
		{	
			if(game->map[y][x] == '1')
				put_walls(game, col_px, row_px);
			else if(game->map[y][x] == '0')
				put_tiles(game, col_px, row_px);
			else if(game->map[y][x] == 'C')
				put_coins(game, col_px, row_px);
			else 
				put_player_or_exit(game, col_px, row_px, game->map[y][x]);
			col_px += 50;
			x++;
		}
		col_px = 0;
		x = 0;
		row_px += 50;
		y++;
	}
}