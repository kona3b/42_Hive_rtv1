/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_and_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:35:45 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:54:41 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix	orientation;
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;

	forward = normalize(subtract(to, from));
	left = normalize(cross(forward, normalize(up)));
	true_up = cross(left, forward);
	orientation = (t_matrix){
		.r0.c0 = left.x, .r0.c1 = left.y, .r0.c2 = left.z, .r0.c3 = 0.0f,
		.r1.c0 = true_up.x, .r1.c1 = true_up.y, .r1.c2 = true_up.z,
		.r1.c3 = 0.0f, .r2.c0 = -forward.x, .r2.c1 = -forward.y,
		.r2.c2 = -forward.z, .r2.c3 = 0.0f, .r3.c0 = 0.0f, .r3.c1 = 0.0f,
		.r3.c2 = 0.0f, .r3.c3 = 1.0f, .size = 4};
	return (matrix_multiply(orientation,
			translation(-from.x, -from.y, -from.z)));
}

t_camera	camera(float hsize, float vsize, float fov)
{
	t_camera	res;
	float		half_view;
	float		aspect;

	res.hsize = hsize;
	res.vsize = vsize;
	res.fov = fov;
	res.transform = indentity_matrix();
	half_view = (float)tan(res.fov / 2);
	aspect = res.hsize / res.vsize;
	if (aspect >= 1)
	{
		res.half_width = half_view;
		res.half_height = half_view / aspect;
	}
	else
	{
		res.half_width = half_view * aspect;
		res.half_height = half_view;
	}
	res.pixel_size = (res.half_width * 2) / res.hsize;
	return (res);
}

t_ray	ray_for_pixel(t_camera cam, float x, float y)
{
	t_rays	r;

	r.offset_x = (x + 0.5f) * cam.pixel_size;
	r.offset_y = (y + 0.5f) * cam.pixel_size;
	r.world_x = cam.half_width - r.offset_x;
	r.world_y = cam.half_height - r.offset_y;
	r.pixel = tuple_matrix_multiply(inverse(cam.transform),
			point(r.world_x, r.world_y, -1));
	r.origin = tuple_matrix_multiply(inverse(cam.transform),
			point(0, 0, 0));
	r.direction = normalize(subtract(r.pixel, r.origin));
	return (ray(r.origin, r.direction));
}

void	render(t_mlx *mlx, t_camera camera, t_world world)
{
	int	y;
	int	x;

	y = 0;
	while (y < camera.vsize - 1)
	{
		x = 0;
		while (x < camera.hsize - 1)
		{
			my_mlx_pixel_put(&mlx->img, x, y,
				color_int(color_at(world, ray_for_pixel(camera, x, y))));
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = (unsigned int)color;
}
