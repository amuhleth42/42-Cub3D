
#include "cub3d.h"


void	init_graphics(t_data *a)
{
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	a->i.img = mlx_new_image(a->mlx, WIN_WIDTH, WIN_HEIGHT);
	a->i.addr = mlx_get_data_addr(a->i.img, &a->i.bpp, &a->i.ll, &a->i.endian);
}

void	init_mlx_hooks(t_data *a)
{
	mlx_key_hook(a->win, &key_hook, a);
	mlx_hook(a->win, ON_DESTROY, 0, red_cross, a);
	mlx_loop(a->mlx);
}

int	main(int argc, char **argv)
{
	t_data	a;

	(void)argc;
	(void)argv;
	ft_bzero(&a, sizeof(a));
	init_graphics(&a);
	init_mlx_hooks(&a);
}
