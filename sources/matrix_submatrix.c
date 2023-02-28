/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:17:22 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 03:17:47 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	submatrix_4(int row, int col, float *src, float *dst)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < 16 && j < 9)
	{
		if (row == 0 && i < 4)
			i++;
		else if (row == 1 && i >= 4 && i < 8)
			i++;
		else if (row == 2 && i >= 8 && i < 12)
			i++;
		else if (row == 3 && i >= 12)
			i++;
		else if (i == col || i == col + 4 || i == col + 8 || i == col + 12)
			i++;
		else
			dst[j++] = src[i++];
	}
}

static void	submatrix_3(int row, int col, float *src, float *dst)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < 11 && j < 4)
	{
		if (row == 0 && i < 4)
			i++;
		else if (row == 1 && i >= 4 && i < 8)
			i++;
		else if (row == 2 && i >= 8)
			i++;
		else if (i == col || i == col + 4 || i == col + 8 || i == 3 || i == 7)
			i++;
		else
			dst[j++] = src[i++];
	}
}

t_matrix	submatrix(t_matrix a, int row, int col)
{
	t_matrix	res;
	float		data[16];
	float		data2[4];
	float		data3[9];

	get_matrix_data(a, data);
	if (a.size == 4)
	{
		submatrix_4(row, col, data, data3);
		res = make_matrix_3(data3);
	}
	else
	{
		submatrix_3(row, col, data, data2);
		res = make_matrix_2(data2);
	}
	return (res);
}
