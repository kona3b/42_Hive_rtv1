/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transforming_0.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:19:06 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:25:11 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	minor(t_matrix a, int row, int col)
{
	return (matrix_determinant(submatrix(a, row, col)));
}

float	cofactor(t_matrix a, int row, int col)
{
	if ((row + col) % 2 == 0)
		return (minor(a, row, col));
	return ((minor(a, row, col) * -1));
}

int	is_invertible(t_matrix a)
{
	if (matrix_determinant(a) == 0)
		return (0);
	return (1);
}

t_matrix	inverse(t_matrix a)
{
	t_matrix	b;
	float		d;

	if (!is_invertible(a))
		exit_message("matrix not invertible!\n", EXIT_ERROR);
	d = matrix_determinant(a);
	b = (t_matrix){.r0.c0 = cofactor(a, 0, 0) / d,
		.r1.c0 = cofactor(a, 0, 1) / d,
		.r2.c0 = cofactor(a, 0, 2) / d,
		.r3.c0 = cofactor(a, 0, 3) / d,
		.r0.c1 = cofactor(a, 1, 0) / d,
		.r1.c1 = cofactor(a, 1, 1) / d,
		.r2.c1 = cofactor(a, 1, 2) / d,
		.r3.c1 = cofactor(a, 1, 3) / d,
		.r0.c2 = cofactor(a, 2, 0) / d,
		.r1.c2 = cofactor(a, 2, 1) / d,
		.r2.c2 = cofactor(a, 2, 2) / d,
		.r3.c2 = cofactor(a, 2, 3) / d,
		.r0.c3 = cofactor(a, 3, 0) / d,
		.r1.c3 = cofactor(a, 3, 1) / d,
		.r2.c3 = cofactor(a, 3, 2) / d,
		.r3.c3 = cofactor(a, 3, 3) / d,
		.size = 4};
	return (b);
}

t_matrix	translation(float x, float y, float z)
{
	t_matrix	t;

	t = (t_matrix){
		.r0.c0 = 1.0f, .r0.c1 = 0.0f, .r0.c2 = 0.0f, .r0.c3 = x,
		.r1.c0 = 0.0f, .r1.c1 = 1.0f, .r1.c2 = 0.0f, .r1.c3 = y,
		.r2.c0 = 0.0f, .r2.c1 = 0.0f, .r2.c2 = 1.0f, .r2.c3 = z,
		.r3.c0 = 0.0f, .r3.c1 = 0.0f, .r3.c2 = 0.0f, .r3.c3 = 1.0f,
		.size = 4};
	return (t);
}
