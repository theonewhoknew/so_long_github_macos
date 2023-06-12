/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounce_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:05:09 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/09 11:06:34 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	count_lines(char *path)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	i++;
	while (line != NULL)
	{	
		free (line);
		line = NULL;
		line = get_next_line(fd);
		i++;
	}
	free (line);
	line = NULL;
	close(fd);
	return (i);
}

void	bounce_map(t_game *map, char *path)
{
	int		i;
	char	*line;
	int		fd;

	map->map = malloc(sizeof (char *) * (count_lines(path) + 1));
	fd = open(path, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{	
		if (line[ft_strlen(line) - 1] == '\n')
		{	
			map->map[i] = malloc(sizeof (char) * (ft_strlen(line)));
			ft_strlcpy(map->map[i++], line, (ft_strlen(line)));
		}
		else
		{
			map->map[i] = malloc(sizeof (char) * (ft_strlen(line)) + 1);
			ft_strlcpy(map->map[i++], line, (ft_strlen(line)) + 1);
		}
		free (line);
		line = NULL;
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
}
