/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:38:29 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 12:43:18 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw_scene_2(t_mlx *mlx)
{
	t_world		world;
	t_camera	cam;
	int			i;

	i = 0;
	world.objects[i] = cylinder();
	world.objects[i].material.color = color(0.1f, 0.2f, 0.9f);
	world.objects[i].material.spec = 0;
	world.count = i + 1;
	world.light = point_light(point(4, 0, -10), color(1, 1, 1));
	cam = camera(WIN_W, WIN_H, ((float)M_PI / 2.0f));
	cam.transform = view_transform(point(0, 1.5f, -5), point(0, 1, 0),
			vector(0, 1, 0));
	render(mlx, cam, world);
}
