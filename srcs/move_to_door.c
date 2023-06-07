#include "libft/libft.h"
#include "inc/so_long.h"
#include <mlx.h>
#include <stdlib.h>

void move_to_door(t_game *game, int col_pos, int row_pos)
{
	if (game->coins == 0)
	{
		game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/character.xpm", &(game->width), &(game->height)); // put image of character and open door
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, col_pos * 50, row_pos * 50);
		ft_printf("You won!\n");
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);	
		exit(1);	}
	else	{
		game->img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/character.xpm", &(game->width), &(game->height)); // put image of character and closed door
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, col_pos * 50, row_pos * 50);
		ft_printf("There are coins remaining!\n");	
	}
}