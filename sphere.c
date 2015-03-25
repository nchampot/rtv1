/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <nchampot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 18:16:05 by nchampot          #+#    #+#             */
/*   Updated: 2015/03/23 20:09:41 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv1.h"

t_sph	new_sph(t_vec o, double r, int c)
{
	t_sph s;

	s.o = o;
	s.r = r;
	s.c = c;
	return (s);
}

double	inter_sph(t_ray r, t_sph s)
{
	double	a;
	double	b;
	double	c;
	double	det;
	double	tmp;

	a = dot(r.d, r.d);
	b = 2 * dot(r.d, sub(r.o, s.o));
	c = dot(sub(r.o, s.o), sub(r.o, s.o)) - s.r;
	det = P(b) - 4 * a * c;
	if (det < 0)
		return (-1);
	if (det == 0)
		return (-b / (2 * a));
	c = (-b - sqrt(det)) / (2 * a);
	tmp = (-b + sqrt(det)) / (2 * a);
	if (c < 0 && tmp < 0)
		return (-1.);
	if (c < 0 && tmp >= 0)
		return (tmp);
	if (c >= 0 && tmp < 0)
		return (c);
	return (tmp > c ? c : tmp);
}
