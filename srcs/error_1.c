/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:06:02 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/12 10:17:56 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	put_no_arg_error(void)
{
	ft_putstr_fd("No map given.\n", 2);
}

void	put_arg_error(void)
{
	ft_putstr_fd("Only one map allowed.\n", 2);
}

void	put_ext_error(void)
{
	ft_putstr_fd("Wrong file extension.\n", 2);
}

void	put_exit_error(void)
{
	ft_putstr_fd("One exit required.\n", 2);
}

void	put_pos_error(void)
{
	ft_putstr_fd("One initial position required.\n", 2);
}
