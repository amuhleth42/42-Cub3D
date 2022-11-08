
#include "cub3d.h"


void	init_graphics(t_data *a)
{
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, WIN_WIDTH * 2, WIN_HEIGHT, "CUB3D");
	a->minimap.img = mlx_new_image(a->mlx, WIN_WIDTH, WIN_HEIGHT);
	a->fp.img = mlx_new_image(a->mlx, WIN_WIDTH, WIN_HEIGHT);
	a->minimap.addr = mlx_get_data_addr(a->minimap.img, &a->minimap.bpp, &a->minimap.ll, &a->minimap.endian);
	a->fp.addr = mlx_get_data_addr(a->fp.img, &a->fp.bpp, &a->fp.ll, &a->fp.endian);
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

	a->map = ft_calloc(7, sizeof(char *));
	if (!a->map)
		exit(1);
	i = 0;
	while (i < 6)
	{
		a->map[i] = ft_calloc(7, sizeof(char));
		if (!a->map[i])
			exit(1);
		i++;
	}
	a->map[0] = "111111";
	a->map[1] = "100001";
	a->map[2] = "100001";
	a->map[3] = "100101";
	a->map[4] = "100001";
	a->map[5] = "111111";
}

void	init_game(t_data *a)
{
	a->cam.x = 100.0;
	a->cam.y = 100.0;
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
	init_graphics(&a);
	init_game(&a);
	init_mlx_hooks(&a);
}
