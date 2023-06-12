/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:33:14 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 08:45:17 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	move_is_valid(t_game *game, int direction)
{
	if (direction == UP)
	{
		if (game->map[game->row_pos - 1][game->col_pos] == '1')
			return (0);
	}
	else if (direction == DOWN)
	{
		if (game->map[game->row_pos + 1][game->col_pos] == '1')
			return (0);
	}
	else if (direction == LEFT)
	{
		if (game->map[game->row_pos][game->col_pos - 1] == '1')
			return (0);
	}
	else if (direction == RIGHT)
	{	
		if (game->map[game->row_pos][game->col_pos + 1] == '1')
			return (0);
	}
	return (1);
}
