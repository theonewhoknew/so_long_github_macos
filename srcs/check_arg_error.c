/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_Error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:21:14 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 10:21:19 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_arg_error(int argc)
{
	if (argc == 1)
	{
		put_no_arg_error();
		return (ERROR);
	}
	else if (argc > 2)
	{
		put_arg_error();
		return (ERROR);
	}
	return (SUCCESS);
}
