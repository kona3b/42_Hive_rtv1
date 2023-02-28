/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_locals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:25:12 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 12:55:48 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	intersect_sphere(t_intersections *xs, t_object *o, t_ray ray)
{
	t_params		params;

	o->saved_ray = ray;
	params.sphere_to_ray = subtract(ray.o, o->origin);
	params.a = dot(ray.d, ray.d);
	params.b = 2 * dot(ray.d, params.sphere_to_ray);
	params.c = dot(params.sphere_to_ray, params.sphere_to_ray) - 1;
	params.disc = ((float)(pow(params.b, 2)) - 4 * params.a * params.c);
	if (params.disc < 0)
		xs->count += 0;
	else
	{
		xs->xs[xs->count].t = (-params.b - sqrtf(params.disc))
			/ (2.0f * params.a);
		xs->xs[xs->count++].object = *o;
		xs->xs[xs->count].t = (-params.b + sqrtf(params.disc))
			/ (2.0f * params.a);
		xs->xs[xs->count++].object = *o;
	}
}

void	intersect_plane(t_intersections *xs, t_object *o, t_ray ray)
{
	t_intersections	res;

	if (fabs(ray.d.y) < EPSILON)
		res.count += 0;
	else
	{
		xs->xs[xs->count].t = (-ray.o.y / ray.d.y);
		xs->xs[xs->count].object = *o;
		xs->count++;
	}
}

void	intersect_cyl(t_intersections *xs, t_object *o, t_ray ray)
{
	t_params		params;

	o->saved_ray = ray;
	params.a = powf(ray.d.x, 2.0f) + powf(ray.d.z, 2.0f);
	if (fabs(params.a) >= EPSILON)
	{
		params.b = 2 * ray.o.x * ray.d.x + 2 * ray.o.z * ray.d.z;
		params.c = powf(ray.o.x, 2.) + powf(ray.o.z, 2.) - 1;
		params.disc = ((float)(pow(params.b, 2)) - 4 * params.a * params.c);
		if (params.disc >= 0)
		{
			xs->xs[xs->count].t = (-params.b - sqrtf(params.disc))
				/ (2.0f * params.a);
			xs->xs[xs->count].object = *o;
			xs->count++;
			xs->xs[xs->count].t = (-params.b + sqrtf(params.disc))
				/ (2.0f * params.a);
			xs->xs[xs->count].object = *o;
			xs->count++;
		}
	}
}

void	intersect_cone(t_intersections *xs, t_object *o, t_ray ray)
{
	t_params		params;

	o->saved_ray = ray;
	params.a = powf(ray.d.x, 2.0f) - powf(ray.d.y, 2.0f) + powf(ray.d.z, 2.0f);
	params.b = 2 * ray.o.x * ray.d.x - 2
		* ray.o.y * ray.d.y + 2 * ray.o.z * ray.d.z;
	params.c = powf(ray.o.x, 2.0f) - powf(ray.o.y, 2.0f) + powf(ray.o.z, 2.0f);
	if (fabs(params.a) < EPSILON && fabs(params.b) >= EPSILON)
		xs->xs[xs->count++].t = -params.c / (2 * params.b);
	else if (fabs(params.a) >= EPSILON)
	{
		params.disc = ((float)(pow(params.b, 2)) - 4 * params.a * params.c);
		if (params.disc >= 0)
		{
			xs->xs[xs->count].t = (-params.b - sqrtf(params.disc))
				/ (2.0f * params.a);
			xs->xs[xs->count].object = *o;
			xs->count++;
			xs->xs[xs->count].t = (-params.b + sqrtf(params.disc))
				/ (2.0f * params.a);
			xs->xs[xs->count].object = *o;
			xs->count++;
		}
	}
}
