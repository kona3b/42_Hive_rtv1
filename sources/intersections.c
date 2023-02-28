/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:22:55 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:48:45 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	intersections_sort(t_intersection *intersecs, int count)
{
	int				i;
	t_intersection	temp;

	i = 0;
	while (i < count - 1)
	{
		if (intersecs[i + 1].t < intersecs[i].t)
		{
			temp = intersecs[i];
			intersecs[i] = intersecs[i + 1];
			intersecs[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

t_intersection	hits(t_intersections xs)
{
	t_intersection	hit;
	int				i;

	i = 0;
	hit.hit = FALSE;
	while (i < xs.count)
	{
		if (xs.xs[i].t < 0)
			i++;
		else
		{
			hit.hit = TRUE;
			hit.t = xs.xs[i].t;
			hit.object = xs.xs[i].object;
			break ;
		}
	}
	return (hit);
}

static void	intersect_ray(t_intersections *xs, t_object *object, t_ray ray)
{
	t_ray	local_ray;

	local_ray = transform(ray, inverse(object->transform));
	if (object->type == SPHERE)
		intersect_sphere(xs, object, local_ray);
	if (object->type == PLANE)
		intersect_plane(xs, object, local_ray);
	if (object->type == CYLINDER)
		intersect_cyl(xs, object, local_ray);
	if (object->type == CONE)
		intersect_cone(xs, object, local_ray);
}

t_intersections	intersect_world(t_world w, t_ray ray)
{
	t_intersections	res;

	res.count = 0;
	res.i = 0;
	while (res.i < w.count)
	{
		intersect_ray(&res, &w.objects[res.i], ray);
		res.i++;
	}
	intersections_sort(res.xs, res.count);
	return (res);
}

t_intersection	intersection(float t, t_object object)
{
	t_intersection	res;

	res = (t_intersection){.t = t, .object = object};
	return (res);
}
