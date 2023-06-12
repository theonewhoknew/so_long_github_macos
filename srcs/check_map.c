/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:05:02 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 10:07:16 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

int	check_extension(char *path)
{
	int		len;
	char	*ptr;

	len = ft_strlen(path);
	ptr = &path[len - 4];
	if (ft_strnstr(ptr, ".ber", 4) == NULL)
		return (ERROR);
	else
		return (SUCCESS);
}

int	check_chars(t_game *map, const char *charset)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	j = 0;
	while (map->map[i] != NULL)
	{	
		while (map->map[i][j] != '\0')
		{
			while (charset[k] != '\0')
			{
				if (map->map[i][j] == charset[k++])
					break ;
				if (k == (int) ft_strlen(charset))
					return (ERROR);
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (SUCCESS);
}

int	check_rectangle(t_game *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
	{
		if (map->col != (int) ft_strlen(map->map[i]))
			return (ERROR);
		i++;
	}
	if (i != map->row)
		return (ERROR);
	else
		return (SUCCESS);
}

int	check_map(int argc, char *path, t_game *map)
{	
	if (argc == 1)
		return (NO_ARG_ERROR);
	if (argc > 2)
		return (ARG_ERROR);
	if (check_extension(path) == ERROR)
		return (EXT_ERROR);
	if (map->exit != 1)
		return (EXIT_ERROR);
	if (map->position != 1)
		return (POS_ERROR);
	if (map->coins < 1)
		return (COIN_ERROR);
	if (check_chars(map, "01CEP") == ERROR)
		return (CHAR_ERROR);
	if (check_rectangle(map) == ERROR)
		return (RECT_ERROR);
	if (check_walls(map) == ERROR)
		return (WALL_ERROR);
	if (check_path(map) == ERROR)
		return (PATH_ERROR);
	return (SUCCESS);
}
