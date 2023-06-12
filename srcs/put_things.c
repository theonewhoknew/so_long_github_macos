/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:57:09 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 10:19:01 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <mlx.h>

void	put_walls(t_game *game, int col_px, int row_px)
{	
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img->wall, col_px, row_px);
}

void	put_tiles(t_game *game, int col_px, int row_px)
{	
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img->tile, col_px, row_px);
}

void	put_coins(t_game *game, int col_px, int row_px)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img->coin, col_px, row_px);
}

void	put_player_or_exit(t_game *game, int col_px, int row_px, char c)
{	
	if (c == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img->player, col_px, row_px);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img->door, col_px, row_px);
}
