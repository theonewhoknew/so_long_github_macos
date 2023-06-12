/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:03:56 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/09 12:05:44 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	get_row_col(t_game *map)
{
	int	row;

	row = 0;
	while (map->map[row] != NULL)
		row++;
	map->row = row;
	map->col = ft_strlen(map->map[0]);
}

void	get_coins(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'C')
				map->coins++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_exit(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'E')
				map->exit++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_position(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
				map->position++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_pos_coord(t_game *map)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[y] != NULL)
	{
		while (map->map[y][x] != '\0')
		{
			if (map->map[y][x] == 'P')
			{
				map->col_pos = x;
				map->row_pos = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
