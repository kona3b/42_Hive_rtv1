/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:21:32 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 03:21:48 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	sphere(void)
{
	t_object	s;

	s.origin = point(0, 0, 0);
	s.radius = 1;
	s.type = SPHERE;
	s.transform = indentity_matrix();
	s.material = material();
	return (s);
}

t_object	plane(void)
{
	t_object	s;

	s.origin = point(0, 0, 0);
	s.radius = 0;
	s.type = PLANE;
	s.transform = indentity_matrix();
	s.material = material();
	return (s);
}

t_object	cylinder(void)
{
	t_object	s;

	s.origin = point(0, 0, 0);
	s.radius = 1;
	s.type = CYLINDER;
	s.minimum = -INFINITY;
	s.maximum = INFINITY;
	s.transform = indentity_matrix();
	s.material = material();
	return (s);
}

t_object	cone(void)
{
	t_object	s;

	s.origin = point(0, 0, 0);
	s.radius = 0;
	s.type = CONE;
	s.minimum = -INFINITY;
	s.maximum = INFINITY;
	s.transform = indentity_matrix();
	s.material = material();
	return (s);
}
