/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:42:13 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 08:50:15 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/so_long.h"
#include <mlx.h>
#include <stdlib.h>

void	check_move(t_game *game, int direction)
{	
	if (move_is_valid(game, direction) == 0)
	{	
		ft_printf("Blocked!\n");
		return ;
	}
	if (direction == UP)
		move_up(game);
	else if (direction == DOWN)
		move_down(game);
	else if (direction == LEFT)
		move_left(game);
	else if (direction == RIGHT)
		move_right(game);
	find_coin(game);
	game->moves++;
	ft_printf("Total moves: %d\n", game->moves);
}

void	move_up(t_game *game)
{	
	if (game->map[game->row_pos - 1][game->col_pos]
		== 'E' && game->coins == 0)
		move_to_open_door(game, game->col_pos, game->row_pos - 1);
	else if (game->map[game->row_pos - 1][game->col_pos] == 'E')
		move_to_door(game, game->col_pos, game->row_pos - 1);
	else if (game->map[game->row_pos][game->col_pos] == 'E')
	{
		move_player(game, (game->col_pos) * PIXEL,
			(game->row_pos - 1) * PIXEL);
		put_door(game, (game->col_pos) * PIXEL,
			(game->row_pos) * PIXEL);
	}
	else
	{
		move_player(game, (game->col_pos) * PIXEL,
			(game->row_pos - 1) * PIXEL);
		put_tiles(game, (game->col_pos) * PIXEL,
			(game->row_pos) * PIXEL);
	}
	game->row_pos--;
}

void	move_down(t_game *game)
{		
	if (game->map[game->row_pos + 1][game->col_pos]
		== 'E' && game->coins == 0)
		move_to_open_door(game, game->col_pos, game->row_pos + 1);
	else if (game->map[game->row_pos + 1][game->col_pos] == 'E')
		move_to_door(game, game->col_pos, game->row_pos + 1);
	else if (game->map[game->row_pos][game->col_pos] == 'E')
	{
		move_player(game, (game->col_pos) * PIXEL,
			(game->row_pos + 1) * PIXEL);
		put_door(game, (game->col_pos) * PIXEL,
			(game->row_pos) * PIXEL);
	}
	else
	{
		move_player(game, (game->col_pos) * PIXEL,
			(game->row_pos + 1) * PIXEL);
		put_tiles(game, (game->col_pos) * PIXEL,
			(game->row_pos) * PIXEL);
	}
	game->row_pos++;
}

void	move_left(t_game *game)
{	
	if (game->map[game->row_pos][game->col_pos - 1]
		== 'E' && game->coins == 0)
		move_to_open_door(game, game->col_pos - 1, game->row_pos);
	else if (game->map[game->row_pos][game->col_pos - 1] == 'E')
		move_to_door(game, game->col_pos - 1, game->row_pos);
	else if (game->map[game->row_pos][game->col_pos] == 'E')
	{
		move_player(game, (game->col_pos - 1) * PIXEL,
			(game->row_pos) * PIXEL);
		put_door(game, (game->col_pos) * PIXEL,
			(game->row_pos) * PIXEL);
	}
	else
	{
		move_player(game, (game->col_pos - 1) * PIXEL,
			(game->row_pos) * PIXEL);
		put_tiles(game, (game->col_pos) * PIXEL,
			(game->row_pos) * PIXEL);
	}
	game->col_pos--;
}

void	move_right(t_game *game)
{		
	if (game->map[game->row_pos][game->col_pos + 1]
		== 'E' && game->coins == 0)
		move_to_open_door(game, game->col_pos + 1, game->row_pos);
	else if (game->map[game->row_pos][game->col_pos + 1] == 'E')
		move_to_door(game, game->col_pos + 1, game->row_pos);
	else if (game->map[game->row_pos][game->col_pos] == 'E')
	{
		move_player(game, (game->col_pos + 1) * PIXEL,
			(game->row_pos) * PIXEL);
		put_door(game, (game->col_pos) * PIXEL,
			(game->row_pos) * PIXEL);
	}
	else
	{
		move_player(game, (game->col_pos + 1) * PIXEL,
			(game->row_pos) * PIXEL);
		put_tiles(game, (game->col_pos) * PIXEL,
			(game->row_pos) * PIXEL);
	}
	game->col_pos++;
}
