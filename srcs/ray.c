/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:30 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/09 19:13:37 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		r->y = (((int)a->cam.y >> 6) << 6) - 0.0001;
		r->x = (a->cam.y - r->y) * (-1 / tan(ra)) + a->cam.x;
		r->yoff = -64;
		r->xoff = -r->yoff * (-1 / tan(ra));
	}
	else if (ra < PI)
	{
		r->y = (((int)a->cam.y >> 6) << 6) + 64;
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
		r->x = (((int)a->cam.x >> 6) << 6) - 0.0001;
		r->y = (a->cam.x - r->x) * -tan(ra) + a->cam.y;
		r->xoff = -64;
		r->yoff = -r->xoff * -tan(ra);
	}
	else if (3 * PI / 2 < ra || ra < PI / 2)
	{
		r->x = (((int)a->cam.x >> 6) << 6) + 64;
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
	if (0 <= x && x < a->map.x && 0 <= y && y < a->map.y && a->map.map[y][x] == '1')
	{
		printf("ouch!\n");
		//draw_square(&a->minimap, r->x, r->y, 3, 0x00FF00);
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
		//draw_square(&a->minimap, r->x, r->y, 3, 0xFF0000);
		r->x += r->xoff;
		r->y += r->yoff;
		i++;
	}
	//draw_square(&a->minimap, r->x, r->y, 3, 0x00FF00);
	r->hx = r->x;
	r->hy = r->y;
	r->hdist = dist(a->cam.x, a->cam.y, r->hx, r->hy);
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
		//draw_square(&a->minimap, r->x, r->y, 3, 0xFF0000);
		r->x += r->xoff;
		r->y += r->yoff;
		i++;
	}
	//draw_square(&a->minimap, r->x, r->y, 3, 0x00FF00);
	r->vx = r->x;
	r->vy = r->y;
	r->vdist = dist(a->cam.x, a->cam.y, r->vx, r->vy);
}

void	draw_ray(t_data *a, float ra, int i)
{
	t_ray	r;

	ft_bzero(&r, sizeof(r));
	horizontal_check(a, &r, ra);
	vertical_check(a, &r, ra);
	if (r.hdist < r.vdist)
	{
		draw_column(a, r.hdist, i, 0x0000FF);
		//draw_square(&a->mini, r.hx, r.hy, 3, 0x00FF00);
	}
	else
	{
		draw_column(a, r.vdist, i, 0x0000AA);
		//draw_square(&a->mini, r.vx, r.vy, 3, 0x00FF00);
	}
}

void	draw_rays(t_data *a)
{
	float	start_angle;
	int		i;
	int		nb_column;

	nb_column = WIN_WIDTH / 4;
	start_angle = add_rad(a->cam.a, -PI / 5);
	i = 0;
	while (i < nb_column)
	{
		draw_ray(a, add_rad(start_angle, i * VIEW_FIELD / nb_column), i);
		i++;
	}
}
