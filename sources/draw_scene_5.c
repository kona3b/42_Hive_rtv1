/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:38:29 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:07:59 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw_scene_5(t_mlx *mlx)
{
	t_world		world;
	t_camera	cam;
	int			i;

	i = 0;
	world.objects[i] = plane();
	world.objects[i].material.spec = 0;
	world.objects[++i] = plane();
	world.objects[i].transform = matrix_multiply(translation(0, 0, 50),
			rotation_x((float)M_PI_2));
	world.objects[i].material.spec = 0;
	world.objects[++i] = sphere();
	world.objects[i].transform = translation(0.5f, 1, 0.5f);
	world.objects[i].material.color = color(0.1f, 1, 0.5f);
	world.objects[i].material.spec = 0.3f;
	world.objects[++i] = cylinder();
	world.objects[i].material.color = color(0.54f, 0.76f, 0.8f);
	world.objects[i].transform = matrix_multiply(translation(-1.75f, 0, -1.75f),
			scaling(0.35f, 0.35f, 0.35f));
	world.count = i + 1;
	world.light = point_light(point(-10, 10, -10), color(1, 1, 1));
	cam = camera(WIN_W, WIN_H, ((float)M_PI / 2.0f));
	cam.transform = view_transform(point(0, 1.5f, -5), point(0, 1, 0),
			vector(0, 1, 0));
	render(mlx, cam, world);
}
