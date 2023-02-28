/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:12:59 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:38:34 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_tuple	color(float r, float g, float b)
{
	t_tuple	res;

	res = tuple(r, g, b, 0.0f);
	return (res);
}

t_tuple	multiply_colors(t_tuple a, t_tuple b)
{
	t_tuple	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	res.w = 0.0f;
	return (res);
}

int	color_int(t_tuple color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color.x * 0xFF);
	g = (int)(color.y * 0xFF);
	b = (int)(color.z * 0xFF);
	return ((r << 16) | (g << 8) | b);
}
