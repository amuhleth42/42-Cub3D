/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:30 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/14 15:45:18 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	cast_ray(t_data *a, float ra, int i)
{
	t_ray	r;

	ft_bzero(&r, sizeof(r));
	horizontal_check(a, &r, ra);
	vertical_check(a, &r, ra);
	if (r.hdist < r.vdist)
	{
		r.dist = r.hdist;
		r.value = r.hx;
		if (ra < PI)
			render_column(a, &r, i, &a->s);
		else
			render_column(a, &r, i, &a->n);
	}
	else
	{
		r.dist = r.vdist;
		r.value = r.vy;
		if (PI / 2 < ra && ra < 3 * PI / 2)
			render_column(a, &r, i, &a->w);
		else
			render_column(a, &r, i, &a->e);
	}
}

void	raycasting(t_data *a)
{
	float	start_angle;
	int		i;
	int		nb_column;

	nb_column = WIN_WIDTH / COLUMN_SIZE;
	start_angle = add_rad(a->cam.a, -(VIEW_FIELD / 2));
	i = 0;
	while (i < nb_column)
	{
		cast_ray(a, add_rad(start_angle, i * VIEW_FIELD / nb_column), i);
		i++;
	}
}
