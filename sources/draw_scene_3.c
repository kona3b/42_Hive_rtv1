/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:38:29 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 10:59:30 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw_scene_3(t_mlx *mlx)
{
	t_world		world;
	t_camera	cam;
	int			i;

	i = 0;
	world.objects[i] = plane();
	world.objects[i].material.spec = 0;
	world.objects[i].material.color = color(1, 0.9f, 0.9f);
	i++;
	world.objects[i] = cone();
	world.objects[i].material.color = color(0.9f, 0.1f, 0.2f);
	world.objects[i].material.spec = 0;
	world.count = i + 1;
	world.light = point_light(point(-10, 2, -10), color(1, 1, 1));
	cam = camera(WIN_W, WIN_H, ((float)M_PI / 2.0f));
	cam.transform = view_transform(point(0, 1.5f, -5), point(0, 1, 0),
			vector(0, 1, 0));
	render(mlx, cam, world);
}
