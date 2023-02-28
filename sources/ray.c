/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:20:58 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:45:59 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	r;

	r.o = origin;
	r.d = direction;
	return (r);
}

t_tuple	position(t_ray ray, float t)
{
	return (add(ray.o, multiply(ray.d, t)));
}

t_ray	transform(t_ray ray, t_matrix m)
{
	t_ray	res;

	res.o = tuple_matrix_multiply(m, ray.o);
	res.d = tuple_matrix_multiply(m, ray.d);
	return (res);
}
