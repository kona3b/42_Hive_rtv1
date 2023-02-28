/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:32:49 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 03:33:42 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_comps	prepare_computations(t_intersection intersec, t_ray ray)
{
	t_comps	comps;

	comps.inside = FALSE;
	comps.t = intersec.t;
	comps.object = intersec.object;
	comps.point = position(ray, comps.t);
	comps.vectors.eye = negate(ray.d);
	comps.vectors.normal = normal_at(comps.object, comps.point);
	if (dot(comps.vectors.normal, comps.vectors.eye) < 0)
	{
		comps.inside = TRUE;
		comps.vectors.normal = negate(comps.vectors.normal);
	}
	comps.over_point = add(comps.point,
			multiply(comps.vectors.normal, (float)EPSILON));
	return (comps);
}
