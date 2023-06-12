/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2023/06/12 10:14:15 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv)
{	
	t_game	game;
	int		error_code;

	if (check_arg_error(argc) == ERROR)
		return (0);
	initialize_struct(&game);
	fill_struct(&game, argv[1]);
	error_code = check_map(argc, argv[1], &game);
	if (error_code != SUCCESS)
	{	
		put_error(error_code);
		return (0);
	}
	run_game(&game);
	return (0);
}
