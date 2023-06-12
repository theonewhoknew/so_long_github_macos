/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:02:31 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 13:10:41 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <mlx.h>
#include <stdlib.h>

void	end_game(t_game *game)
{	
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_struct(game);
	free(game->mlx_ptr);
	exit(1);
}
