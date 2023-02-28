/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:08:24 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 03:09:05 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_tuple	tuple(float x, float y, float z, float w)
{
	t_tuple	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = w;
	return (res);
}

t_tuple	point(float x, float y, float z)
{
	t_tuple	res;

	res = tuple(x, y, z, 1.0f);
	return (res);
}

t_tuple	vector(float x, float y, float z)
{
	t_tuple	res;

	res = tuple(x, y, z, 0.0f);
	return (res);
}
