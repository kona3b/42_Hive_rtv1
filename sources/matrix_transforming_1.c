/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transforming_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:19:40 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:28:05 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matrix	scaling(float x, float y, float z)
{
	t_matrix	t;

	t = (t_matrix){
		.r0.c0 = x, .r0.c1 = 0.0f, .r0.c2 = 0.0f, .r0.c3 = 0.0f,
		.r1.c0 = 0.0f, .r1.c1 = y, .r1.c2 = 0.0f, .r1.c3 = 0.0f,
		.r2.c0 = 0.0f, .r2.c1 = 0.0f, .r2.c2 = z, .r2.c3 = 0.0f,
		.r3.c0 = 0.0f, .r3.c1 = 0.0f, .r3.c2 = 0.0f, .r3.c3 = 1.0f,
		.size = 4};
	return (t);
}

t_matrix	rotation_x(float r)
{
	t_matrix	t;

	t = (t_matrix){
		.r0.c0 = 1.0f, .r0.c1 = 0.0f, .r0.c2 = 0.0f, .r0.c3 = 0.0f,
		.r1.c0 = 0.0f, .r1.c1 = cosf(r), .r1.c2 = sinf(r) * -1, .r1.c3 = 0.0f,
		.r2.c0 = 0.0f, .r2.c1 = sinf(r), .r2.c2 = cosf(r), .r2.c3 = 0.0f,
		.r3.c0 = 0.0f, .r3.c1 = 0.0f, .r3.c2 = 0.0f, .r3.c3 = 1.0f,
		.size = 4};
	return (t);
}

t_matrix	rotation_y(float r)
{
	t_matrix	t;

	t = (t_matrix){
		.r0.c0 = cosf(r), .r0.c1 = 0.0f, .r0.c2 = sinf(r), .r0.c3 = 0.0f,
		.r1.c0 = 0.0f, .r1.c1 = 1.0f, .r1.c2 = 0.0f, .r1.c3 = 0.0f,
		.r2.c0 = sinf(r) * -1, .r2.c1 = 0.0f, .r2.c2 = cosf(r), .r2.c3 = 0.0f,
		.r3.c0 = 0.0f, .r3.c1 = 0.0f, .r3.c2 = 0.0f, .r3.c3 = 1.0f,
		.size = 4};
	return (t);
}

t_matrix	rotation_z(float r)
{
	t_matrix	t;

	t = (t_matrix){
		.r0.c0 = cosf(r), .r0.c1 = sinf(r) * -1, .r0.c2 = 0.0f, .r0.c3 = 0.0f,
		.r1.c0 = sinf(r), .r1.c1 = cosf(r), .r1.c2 = 0.0f, .r1.c3 = 0.0f,
		.r2.c0 = 0.0f, .r2.c1 = 0.0f, .r2.c2 = 1.0f, .r2.c3 = 0.0f,
		.r3.c0 = 0.0f, .r3.c1 = 0.0f, .r3.c2 = 0.0f, .r3.c3 = 1.0f,
		.size = 4};
	return (t);
}

t_matrix	shearing(t_skews s)
{
	t_matrix	t;

	t = (t_matrix){
		.r0.c0 = 1.0f, .r0.c1 = s.xy, .r0.c2 = s.xz, .r0.c3 = 0.0f,
		.r1.c0 = s.yx, .r1.c1 = 1.0f, .r1.c2 = s.yz, .r1.c3 = 0.0f,
		.r2.c0 = s.zx, .r2.c1 = s.zy, .r2.c2 = 1.0f, .r2.c3 = 0.0f,
		.r3.c0 = 0.0f, .r3.c1 = 0.0f, .r3.c2 = 0.0f, .r3.c3 = 1.0f,
		.size = 4};
	return (t);
}
