/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_and_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:34:17 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 03:34:49 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static t_tuple	shade_hit(t_world w, t_comps c)
{
	c.vectors.in_shadow = is_shadowed(w, c.over_point);
	return (lighting(c.object.material, w.light, c.over_point, c.vectors));
}

t_tuple	color_at(t_world w, t_ray r)
{
	t_intersections	xs;
	t_intersection	hit;
	t_tuple			res;

	xs = intersect_world(w, r);
	hit = hits(xs);
	if (hit.hit == FALSE)
		return (color(0, 0, 0));
	res = shade_hit(w, prepare_computations(intersection(hit.t,
					hit.object), r));
	if (res.x > 1.0f)
		res.x = 1.0f;
	if (res.y > 1.0f)
		res.y = 1.0f;
	if (res.z > 1.0f)
		res.z = 1.0f;
	return (res);
}

int	is_shadowed(t_world w, t_tuple p)
{
	float			dist;
	t_ray			r;
	t_intersection	h;
	t_intersections	xs;

	dist = magnitude(subtract(w.light.position, p));
	r = ray(p, normalize(subtract(w.light.position, p)));
	xs = intersect_world(w, r);
	h = hits(xs);
	if (h.hit == TRUE && h.t < dist)
		return (TRUE);
	return (FALSE);
}
