/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:25 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/09 19:14:49 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	clear_img(&a->mini);
	clear_img(&a->fp);
	draw_map(a);
	draw_cam(a);
	draw_rays(a);
	mlx_put_image_to_window(a->mlx, a->win, a->fp.img, 0, 0);
	mlx_put_image_to_window(a->mlx, a->win, a->mini.img, 50, 50);
}

int	check_move_ok(t_data *a, float x, float y, int dir)
{
	int	mx;
	int	my;
	int	offx;
	int	offy;

	if (a->cam.dx > 0)
		offx = 20.0;
	else
		offx = -20.0;
	if (a->cam.dy > 0)
		offy = 20.0;
	else
		offy = -20.0;
	x += dir * offx;
	y += dir * offy;
	mx = ((int)x) >> 6;
	my = ((int)y) >> 6;
	if (0 <= mx && mx < a->map.x && 0 <= my && my < a->map.y && a->map.map[my][mx] == '0')
		return (1);
	return (0);
}

int	check_move_ok_rl(t_data *a, float x, float y, int dir)
{
	float	dx;
	float	dy;
	int	offx;
	int	offy;

	dx = cos(add_rad(a->cam.a, PI / 2));
	dy = sin(add_rad(a->cam.a, PI / 2));
	if (dx > 0)
		offx = 20.0;
	else
		offx = -20.0;
	if (dy > 0)
		offy = 20.0;
	else
		offy = -20.0;
	x += dir * offx;
	y += dir * offy;
	x = ((int)x) >> 6;
	y = ((int)y) >> 6;
	if (0 <= x && x < a->map.x && 0 <= y && y < a->map.y && a->map.map[(int)y][(int)x] == '0')
		return (1);
	return (0);
}

void	move(t_data *a, int dir)
{
	float	new_x;
	float	new_y;

	new_x = a->cam.x + a->cam.dx * dir * 2;
	new_y = a->cam.y + a->cam.dy * dir * 2;
	if (check_move_ok(a, new_x, a->cam.y, dir))
		a->cam.x = new_x;
	if (check_move_ok(a, a->cam.x, new_y, dir))
		a->cam.y = new_y;
}

void	rl_move(t_data *a, int dir)
{
	float	dx;
	float	dy;
	float	new_x;
	float	new_y;

	dx = cos(add_rad(a->cam.a, PI / 2));
	dy = sin(add_rad(a->cam.a, PI / 2));
	new_x = a->cam.x + dx * dir * 2;
	new_y = a->cam.y + dy * dir * 2;
	if (check_move_ok_rl(a, new_x, a->cam.y, dir))
		a->cam.x = new_x;
	if (check_move_ok_rl(a, a->cam.x, new_y, dir))
		a->cam.y = new_y;
}

void	rotate(t_data *a, double da)
{
	a->cam.a = add_rad(a->cam.a, da);
	a->cam.dx = cos(a->cam.a);
	a->cam.dy = sin(a->cam.a);
	//reset_screen(a);
}
