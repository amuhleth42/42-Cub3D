/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:05 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/09 18:08:55 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_from_texture(t_img *i, int x, int y)
{
	char	*p;

	if (x < 0 || i->x <= x || y < 0 || i->y < y)
		return (0);
	p = i->addr + (y * i->ll + x * (i->bpp / 8));
	return (*(unsigned int *)p);
}

void	draw_rectangle(t_data *a, float size, int index, int color, t_ray *r)
{
	int	offset;
	int	i;
	int	j;
	float	step;
	float	ty;
	float	tyoff;
	float	tx;

	
	step = 32.0 / size;

	tyoff = 0;
	if (size > WIN_HEIGHT)
	{
		tyoff = (size - WIN_HEIGHT) / 2;
		size = WIN_HEIGHT;
	}
	offset = WIN_HEIGHT / 2 - size / 2;
	(void)tyoff;
	ty = step * tyoff;
	tx = (int)(r->x / 2.0) % 32;
	i = 0;
	while (i < size)
	{
		j = 0;
		color = get_color_from_texture(&a->map.n, tx, ty);
		while (j++ < 4)
			put_pixel_to_img(&a->fp, j - 1 + index * 4, i + offset, color);
		i++;
		ty += step;
	}
}

float	fix_fisheye(float dist, int i)
{
	float	angle;

	angle = add_rad(-PI / 5, i * VIEW_FIELD / (WIN_WIDTH / 4));
	return (dist * cos(angle));
}

void	draw_column(t_data *a, t_ray *r, int i, int color)
{
	float	size;
	float	dist;

	dist = fix_fisheye(r->dist, i);
	size = 64 * WIN_HEIGHT / dist;
	draw_rectangle(a, size, i, color, r);
}
