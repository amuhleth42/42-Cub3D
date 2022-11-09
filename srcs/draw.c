/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:56 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/09 19:09:24 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	put_pixel_to_img(t_img *i, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || i->x <= x || y < 0 || i->y <= y)
		return ;
	dst = i->addr + (y * i->ll + x * (i->bpp / 8));
	*(unsigned int *)dst = color;
}

void	clear_img(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->y)
	{
		j = 0;
		while (j++ < img->x)
			put_pixel_to_img(img, j, i, 0x0);
		i++;
	}
}

void	draw_tile(t_data *a, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->map.size)
	{
		j = 0;
		while (j++ < a->map.size)
			put_pixel_to_img(&a->mini, x + j, y + i, 0x808080);
		i++;
	}
	i = 1;
	while (i < a->map.size - 1)
	{
		j = 1;
		while (j++ < a->map.size - 1)
			put_pixel_to_img(&a->mini, x + j, y + i, color);
		i++;
	}
}

void	draw_map(t_data *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map.map[i] != NULL)
	{
		j = 0;
		while (a->map.map[i][j] != '\0')
		{
			if (a->map.map[i][j] == '1')
			{
				draw_tile(a, j * a->map.size, i * a->map.size, 0xFFFFFF);
			}
			if (a->map.map[i][j] == '0')
			{
				draw_tile(a, j * a->map.size, i * a->map.size, 0xFF000000);
			}
			j++;
		}
		i++;
	}
}

void	draw_cam(t_data *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->cam.size)
	{
		j = 0;
		while (j < a->cam.size)
		{
			put_pixel_to_img(&a->mini, j + a->cam.x / 64 * a->map.size,
					i + a->cam.y / 64 * a->map.size, a->cam.color);
			j++;
		}
		i++;
	}






	//draw_square(&a->mini, a->cam.x + 4 + a->cam.dx * 10, a->cam.y + 4 + a->cam.dy * 10, 2, a->cam.color);
}
