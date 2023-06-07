#include "inc/so_long.h"

int check_first_bottom(t_game *map)
{
	int i;

	i = 0;
	while (map->map[0][i] != '\0')
	{
		if (map->map[0][i] != '1')
			return (ERROR);
		i++;
	}
	i = 0;
	while (map->map[map->row - 1][i] != '\0')
	{
		if (map->map[map->row - 1][i] != '1')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int check_others(t_game *map)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < map->row - 1)
	{
		if (map->map[i][j] != '1')
			return (ERROR);
		i++;
	}
	i = 1;
	j = ft_strlen(map->map[0]) - 1;
	while (i < map->row - 1)
	{
		if (map->map[i][j] != '1')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int check_walls(t_game *map)
{	
	
	if (check_first_bottom(map) == ERROR)
		return (ERROR);
	if (check_others(map) == ERROR)
		return (ERROR);
	return (SUCCESS);
}