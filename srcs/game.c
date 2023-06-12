/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:59:39 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 12:52:34 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int	handle_no_event(void)
{
	return (0);
}

int	red_cross(t_game *game)
{	
	end_game(game);
	return (0);
}

int	key_press(int keycode, t_game *game)
{	
	if (game->victory == 0)
	{	
		if (keycode != ESC)
		{
			if (keycode == W)
				check_move(game, UP);
			else if (keycode == S)
				check_move(game, DOWN);
			else if (keycode == A)
				check_move(game, LEFT);
			else if (keycode == D)
				check_move(game, RIGHT);
		}
		else if (keycode == ESC)
			end_game(game);
		return (0);
	}
	else
	{
		if (keycode == ESC)
			end_game(game);
		else if (keycode == R)
			reset(game);
		return (0);
	}		
}

void	run_game(t_game *game)
{	
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, PIXEL * game->col,
			PIXEL * game->row, "Take the money and run");
	render_map(game, 0, 0);
	ft_printf("Go!\n");
	mlx_hook(game->win_ptr, 2, 0, &key_press, game);
	mlx_hook(game->win_ptr, 17, 0, &red_cross, game);
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_loop(game->mlx_ptr);
	return ;
}
