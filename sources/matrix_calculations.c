/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calculations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:15:02 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:21:37 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matrix	matrix_multiply(t_matrix a, t_matrix b)
{
	t_matrix	m;
	t_multis	ms;

	ms = (t_multis){.a0 = tuple(a.r0.c0, a.r0.c1, a.r0.c2, a.r0.c3),
		.a1 = tuple(a.r1.c0, a.r1.c1, a.r1.c2, a.r1.c3),
		.a2 = tuple(a.r2.c0, a.r2.c1, a.r2.c2, a.r2.c3),
		.a3 = tuple(a.r3.c0, a.r3.c1, a.r3.c2, a.r3.c3),
		.b0 = tuple(b.r0.c0, b.r1.c0, b.r2.c0, b.r3.c0),
		.b1 = tuple(b.r0.c1, b.r1.c1, b.r2.c1, b.r3.c1),
		.b2 = tuple(b.r0.c2, b.r1.c2, b.r2.c2, b.r3.c2),
		.b3 = tuple(b.r0.c3, b.r1.c3, b.r2.c3, b.r3.c3)};
	m = (t_matrix){.r0.c0 = dot(ms.a0, ms.b0), .r0.c1 = dot(ms.a0, ms.b1),
		.r0.c2 = dot(ms.a0, ms.b2), .r0.c3 = dot(ms.a0, ms.b3),
		.r1.c0 = dot(ms.a1, ms.b0), .r1.c1 = dot(ms.a1, ms.b1),
		.r1.c2 = dot(ms.a1, ms.b2), .r1.c3 = dot(ms.a1, ms.b3),
		.r2.c0 = dot(ms.a2, ms.b0), .r2.c1 = dot(ms.a2, ms.b1),
		.r2.c2 = dot(ms.a2, ms.b2), .r2.c3 = dot(ms.a2, ms.b3),
		.r3.c0 = dot(ms.a3, ms.b0), .r3.c1 = dot(ms.a3, ms.b1),
		.r3.c2 = dot(ms.a3, ms.b2), .r3.c3 = dot(ms.a3, ms.b3), .size = 4,};
	return (m);
}

t_tuple	tuple_matrix_multiply(t_matrix a, t_tuple b)
{
	t_tuple	res;

	res = (t_tuple){.x = a.r0.c0 * b.x + a.r0.c1 * b.y + a.r0.c2 * b.z
		+ a.r0.c3 * b.w, .y = a.r1.c0 * b.x + a.r1.c1 * b.y + a.r1.c2 * b.z
		+ a.r1.c3 * b.w, .z = a.r2.c0 * b.x + a.r2.c1 * b.y + a.r2.c2 * b.z
		+ a.r2.c3 * b.w, .w = a.r3.c0 * b.x + a.r3.c1 * b.y + a.r3.c2 * b.z
		+ a.r3.c3 * b.w};
	return (res);
}

t_matrix	indentity_matrix(void)
{
	t_matrix	m;

	m = (t_matrix){
		.r0.c0 = 1.0f, .r0.c1 = 0.0f, .r0.c2 = 0.0f, .r0.c3 = 0.0f,
		.r1.c0 = 0.0f, .r1.c1 = 1.0f, .r1.c2 = 0.0f, .r1.c3 = 0.0f,
		.r2.c0 = 0.0f, .r2.c1 = 0.0f, .r2.c2 = 1.0f, .r2.c3 = 0.0f,
		.r3.c0 = 0.0f, .r3.c1 = 0.0f, .r3.c2 = 0.0f, .r3.c3 = 1.0f,
		.size = 4};
	return (m);
}

t_matrix	matrix_transpose(t_matrix a)
{
	t_matrix	m;

	m = (t_matrix){
		.r0.c0 = a.r0.c0, .r0.c1 = a.r1.c0, .r0.c2 = a.r2.c0, .r0.c3 = a.r3.c0,
		.r1.c0 = a.r0.c1, .r1.c1 = a.r1.c1, .r1.c2 = a.r2.c1, .r1.c3 = a.r3.c1,
		.r2.c0 = a.r0.c2, .r2.c1 = a.r1.c2, .r2.c2 = a.r2.c2, .r2.c3 = a.r3.c2,
		.r3.c0 = a.r0.c3, .r3.c1 = a.r1.c3, .r3.c2 = a.r2.c3, .r3.c3 = a.r3.c3,
		.size = a.size};
	return (m);
}

float	matrix_determinant(t_matrix a)
{
	float	res;

	if (a.size == 2)
		res = (a.r0.c0 * a.r1.c1 - a.r0.c1 * a.r1.c0);
	else if (a.size == 3)
	{
		res = (a.r0.c0 * cofactor(a, 0, 0) + a.r0.c1 * cofactor(a, 0, 1)
				+ a.r0.c2 * cofactor(a, 0, 2));
	}
	else
	{
		res = (a.r0.c0 * cofactor(a, 0, 0) + a.r0.c1 * cofactor(a, 0, 1)
				+ a.r0.c2 * cofactor(a, 0, 2) + a.r0.c3 * cofactor(a, 0, 3));
	}
	return (res);
}
