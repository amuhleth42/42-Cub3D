

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

# define WIN_WIDTH 500
# define WIN_HEIGHT 500

enum
{
	ON_KEYDOWN = 2,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	i;
}			t_data;

//	draw.c

void	clear_img(t_img *i);
void	put_pixel_to_img(t_img *i, int x, int y, int color);

//	exit.c

int		red_cross(t_data *a);

//	keyboard.c

int		key_hook(int key, t_data *a);

#endif
