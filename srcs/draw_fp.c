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

void	draw_rectangle(t_img *img, float size, int index, int color)
{
	int	offset;
	int	i;
	int	j;

	offset = WIN_HEIGHT / 2 - size / 2;
	//offset = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j++ < 4)
			put_pixel_to_img(img, j + index * 4, i + offset, color);
		i++;
	}
}

float	fix_fisheye(float dist, int i)
{
	float	angle;

	angle = add_rad(-PI / 5, i * VIEW_FIELD / (WIN_WIDTH / 4));
	return (dist * cos(angle));
}

void	draw_column(t_data *a, float dist, int i, int color)
{
	float	size;

	dist = fix_fisheye(dist, i);
	size = 64 * WIN_HEIGHT / dist;
	if (size > WIN_HEIGHT)
		size = WIN_HEIGHT;
	draw_rectangle(&a->fp, size, i, color);
}
