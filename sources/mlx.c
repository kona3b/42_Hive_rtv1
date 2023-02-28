/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:58:58 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:54:30 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	if (mlx->img.img == NULL || mlx->img.addr == NULL)
		exit_message(EXIT_MLX_3, EXIT_ERROR);
	if (mlx->scene == 1)
		draw_scene_1(mlx);
	if (mlx->scene == 2)
		draw_scene_2(mlx);
	if (mlx->scene == 3)
		draw_scene_3(mlx);
	if (mlx->scene == 4)
		draw_scene_4(mlx);
	if (mlx->scene == 5)
		draw_scene_5(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
}

int	key_event(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == ESC_KEY)
		exit_message(EXIT_ESC, EXIT_SUCCESS);
	return (0);
}

int	expose_handler(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

void	hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_KEYDOWN, 0, key_event, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, exit_success, mlx);
	mlx_expose_hook(mlx->win, expose_handler, mlx);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit_message(EXIT_MLX_1, EXIT_ERROR);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, WIN_N);
	if (mlx->win == NULL)
		exit_message(EXIT_MLX_2, EXIT_ERROR);
	mlx_do_key_autorepeaton(mlx);
}
