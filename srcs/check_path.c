/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:03:33 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/09 14:04:49 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	visited_init(t_game *map)
{	
	int	y;
	int	x;

	y = 0;
	if (map->visited == NULL)
	{
		map->visited = malloc(sizeof (char *) * (map->row));
		while (y < map->row)
		{
			map->visited[y] = malloc(sizeof (char) * (map->col));
			y++;
		}
	}
	y = 0;
	x = 0;
	while (y < map->row)
	{	
		while (x < map->col)
		{
			map->visited[y][x] = '0';
			x++;
		}
		x = 0;
		y++;
	}
}

int	is_valid_move(t_game *path_map, int row, int col)
{	
	if (row < 0 || row >= path_map->row || col < 0 || col >= path_map->col)
		return (ERROR);
	if (path_map->map[row][col] == '1')
		return (ERROR);
	else
		return (SUCCESS);
}

void	dfs_coins(t_game *map, int row, int col)
{	
	if (map->path_coins == 0)
		return ;
	if (is_valid_move(map, row, col) == ERROR)
		return ;
	if (map->map[row][col] == 'C')
		map->path_coins--;
	map->visited[row][col] = '1';
	if (map->visited[row - 1][col] == '0')
		dfs_coins(map, row - 1, col);
	if (map->visited[row + 1][col] == '0')
		dfs_coins(map, row + 1, col);
	if (map->visited[row][col + 1] == '0')
		dfs_coins(map, row, col + 1);
	if (map->visited[row][col - 1] == '0')
		dfs_coins(map, row, col - 1);
}

void	dfs_exit(t_game *map, int row, int col)
{	
	if (map->path_exit == SUCCESS)
		return ;
	if (is_valid_move(map, row, col) == ERROR)
		return ;
	if (map->map[row][col] == 'E')
		map->path_exit = SUCCESS;
	map->visited[row][col] = '1';
	if (map->visited[row - 1][col] == '0')
		dfs_exit(map, row - 1, col);
	if (map->visited[row + 1][col] == '0')
		dfs_exit(map, row + 1, col);
	if (map->visited[row][col + 1] == '0')
		dfs_exit(map, row, col + 1);
	if (map->visited[row][col - 1] == '0')
		dfs_exit(map, row, col - 1);
}

int	check_path(t_game *map)
{	
	get_pos_coord(map);
	map->visited = NULL;
	visited_init(map);
	map->path_coins = map->coins;
	dfs_coins(map, map->row_pos, map->col_pos);
	if (map->path_coins > 0)
		return (ERROR);
	visited_init(map);
	map->path_exit = ERROR;
	dfs_exit(map, map->row_pos, map->col_pos);
	if (map->path_exit == ERROR)
		return (ERROR);
	return (SUCCESS);
}
