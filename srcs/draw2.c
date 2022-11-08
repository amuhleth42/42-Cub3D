

#include "cub3d.h"

void	draw_rectangle(t_img *img, float size, float offset, int index)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j++ < WIN_WIDTH / 182)
			put_pixel_to_img(img, j + index * WIN_WIDTH / 182, i + offset, 0x0000FF);
		i++;
	}
}

float	fix_fisheye(float dist, int i)
{
	float	angle;

	angle = add_rad(-PI / 4, i * PI / 384);
	return (dist * cos(angle));
}

void	draw_column(t_data *a, float dist, int i)
{
	float	size;
	float	offset;

	dist = fix_fisheye(dist, i);
	size = 64 * WIN_HEIGHT / dist;
	if (size > WIN_HEIGHT)
		size = WIN_HEIGHT;
	offset = WIN_HEIGHT / 2 - size / 2;
	draw_rectangle(&a->fp, size, offset, i);
	
}
