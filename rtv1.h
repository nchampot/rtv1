/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 18:03:01 by nchampot          #+#    #+#             */
/*   Updated: 2015/03/23 20:09:40 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# define P(x) (x) * (x)
# define W 1200
# define H 1200

/*
**------------KEYS--------------
*/
# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_ray
{
	t_vec	o; //origine
	t_vec	d; //direction
}				t_ray;

typedef struct	s_sph
{
	t_vec	o; //origine
	double	r; //rayon
	int		c; //couleur
}				t_sph;

typedef struct	s_cam
{
	t_vec	o; // o
	t_vec	u; // i
	t_vec	v; // j
	t_vec	w; // k
	double	l; //viewPlaneWidth
	double	f; //distance focale
	double	tx;
	double	ty;
}				t_cam;

typedef struct	s_img
{
	void			*img;
	int				szl;
	char			*d;
	int				endian;
	int				bpp;
}				t_img;

typedef struct	s_scen
{
	t_sph	sph1;
}				t_scen;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_cam	c;
	t_scen	scen;
}				t_env;

void			draw_pixel(t_env *e, int x, int y, int color);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
void			init_scene(t_env *e);
void			init_cam(t_env *e);
void			init_img(t_env *e);
void			raytrace(t_env *e);
/*
**------------VECTOR FUNCTIONS--------------
*/
double			len_v(t_vec v);
t_vec			vec(int x, int y, int z);
t_vec			normalize(t_vec v);
t_vec			add(t_vec v1, t_vec v2);
t_vec			sub(t_vec v1, t_vec v2);
t_vec			mult(double x, t_vec v1);
t_vec			prod(t_vec v1, t_vec v2);
double			dot(t_vec v1, t_vec v2);
/*
**------------OBJECT FUNCTIONS--------------
*/
t_sph			new_sph(t_vec o, double r, int c);
double			inter_sph(t_ray r, t_sph s);

#endif
