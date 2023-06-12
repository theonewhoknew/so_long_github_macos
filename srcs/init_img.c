/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:01:14 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/09 13:53:09 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <mlx.h>
#include <stdlib.h>

void	init_img(t_game *game)
{
	game->img = malloc(sizeof (t_img));
	game->img->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/red_wall.xpm", &(game->width), &(game->height));
	game->img->coin = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/coin.xpm", &(game->width), &(game->height));
	game->img->tile = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/tile.xpm", &(game->width), &(game->height));
	game->img->door = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/door.xpm", &(game->width), &(game->height));
	game->img->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player.xpm", &(game->width), &(game->height));
	game->img->player_at_door = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player_at_door.xpm", &(game->width), &(game->height));
	game->img->player_at_open_door = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player_at_open_door.xpm",
			&(game->width), &(game->height));
}
