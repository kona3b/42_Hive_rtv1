/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaittola <kaittola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:45:10 by kaittola          #+#    #+#             */
/*   Updated: 2023/02/28 12:37:15 by kaittola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

# define WIN_H 400
# define WIN_W 600
# define WIN_N "RTv1-kaittola"

# define BUFF 100

# define EPSILON 0.0001

# define EXIT_ERROR 1
# define EXIT_SUCCESS 0

# define TRUE 1
# define FALSE 0

# define EXIT_WINDOW "Window closed, successful exit!\n"
# define EXIT_ESC "Esc pressed, successfull exit!\n"
# define EXIT_MLX_1 "mlx->mlx is NULL error!\n"
# define EXIT_MLX_2 "mlx->win is NULL error!\n"
# define EXIT_MLX_3 "mlx->img.img or mlx->img.addr is NULL error!\n"
# define EXIT_USAGE "usage: ./rtv1 <scene number (1-5)>\n"

enum e_key
{
	ESC_KEY = 53,
};

enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_object
{
	SPHERE = 1,
	PLANE = 2,
	CYLINDER = 3,
	CONE = 4
};

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef struct s_row_mtx
{
	float	c0;
	float	c1;
	float	c2;
	float	c3;
}	t_row_mtx;

typedef struct s_matrix
{
	int			size;
	t_row_mtx	r0;
	t_row_mtx	r1;
	t_row_mtx	r2;
	t_row_mtx	r3;
}	t_matrix;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_img			img;
	int				scene;
}	t_mlx;

typedef struct multis
{
	t_tuple		a0;
	t_tuple		a1;
	t_tuple		a2;
	t_tuple		a3;
	t_tuple		b0;
	t_tuple		b1;
	t_tuple		b2;
	t_tuple		b3;
}	t_multis;

typedef struct s_skews
{
	float	xy;
	float	xz;
	float	yx;
	float	yz;
	float	zx;
	float	zy;
}	t_skews;

typedef struct s_ray
{
	t_tuple	o;
	t_tuple	d;
}	t_ray;

typedef struct s_transform
{
	t_matrix	matrix;
	t_matrix	inverse;
	t_tuple		translation;
	t_tuple		rotation;
	t_tuple		scale;
}	t_transform;

typedef struct s_material
{
	float		ambi;
	float		diff;
	float		spec;
	float		shine;
	t_tuple		color;
}	t_material;

typedef struct s_object
{
	t_tuple		origin;
	float		radius;
	int			type;
	t_matrix	transform;
	t_material	material;
	t_ray		saved_ray;
	float		minimum;
	float		maximum;
}	t_object;

typedef struct s_intersection
{
	float		t;
	t_object	object;
	int			hit;
}	t_intersection;

typedef struct s_intersections
{
	int				count;
	int				i;
	t_intersection	xs[BUFF];
}	t_intersections;

typedef struct s_params
{
	float		disc;
	float		a;
	float		b;
	float		c;
	int			count;
	t_tuple		sphere_to_ray;
	t_object	object;
}	t_params;

typedef struct s_light
{
	t_tuple		position;
	t_tuple		intensity;
}	t_light;

typedef struct s_lighting
{
	t_tuple	eff_col;
	t_tuple	ambient;
	float	l_dot_norm;
	t_tuple	diff;
	t_tuple	spec;
	t_tuple	reflectv;
	t_tuple	lightv;
	float	r_dot_eye;
}	t_lighting;

typedef struct s_phong
{
	t_tuple		eye;
	t_tuple		normal;
	int			in_shadow;
}	t_phong;

typedef struct s_comps
{
	float		t;
	t_object	object;
	t_tuple		point;
	t_phong		vectors;
	int			inside;
	t_tuple		over_point;
}	t_comps;

typedef struct s_world
{
	t_light		light;
	t_object	objects[BUFF];
	int			count;
}	t_world;

typedef struct s_camera
{
	float		hsize;
	float		vsize;
	float		fov;
	t_matrix	transform;
	float		pixel_size;
	float		half_height;
	float		half_width;
}	t_camera;

typedef struct s_rays
{
	float	offset_x;
	float	offset_y;
	float	world_x;
	float	world_y;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;
}	t_rays;

int				exit_success(void);
void			exit_message(const char *msg, int v);
t_tuple			tuple(float x, float y, float z, float w);
t_tuple			point(float x, float y, float z);
t_tuple			vector(float x, float y, float z);
t_tuple			add(t_tuple a, t_tuple b);
t_tuple			subtract(t_tuple a, t_tuple b);
t_tuple			negate(t_tuple a);
t_tuple			multiply(t_tuple a, float m);
t_tuple			divide(t_tuple a, float m);
float			magnitude(t_tuple a);
t_tuple			normalize(t_tuple a);
float			dot(t_tuple a, t_tuple b);
t_tuple			cross(t_tuple a, t_tuple b);
t_tuple			color(float r, float g, float b);
t_tuple			multiply_colors(t_tuple a, t_tuple b);
int				color_int(t_tuple color);
void			get_matrix_data(t_matrix a, float *data);
t_matrix		make_matrix_2(float *data);
t_matrix		make_matrix_3(float *data);
t_matrix		make_matrix_4(float *data);
t_matrix		matrix_multiply(t_matrix a, t_matrix b);
t_tuple			tuple_matrix_multiply(t_matrix a, t_tuple b);
t_matrix		indentity_matrix(void);
t_matrix		matrix_transpose(t_matrix a);
float			matrix_determinant(t_matrix a);
t_matrix		submatrix(t_matrix a, int row, int col);
float			minor(t_matrix a, int row, int col);
float			cofactor(t_matrix a, int row, int col);
int				is_invertible(t_matrix a);
t_matrix		inverse(t_matrix a);
t_matrix		translation(float x, float y, float z);
t_matrix		scaling(float x, float y, float z);
t_matrix		rotation_x(float r);
t_matrix		rotation_y(float r);
t_matrix		rotation_z(float r);
t_matrix		shearing(t_skews s);
t_ray			ray(t_tuple origin, t_tuple direction);
t_tuple			position(t_ray ray, float t);
t_object		sphere(void);
t_object		plane(void);
t_object		cylinder(void);
t_object		cone(void);
t_intersection	intersection(float t, t_object object);
t_intersection	hits(t_intersections xs);
t_ray			transform(t_ray ray, t_matrix m);
t_tuple			normal_at(t_object o, t_tuple p);
t_light			point_light(t_tuple position, t_tuple intensity);
t_material		material(void);
t_tuple			lighting(t_material m, t_light l, t_tuple p, t_phong v);
t_intersections	intersect_world(t_world w, t_ray ray);
void			intersect_sphere(t_intersections *xs, t_object *o, t_ray ray);
void			intersect_plane(t_intersections *xs, t_object *o, t_ray ray);
void			intersect_cyl(t_intersections *xs, t_object *o, t_ray ray);
void			intersect_cone(t_intersections *xs, t_object *o, t_ray ray);
t_comps			prepare_computations(t_intersection intersec, t_ray ray);
t_tuple			color_at(t_world w, t_ray r);
t_matrix		view_transform(t_tuple from, t_tuple to, t_tuple up);
t_camera		camera(float hsize, float vsize, float fov);
t_ray			ray_for_pixel(t_camera cam, float x, float y);
void			render(t_mlx *mlx, t_camera camera, t_world world);
int				is_shadowed(t_world w, t_tuple p);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			init_mlx(t_mlx *mlx);
void			hooks(t_mlx *mlx);
int				key_event(int key, t_mlx *mlx);
void			draw(t_mlx *mlx);
void			draw_scene_1(t_mlx *mlx);
void			draw_scene_2(t_mlx *mlx);
void			draw_scene_3(t_mlx *mlx);
void			draw_scene_4(t_mlx *mlx);
void			draw_scene_5(t_mlx *mlx);

#endif
