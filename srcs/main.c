/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:17 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/09 19:11:34 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_graphics(t_data *a)
{
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	a->fp.x = WIN_WIDTH;
	a->fp.y = WIN_HEIGHT;
	a->fp.img = mlx_new_image(a->mlx, a->fp.x, a->fp.y);
	a->fp.addr = mlx_get_data_addr(a->fp.img, &a->fp.bpp, &a->fp.ll,
			&a->fp.endian);
	a->mini.x = a->map.x * a->map.size;
	a->mini.y = a->map.y * a->map.size;
	a->mini.img = mlx_new_image(a->mlx, a->mini.x, a->mini.y);
	a->mini.addr = mlx_get_data_addr(a->mini.img, &a->mini.bpp, &a->mini.ll,
			&a->mini.endian);
}

void	init_mlx_hooks(t_data *a)
{
	mlx_hook(a->win, ON_KEYDOWN, 0, &key_down, a);
	mlx_hook(a->win, ON_KEYUP, 0, &key_up, a);
	mlx_hook(a->win, ON_DESTROY, 0, &red_cross, a);
	mlx_loop_hook(a->mlx, &loop_render, a);
	mlx_loop(a->mlx);
}

void	init_map(t_data *a)
{
	int	i;

	a->map.map = ft_calloc(7, sizeof(char *));
	if (!a->map.map)
		exit(1);
	i = 0;
	while (i < 6)
	{
		a->map.map[i] = ft_calloc(8, sizeof(char));
		if (!a->map.map[i])
			exit(1);
		i++;
	}
	a->map.map[0] = "1111111";
	a->map.map[1] = "1100001";
	a->map.map[2] = "1000001";
	a->map.map[3] = "1001001";
	a->map.map[4] = "1000001";
	a->map.map[5] = "1111111";
	a->map.x = 7;
	a->map.y = 6;

	if (a->map.x <= 10 && a->map.y <= 16)
		a->map.size = 20;
	else if (a->map.x <= 20 && a->map.y <= 32)
		a->map.size = 10;
	else if (a->map.x <= 30 && a->map.y <= 64)
		a->map.size = 5;
}

void	init_tile(t_img *img, char *file, void *mlx)
{
	img->img = mlx_xpm_file_to_image(mlx, file, &img->x, &img->y);
}

void	init_textures(t_data *a)
{
	init_tile(&a->n, "assets/wallgrass32.xpm", a->mlx);
	init_tile(&a->s, "assets/wall_block.xpm", a->mlx);
	init_tile(&a->e, "assets/grass32.xpm", a->mlx);
	init_tile(&a->w, "assets/star_l_32.xpm", a->mlx);
	/*if (!a->map.n.img)
	{
		ft_printf("Error: texture failed\n");
		exit(0);
	}*/
	a->n.addr = mlx_get_data_addr(a->n.img, &a->n.bpp, &a->n.ll, &a->n.endian);
	a->s.addr = mlx_get_data_addr(a->s.img, &a->s.bpp, &a->s.ll, &a->s.endian);
	a->e.addr = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.ll, &a->e.endian);
	a->w.addr = mlx_get_data_addr(a->w.img, &a->w.bpp, &a->w.ll, &a->w.endian);
}

void	init_game(t_data *a)
{
	a->cam.x = 170.0;
	a->cam.y = 170.0;
	a->cam.a = 0.0;
	a->cam.dx = cos(a->cam.a);
	a->cam.dy = sin(a->cam.a);
	a->cam.size = 4;
	a->cam.color = 0xFFFF00;
	render_frame(a);
}

int	main(int argc, char **argv)
{
	t_data	a;

	(void)argc;
	(void)argv;
	ft_bzero(&a, sizeof(a));
	init_map(&a);
	init_graphics(&a);
	init_textures(&a);
	init_game(&a);
	init_mlx_hooks(&a);
}
