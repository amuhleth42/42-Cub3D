

#include "cub3d.h"
#include <stdio.h>

void	clear_img(t_img *i)
{
	ft_bzero(i->addr, WIN_WIDTH * WIN_HEIGHT * i->bpp / 8);
}

void	put_pixel_to_img(t_img *i, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || WIN_WIDTH * 2 < x || y < 0 || WIN_HEIGHT < y)
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
	while (a->map[i] != NULL)
	{
		j = 0;
		while (a->map[i][j] != '\0')
		{
			if (a->map[i][j] == '1')
			{
				draw_square(&a->minimap, j * 64, i * 64, 64, 0x808080);
				draw_square(&a->minimap, j * 64 + 2, i * 64 + 2, 62, 0xFFFFFF);
			}
			if (a->map[i][j] == '0')
			{
				draw_square(&a->minimap, j * 64, i * 64, 64, 0x808080);
				draw_square(&a->minimap, j * 64 + 2, i * 64 + 2, 62, 0x000000);
			}
			j++;
		}
		i++;
	}
}

void	draw_cam(t_data *a)
{
	draw_square(&a->minimap, a->cam.x, a->cam.y, a->cam.size, a->cam.color);
	draw_square(&a->minimap, a->cam.x + 4 + a->cam.dx * 10, a->cam.y + 4 + a->cam.dy * 10, 2, a->cam.color);
}
