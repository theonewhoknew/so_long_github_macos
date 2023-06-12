/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:05:46 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 10:19:20 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_error(int code)
{	
	if (code == EXT_ERROR)
		put_ext_error();
	else if (code == EXIT_ERROR)
		put_exit_error();
	else if (code == POS_ERROR)
		put_pos_error();
	else if (code == COIN_ERROR)
		put_coin_error();
	else if (code == CHAR_ERROR)
		put_char_error();
	else if (code == RECT_ERROR)
		put_rect_error();
	else if (code == WALL_ERROR)
		put_wall_error();
	else if (code == PATH_ERROR)
		put_path_error();
}
