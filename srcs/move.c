
#include <stdio.h>
#include "cub3d.h"

float	add_rad(float a1, float a2)
{
	a1 += a2;
	if (a1 < 0.0)
		a1 += 2 * PI;
	else if (a1 >= 2 * PI)
		a1 -= 2 * PI;
	return (a1);
}

void	reset_screen(t_data *a)
{
	clear_img(a->i.img);
	draw_map(a);
	draw_cam(a);
	draw_ray(a, a->cam.a);
	mlx_put_image_to_window(a->mlx, a->win, a->i.img, 0, 0);
}

int	check_move_ok(t_data *a, float x, float y)
{
	int	mx;
	int	my;

	mx = ((int)x) >> 6;
	my = ((int)y) >> 6;
	if (0 <= mx && mx < 6 && 0 <= my && my < 6 && a->map[my][mx] == '1')
		return (0);
	return (1);

}

void	move(t_data *a, int dirx, int diry)
{
	float	new_x;
	float	new_y;
	new_x = a->cam.x + a->cam.dx * dirx * 4;
	new_y = a->cam.y + a->cam.dy * diry * 4;
	if (check_move_ok(a, new_x, new_y))
	{
		a->cam.x = new_x;
		a->cam.y = new_y;
		reset_screen(a);
	}
}

void	rl_move(t_data *a, int dirx, int diry)
{
	float	dx;
	float	dy;

	dx = cos(add_rad(a->cam.a, PI / 2));
	dy = sin(add_rad(a->cam.a, PI / 2));
	a->cam.x += dx * dirx * 4;
	a->cam.y += dy * diry * 4;
	reset_screen(a);
}

void	rotate(t_data *a, double da)
{
	a->cam.a = add_rad(a->cam.a, da);
	printf("a: %f\n", a->cam.a);
	a->cam.dx = cos(a->cam.a);
	a->cam.dy = sin(a->cam.a);
	reset_screen(a);
}
