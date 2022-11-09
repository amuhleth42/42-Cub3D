/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:17 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/09 17:38:12 by amuhleth         ###   ########.fr       */
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
	a->mini.x = WIN_WIDTH / 4;
	a->mini.y = WIN_HEIGHT / 4;
	a->mini.img = mlx_new_image(a->mlx, a->mini.x, a->mini.y);
	a->mini.addr = mlx_get_data_addr(a->mini.img, &a->mini.bpp, &a->mini.ll,
			&a->mini.endian);
}

void	init_mlx_hooks(t_data *a)
{
	mlx_key_hook(a->win, &key_hook, a);
	mlx_hook(a->win, ON_KEYDOWN, 0, &key_down, a);
	mlx_hook(a->win, ON_DESTROY, 0, &red_cross, a);
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
		a->map.map[i] = ft_calloc(7, sizeof(char));
		if (!a->map.map[i])
			exit(1);
		i++;
	}
	a->map.map[0] = "111111";
	a->map.map[1] = "110001";
	a->map.map[2] = "100001";
	a->map.map[3] = "100101";
	a->map.map[4] = "100001";
	a->map.map[5] = "111111";
}

void	init_game(t_data *a)
{
	a->cam.x = 170.0;
	a->cam.y = 170.0;
	a->cam.a = 0.0;
	a->cam.dx = cos(a->cam.a);
	a->cam.dy = sin(a->cam.a);
	a->cam.size = 8;
	a->cam.color = 0xFFFF00;
	init_map(a);
	reset_screen(a);
}

int	main(int argc, char **argv)
{
	t_data	a;

	(void)argc;
	(void)argv;
	ft_bzero(&a, sizeof(a));
	ft_printf("1\n");
	init_graphics(&a);
	ft_printf("1\n");
	init_game(&a);
	ft_printf("1\n");
	init_mlx_hooks(&a);
}
