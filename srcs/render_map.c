/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:38:15 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 08:46:11 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

void	check_put(t_game *game, char tile, int col_px, int row_px)
{
	if (tile == '1')
		put_walls(game, col_px, row_px);
	else if (tile == '0')
		put_tiles(game, col_px, row_px);
	else if (tile == 'C')
		put_coins(game, col_px, row_px);
	else
		put_player_or_exit(game, col_px, row_px, tile);
}

void	render_map(t_game *game, int x, int y)
{	
	int	col_px;
	int	row_px;

	col_px = 0;
	row_px = 0;
	init_img(game);
	while (y < game->row)
	{	
		while (x < game->col)
		{	
			check_put(game, game->map[y][x], col_px, row_px);
			col_px += PIXEL;
			x++;
		}
		col_px = 0;
		x = 0;
		row_px += PIXEL;
		y++;
	}
}

void	print_map(t_game *game)
{	
	int	i;

	i = 0;
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
}
