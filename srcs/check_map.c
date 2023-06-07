#include "libft/libft.h"
#include "inc/so_long.h"

int check_extension(char *path)
{
	int len;
	char *ptr;

	len = ft_strlen(path);
	ptr = &path[len - 4];
	if (ft_strnstr(ptr, ".ber", 4) == NULL)
		return (ERROR);
	else 
		return (SUCCESS);
}

int check_chars(t_game *map, const char *charset)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while (map->map[i] != NULL)
	{	
		while (map->map[i][j] != '\0')
		{
			while (charset[k] != '\0')
			{
				if (map->map[i][j] == charset[k])
					break ;
				k++;
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

int check_rectangle(t_game *map)
{
	int i;

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

int check_map(int argc, char *path,  t_game *map)
{	
	if (argc != 2)
		return (ERROR);
	if (check_extension(path) == ERROR)
		return (ERROR);
	if (map->exit != 1 && map->position != 1)
		return (ERROR);
	if (map->coins < 1)
		return (ERROR);
	if (check_chars(map, "01CEP") == ERROR)
		return (ERROR);
	if (check_rectangle(map) == ERROR)
		return (ERROR);
	if (check_walls(map) == ERROR)
		return (ERROR);
	if (check_path(map) == ERROR)
		return (ERROR);
	return (SUCCESS);
}