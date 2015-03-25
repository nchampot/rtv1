/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 11:21:48 by nchampot          #+#    #+#             */
/*   Updated: 2015/03/23 20:09:08 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray	build_ray(int x, int y, t_env e)
{
	t_ray r;

	r.o = e.c.o;
	r.d = add(mult(e.c.f, e.c.u), add(mult(e.c.tx *\
		(W / 2 - x), e.c.v), mult(e.c.ty * (H / 2 - y), e.c.w)));
	r.d = normalize(r.d);
//	printf("%f %f %f\n", r.d.x, r.d.y, r.d.z);
	return (r);
}

void	raytrace(t_env *e)
{
	int		x;
	int		y;
	t_ray	r;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < H)
		{
			r = build_ray(x, y, *e);
			if (inter_sph(r, e->scen.sph1) >= 0)
				draw_pixel(e, x, y, e->scen.sph1.c);
			x++;
		}
		y++;
	}
}
