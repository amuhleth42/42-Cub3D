

#include "cub3d.h"
#include <stdio.h>

int	key_hook(int key, t_data *a)
{
	(void)a;
	printf("key: %d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

int	key_down(int key, t_data *a)
{
	if (key == 13)
		move(a, 1, 1);
	if (key == 1)
		move(a, -1, -1);
	if (key == 0)
		rl_move(a, -1, -1);
	if (key == 2)
		rl_move(a, 1, 1);
	if (key == 123)
		rotate(a, -0.1);
	if (key == 124)
		rotate(a, 0.1);
	return (0);
}
