/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 11:13:07 by nchampot          #+#    #+#             */
/*   Updated: 2015/03/23 20:09:41 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	vec(int x, int y, int z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	normalize(t_vec v)
{
	double	len;

	len = len_v(v);
	len = len != 0 ? 1 / len : 0;
	v.x = v.x * len;
	v.y = v.y * len;
	v.z = v.z * len;
	return (v);
}

double	dot(t_vec v1, t_vec v2)
{
	v1 = normalize(v1);
	v2 = normalize(v2);
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}
