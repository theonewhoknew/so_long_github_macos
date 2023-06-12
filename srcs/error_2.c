/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:07:40 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 10:07:58 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	put_coin_error(void)
{
	ft_putstr_fd("At least one coin required.\n", 2);
}

void	put_char_error(void)
{
	ft_putstr_fd("Wrong characters found.\n", 2);
}

void	put_rect_error(void)
{	
	ft_putstr_fd("Map must be a rectangle.\n", 2);
}

void	put_wall_error(void)
{
	ft_putstr_fd("Map must be surrounded by walls.\n", 2);
}

void	put_path_error(void)
{
	ft_putstr_fd("There must be a valid path.\n", 2);
}
