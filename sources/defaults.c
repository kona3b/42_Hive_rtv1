/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:30:22 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 09:49:51 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_material	material(void)
{
	t_material	m;

	m.color = color(1.0f, 1.0f, 1.0f);
	m.ambi = 0.1f;
	m.diff = 0.9f;
	m.spec = 0.9f;
	m.shine = 200.0f;
	return (m);
}
