/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:28 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 13:08:25 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>
#include <mlx.h>

void	free_visited(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->row)
	{
		free(game->visited[x]);
		x++;
	}
	free(game->visited);
}

void	free_map(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->row)
	{
		free(game->map[x]);
		x++;
	}
	free(game->map);
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img->wall);
	mlx_destroy_image(game->mlx_ptr, game->img->tile);
	mlx_destroy_image(game->mlx_ptr, game->img->door);
	mlx_destroy_image(game->mlx_ptr, game->img->coin);
	mlx_destroy_image(game->mlx_ptr, game->img->player);
	mlx_destroy_image(game->mlx_ptr, game->img->player_at_door);
	mlx_destroy_image(game->mlx_ptr, game->img->player_at_open_door);
	free(game->img);
}

void	free_struct(t_game *game)
{
	free_visited(game);
	free_map(game);
	free_images(game);
}
