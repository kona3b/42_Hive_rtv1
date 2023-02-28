/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:16:26 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 04:21:02 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_message(const char *msg, int v)
{
	ft_putstr(msg);
	exit(v);
}

int	exit_success(void)
{
	exit_message(EXIT_WINDOW, EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	static t_mlx	mlx;
	int				scene;

	scene = ft_atoi(argv[1]);
	if (argc != 2 || ft_strlen(argv[1]) != 1 || scene < 1 || scene > 5)
		exit_message(EXIT_USAGE, EXIT_ERROR);
	mlx.scene = scene;
	init_mlx(&mlx);
	hooks(&mlx);
	draw(&mlx);
	mlx_loop(&mlx);
	return (0);
}
