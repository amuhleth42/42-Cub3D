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

void	draw_column(t_data *a, t_ray *r, int index, t_img *img)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < r->size)
	{
		j = 0;
		color = get_color_from_texture(img, r->tx, r->ty);
		while (j++ < 4)
			put_pixel_to_img(&a->fp, j - 1 + index * 4, i + r->offset, color);
		i++;
		r->ty += r->step;
	}
}

void	set_column_values(t_data *a, t_ray *r)
{
	(void)a;
	r->step = 32.0 / r->size;
	r->tyoff = 0;
	if (r->size > WIN_HEIGHT)
	{
		r->tyoff = (r->size - WIN_HEIGHT) / 2;
		r->size = WIN_HEIGHT;
	}
	r->offset = WIN_HEIGHT / 2 - r->size / 2;
	r->ty = r->step * r->tyoff;
	r->tx = (int)(r->value / 2.0) % 32;
}

float	fix_fisheye(float dist, int i)
{
	float	angle;

	angle = add_rad(-PI / 5, i * VIEW_FIELD / (WIN_WIDTH / 4));
	return (dist * cos(angle));
}

void	render_column(t_data *a, t_ray *r, int i, t_img *img)
{
	r->dist = fix_fisheye(r->dist, i);
	r->size = 64 * WIN_HEIGHT / r->dist;
	set_column_values(a, r);
	draw_column(a, r, i, img);
}
