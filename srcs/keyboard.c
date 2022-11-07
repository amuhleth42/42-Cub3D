

#include "cub3d.h"
#include <stdio.h>

int	key_hook(int key, t_data *a)
{
	(void)a;
	if (key == 53)
		exit(0);
	return (0);
}

int	key_down(int key, t_data *a)
{
	if (key == 13)
		move(a, 0, -4);
	if (key == 1)
		move(a, 0, 4);
	if (key == 0)
		move(a, -4, 0);
	if (key == 2)
		move(a, 4, 0);
	return (0);
}
