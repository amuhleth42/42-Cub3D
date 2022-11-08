

#include "cub3d.h"

void	draw_rectangle(t_img *img, float size, int index, int color)
{
	int	offset;
	int	i;
	int	j;

	offset = WIN_HEIGHT / 2 - size / 2;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j++ < 2)
			put_pixel_to_img(img, j + index * 2, i + offset, color);
		i++;
	}
}

float	fix_fisheye(float dist, int i)
{
	float	angle;

	angle = add_rad(-PI / 5, i * PI / 384);
	return (dist * cos(angle));
}

void	draw_column(t_data *a, float dist, int i, int color)
{
	float	size;

	dist = fix_fisheye(dist, i);
	size = 64 * WIN_HEIGHT / 2 / dist;
	if (size > WIN_HEIGHT)
		size = WIN_HEIGHT;
	draw_rectangle(&a->fp, size, i, color);
}
