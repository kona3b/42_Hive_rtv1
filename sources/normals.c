/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:27:15 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 03:28:40 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_tuple	normal_at_sphere(t_tuple p)
{
	return (subtract(p, point(0, 0, 0)));
}

static t_tuple	normal_at_plane(t_tuple p)
{
	(void)p;
	return (vector(0, 1, 0));
}

static t_tuple	normal_at_cylinder(t_tuple p)
{
	return (vector(p.x, 0, p.z));
}

static t_tuple	normal_at_cone(t_tuple p)
{
	float	y;

	y = sqrtf(powf(p.x, 2) + sqrtf(powf(p.z, 2)));
	if (y > 0)
		y = -y;
	return (vector(p.x, y, p.z));
}

t_tuple	normal_at(t_object o, t_tuple world_point)
{
	t_tuple	local_point;
	t_tuple	local_normal;
	t_tuple	world_normal;

	local_point = tuple_matrix_multiply(inverse(o.transform), world_point);
	if (o.type == SPHERE)
		local_normal = normal_at_sphere(local_point);
	else if (o.type == PLANE)
		local_normal = normal_at_plane(local_point);
	else if (o.type == CYLINDER)
		local_normal = normal_at_cylinder(local_point);
	else if (o.type == CONE)
		local_normal = normal_at_cone(local_point);
	else
		local_normal = normal_at_sphere(local_point);
	world_normal = tuple_matrix_multiply(matrix_transpose(inverse(o.transform)),
			local_normal);
	world_normal.w = 0.0f;
	return (normalize(world_normal));
}
