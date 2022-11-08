

#include "cub3d.h"
#include <stdio.h>

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	set_horizontal_start(t_data *a, t_ray *r, float ra)
{
	if (ra > PI)
	{
		r->y = (((int)a->cam.y>>6)<<6) - 0.0001;
		r->x = (a->cam.y - r->y) * (-1 / tan(ra)) + a->cam.x;
		r->yoff = -64;
		r->xoff = -r->yoff * (-1 / tan(ra));
	}
	else if (ra < PI)
	{
		r->y = (((int)a->cam.y>>6)<<6) + 64;
		r->x = (a->cam.y - r->y) * (-1 / tan(ra)) + a->cam.x;
		r->yoff = 64;
		r->xoff = -r->yoff * (-1 / tan(ra));
	}
	else
	{
		r->x = a->cam.x;
		r->y = a->cam.y;
		r->nope = 1;
	}
}

void	set_vertical_start(t_data *a, t_ray *r, float ra)
{
	if (PI / 2 < ra && ra < 3 * PI / 2)
	{
		r->x = (((int)a->cam.x>>6)<<6) - 0.0001;
		r->y = (a->cam.x - r->x) * -tan(ra) + a->cam.y;
		r->xoff = -64;
		r->yoff = -r->xoff * -tan(ra);
	}
	else if (3 * PI / 2 < ra || ra < PI / 2)
	{
		r->x = (((int)a->cam.x>>6)<<6) + 64;
		r->y = (a->cam.x - r->x) * -tan(ra) + a->cam.y;
		r->xoff = 64;
		r->yoff = -r->xoff * -tan(ra);
	}
	else
	{
		r->x = a->cam.x;
		r->y = a->cam.y;
		r->nope = 1;
	}
}

int	hit_wall(t_data *a, t_ray *r)
{
	int	x;
	int	y;

	x = ((int)r->x) >> 6;
	y = ((int)r->y) >> 6;
	printf("Map x: %d, map y: %d\n", x, y);
	if (0 <= x && x < 6 && 0 <= y && y < 6 && a->map[y][x] == '1')
	{
		printf("ouch!\n");
		return (1);
	}
	return (0);
}

void	horizontal_check(t_data *a, t_ray *r, float ra)
{
	int	i;

	set_horizontal_start(a, r, ra);
	i = 0;
	while (i < 8)
	{
		if (hit_wall(a, r))
			break ;
		draw_square(a, r->x, r->y, 3, 0xFF0000);
		r->x += r->xoff;
		r->y += r->yoff;
		i++;
	}
	draw_square(a, r->x, r->y, 3, 0x00FF00);
	r->hx = r->x;
	r->hy = r->y;
}

void	vertical_check(t_data *a, t_ray *r, float ra)
{
	int	i;

	set_vertical_start(a, r, ra);
	i = 0;
	while (i < 8)
	{
		if (hit_wall(a, r))
			break ;
		draw_square(a, r->x, r->y, 3, 0xFF0000);
		r->x += r->xoff;
		r->y += r->yoff;
		i++;
	}
	draw_square(a, r->x, r->y, 3, 0x00FF00);
	r->vx = r->x;
	r->vy = r->y;
}
void	draw_ray(t_data *a, float ra)
{
	t_ray	r;

	ft_bzero(&r, sizeof(r));
	horizontal_check(a, &r, ra);
	vertical_check(a, &r, ra);

}
