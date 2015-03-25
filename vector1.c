/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 11:13:26 by nchampot          #+#    #+#             */
/*   Updated: 2015/03/23 20:09:09 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	len_v(t_vec v)
{
	return (sqrt(P(v.x) + P(v.y) + P(v.z)));
}

t_vec	add(t_vec v1, t_vec v2)
{
	t_vec	new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}

t_vec	sub(t_vec v1, t_vec v2)
{
	t_vec	new;

	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	new.z = v1.z - v2.z;
	return (new);
}

t_vec	mult(double x, t_vec v1)
{
	t_vec	new;

	new.x = v1.x * x;
	new.y = v1.y * x;
	new.z = v1.z * x;
	return (new);
}

t_vec	prod(t_vec v1, t_vec v2)
{
	t_vec	new;

	new.x = v1.y * v2.z - v1.z * v2.y;
	new.y = v1.z * v2.x - v1.x * v2.z;
	new.z = v1.x * v2.y - v1.y * v2.x;
	return (new);
}
