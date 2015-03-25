/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 16:03:04 by nchampot          #+#    #+#             */
/*   Updated: 2015/03/23 18:03:21 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void		init_img(t_env *e)
{
	e->img.img = mlx_new_image(e->mlx, W, H);
	e->img.d = mlx_get_data_addr(e->img.img, &(e->img.bpp), &(e->img.szl), &(e->img.endian));
}

void		draw_pixel(t_env *e, int x, int y, int color)
{
	unsigned int	c;

	c = mlx_get_color_value(e->mlx, color);
	e->img.d[y * e->img.szl + x * e->img.bpp / 8] = (c & 0xFF0000) >> 16;
	e->img.d[y * e->img.szl + x * e->img.bpp / 8 + 1] = (c & 0xFF00) >> 8;
	e->img.d[y * e->img.szl + x * e->img.bpp / 8 + 2] = (c & 0xFF);
}
