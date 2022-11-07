

#include "cub3d.h"

void	clear_img(t_img *i)
{
	ft_bzero(i->addr, WIN_WIDTH * WIN_HEIGHT * i->bpp / 8);
}

void	put_pixel_to_img(t_img *i, int x, int y, int color)
{
	char	*dst;

	dst = i->addr + (y * i->ll + x * (i->bpp / 8));
	*(unsigned int *)dst = color;
}
