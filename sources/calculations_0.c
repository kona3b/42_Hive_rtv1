/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:10:06 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:38:14 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_tuple	add(t_tuple a, t_tuple b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return (a);
}

t_tuple	subtract(t_tuple a, t_tuple b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return (a);
}

t_tuple	negate(t_tuple a)
{
	a.x = 0.0f - a.x;
	a.y = 0.0f - a.y;
	a.z = 0.0f - a.z;
	a.w = 0.0f - a.w;
	return (a);
}

t_tuple	multiply(t_tuple a, float m)
{
	a.x *= m;
	a.y *= m;
	a.z *= m;
	a.w *= m;
	return (a);
}

t_tuple	divide(t_tuple a, float m)
{
	a.x /= m;
	a.y /= m;
	a.z /= m;
	a.w /= m;
	return (a);
}
