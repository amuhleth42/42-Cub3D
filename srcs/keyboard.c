

#include "cub3d.h"

int	key_hook(int key, t_data *a)
{
	(void)a;
	if (key == 53)
		exit(0);
	return (0);
}
