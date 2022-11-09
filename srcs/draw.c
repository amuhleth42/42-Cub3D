/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:56 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/09 17:59:37 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	clear_img(t_img *i)
{
	ft_bzero(i->addr, WIN_WIDTH * WIN_HEIGHT * i->bpp / 8);
}

void	put_pixel_to_img(t_img *i, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || i->x <= x || y < 0 || i->y <= y)
		return ;
	dst = i->addr + (y * i->ll + x * (i->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j++ < size)
			put_pixel_to_img(img, x + j, y + i, color);
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
				draw_square(&a->mini, j * a->map.size, i * a->map.size, a->map.size, 0x808080);
				draw_square(&a->mini, j * a->map.size + 2, i * a->map.size + 2, a->map.size - 2, 0xFFFFFF);
			}
			if (a->map.map[i][j] == '0')
			{
				draw_square(&a->mini, j * a->map.size, i * a->map.size, a->map.size, 0x808080);
				draw_square(&a->mini, j * a->map.size + 2, i * a->map.size + 2, a->map.size - 2, 0x000000);
			}
			j++;
		}
		i++;
	}
}

void	draw_cam(t_data *a)
{
	draw_square(&a->mini, a->cam.x / 64 * a->map.size, a->cam.y / 64 * a->map.size, a->cam.size, a->cam.color);
	//draw_square(&a->mini, a->cam.x + 4 + a->cam.dx * 10, a->cam.y + 4 + a->cam.dy * 10, 2, a->cam.color);
}
