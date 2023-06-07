/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2023/06/07 12:07:59 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "inc/so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv)
{	
	t_game game;
		
	initialize_struct(&game);
	fill_struct(&game, argv[1]);
	if (check_map(argc, argv[1], &game) == ERROR)
	{	
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	run_game(&game);
}