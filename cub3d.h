

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 800

# define PI 3.1415926535

# define VIEW_FIELD	(PI / 3)
# define COLUMN_SIZE 2

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
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
	int		x;
	int		y;
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
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	hdist;
	float	vdist;
	float	dist;
	char	side;
	int		offset;
	float	size;
	float	step;
	float	tx;
	float	ty;
	float	tyoff;
	float	value;
}			t_ray;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		size;
	t_img	n;
}			t_map;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}		t_keys;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	mini;
	t_img	fp;
	t_cam	cam;
	t_keys	keys;
	t_img	n;
	t_img	s;
	t_img	e;
	t_img	w;
}			t_data;

//	draw.c

void	put_pixel_to_img(t_img *i, int x, int y, int color);
void	draw_square(t_img *img, int x, int y, int size, int color);
void	draw_cam(t_data *a);
void	draw_map(t_data *a);

//	exit.c

void	exit_all(t_data *a);
int		red_cross(t_data *a);

//	keyboard.c

int		key_hook(int key, t_data *a);
int		key_down(int key, t_data *a);
int		key_up(int key, t_data *a);

//	move.c

void	move(t_data *a, int dir);
void	rl_move(t_data *a, int dir);
void	rotate(t_data *a, double da);
void	reset_screen(t_data *a);
float	add_rad(float a1, float a2);

//	ray.c

void	draw_ray(t_data *a, float ra, int i);
void	draw_rays(t_data *a);

//	draw2.c

void	render_column(t_data *a, t_ray *r, int i, t_img *img);

//	render.c

int		loop_render(t_data *a);
void	render_frame(t_data *a);
void	clear_img(t_img *i);

#endif
