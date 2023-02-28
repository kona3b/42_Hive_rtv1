/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:31:27 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:42:43 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (subtract(in, multiply(multiply(normal, 2), dot(in, normal))));
}

t_tuple	lighting(t_material m, t_light l, t_tuple p, t_phong v)
{
	t_lighting	l_t;

	l_t.eff_col = multiply_colors(m.color, l.intensity);
	l_t.lightv = normalize(subtract(l.position, p));
	l_t.ambient = multiply(l_t.eff_col, m.ambi);
	l_t.l_dot_norm = dot(l_t.lightv, v.normal);
	if (l_t.l_dot_norm < 0)
	{
		l_t.diff = color(0, 0, 0);
		l_t.spec = color(0, 0, 0);
	}
	else
	{
		l_t.diff = multiply(multiply(l_t.eff_col, m.diff), l_t.l_dot_norm);
		l_t.reflectv = reflect(negate(l_t.lightv), v.normal);
		l_t.r_dot_eye = dot(l_t.reflectv, v.eye);
		if (l_t.r_dot_eye <= 0)
			l_t.spec = color(0, 0, 0);
		else
			l_t.spec = multiply(multiply(l.intensity, m.spec),
					(float)pow(l_t.r_dot_eye, m.shine));
	}
	if (v.in_shadow == TRUE)
		return (l_t.ambient);
	return (add(add(l_t.ambient, l_t.diff), l_t.spec));
}

t_light	point_light(t_tuple position, t_tuple intensity)
{
	t_light	light;

	light.position = position;
	light.intensity = intensity;
	return (light);
}
