/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:13:58 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 11:35:22 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_matrix_data(t_matrix a, float *data)
{
	data[0] = a.r0.c0;
	data[1] = a.r0.c1;
	data[2] = a.r0.c2;
	data[3] = a.r0.c3;
	data[4] = a.r1.c0;
	data[5] = a.r1.c1;
	data[6] = a.r1.c2;
	data[7] = a.r1.c3;
	data[8] = a.r2.c0;
	data[9] = a.r2.c1;
	data[10] = a.r2.c2;
	data[11] = a.r2.c3;
	data[12] = a.r3.c0;
	data[13] = a.r3.c1;
	data[14] = a.r3.c2;
	data[15] = a.r3.c3;
}

t_matrix	make_matrix_2(float *data)
{
	t_matrix	m;

	m.size = 2;
	m.r0 = (t_row_mtx){.c0 = data[0], .c1 = data[1],
		.c2 = '\0', .c3 = '\0'};
	m.r1 = (t_row_mtx){.c0 = data[2], .c1 = data[3],
		.c2 = '\0', .c3 = '\0'};
	m.r2 = (t_row_mtx){.c0 = '\0', .c1 = '\0',
		.c2 = '\0', .c3 = '\0'};
	m.r3 = (t_row_mtx){.c0 = '\0', .c1 = '\0',
		.c2 = '\0', .c3 = '\0'};
	return (m);
}

t_matrix	make_matrix_3(float *data)
{
	t_matrix	m;

	m.size = 3;
	m.r0 = (t_row_mtx){.c0 = data[0], .c1 = data[1],
		.c2 = data[2], .c3 = '\0'};
	m.r1 = (t_row_mtx){.c0 = data[3], .c1 = data[4],
		.c2 = data[5], .c3 = '\0'};
	m.r2 = (t_row_mtx){.c0 = data[6], .c1 = data[7],
		.c2 = data[8], .c3 = '\0'};
	m.r3 = (t_row_mtx){.c0 = '\0', .c1 = '\0',
		.c2 = '\0', .c3 = '\0'};
	return (m);
}

t_matrix	make_matrix_4(float *data)
{
	t_matrix	m;

	m.size = 4;
	m.r0 = (t_row_mtx){.c0 = data[0], .c1 = data[1],
		.c2 = data[2], .c3 = data[3]};
	m.r1 = (t_row_mtx){.c0 = data[4], .c1 = data[5],
		.c2 = data[6], .c3 = data[7]};
	m.r2 = (t_row_mtx){.c0 = data[8], .c1 = data[9],
		.c2 = data[10], .c3 = data[11]};
	m.r3 = (t_row_mtx){.c0 = data[12], .c1 = data[13],
		.c2 = data[14], .c3 = data[15]};
	return (m);
}
