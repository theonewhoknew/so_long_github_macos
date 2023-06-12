/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:37:39 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 13:03:16 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	reset(t_game *game)
{	
	free_map(game);
	bounce_map(game, game->path);
	get_coins(game);
	get_exit(game);
	get_position(game);
	get_pos_coord(game);
	render_map(game, 0, 0);
	game->victory = 0;
	game->moves = 0;
	ft_printf("Go!\n");
}
