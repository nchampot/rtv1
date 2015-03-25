/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:07:10 by nchampot          #+#    #+#             */
/*   Updated: 2015/03/23 20:09:39 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_cam(t_env *e)
{
	e->c.o = vec(0, 0, 0);
	e->c.u = vec(-1, 0, 0);
	e->c.v = vec(0, 1, 0);
	e->c.w = prod(e->c.v, e->c.u);
	e->c.w = normalize(e->c.w);
	e->c.l = 100;
	e->c.f = 1. / tan(e->c.l / 2);
	e->c.tx = 2. / W;
	e->c.ty = 2. / H;
}

void	init_scene(t_env *e)
{
	e->scen.sph1 = new_sph(vec(30, 0, -4), 5, 0x00FF00);
}
