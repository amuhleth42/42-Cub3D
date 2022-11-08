

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

# define WIN_WIDTH 384
# define WIN_HEIGHT 384

# define PI 3.1415926535

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

typedef struct s_cam
{
	float		x;
	float		y;
	int		size;
	int		color;
	float		dx;
	float		dy;
	float		a;
}			t_cam;

typedef struct s_ray
{
	float	x;
	float	y;
	float	xoff;
	float	yoff;
}			t_ray;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	t_img	i;
	t_cam	cam;
}			t_data;

//	draw.c

void	clear_img(t_img *i);
void	put_pixel_to_img(t_img *i, int x, int y, int color);
void	draw_square(t_data *a, int x, int y, int size, int color);
void	draw_cam(t_data *a);
void	draw_map(t_data *a);

//	exit.c

int		red_cross(t_data *a);

//	keyboard.c

int		key_hook(int key, t_data *a);
int		key_down(int key, t_data *a);

//	move.c

void	move(t_data *a, int dx, int dy);
void	rl_move(t_data *a, int dx, int dy);
void	rotate(t_data *a, double da);
void	reset_screen(t_data *a);

//	ray.c

void	draw_ray(t_data *a, float ra);

#endif
