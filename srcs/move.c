
#include <stdio.h>
#include "cub3d.h"

void	move(t_data *a, int dx, int dy)
{
	a->cam.x += dx;
	a->cam.y += dy;
	clear_img(a->i.img);
	draw_map(a);
	draw_cam(a);
	mlx_put_image_to_window(a->mlx, a->win, a->i.img, 0, 0);
}
