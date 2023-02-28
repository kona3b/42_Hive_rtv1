/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:11:52 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 03:12:27 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	magnitude(t_tuple a)
{
	float	res;

	res = (float)sqrt(pow(a.x, 2.0) + pow(a.y, 2.0) + pow(a.z, 2.0)
			+ pow(a.w, 2.0));
	return (res);
}

t_tuple	normalize(t_tuple a)
{
	float	m;

	m = magnitude(a);
	a = divide(a, m);
	return (a);
}

float	dot(t_tuple a, t_tuple b)
{
	float	res;

	res = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (res);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	t_tuple	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	res.w = 0.0f;
	return (res);
}
