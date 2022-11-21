/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:51:25 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 11:51:30 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0_parser_maps.h"

int	manage_args(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac != 2)
	{
		printf("less arguments\n", stderr);
		return (1);
	}
	if (av[0])
	{
		while (av[++i])
		{
			if (!av[i])
			{
				printf("arguments is NULL\n", stderr);
				return (1);
			}
		}
	}
	return (0);
}

void	print_right_line(char *line, int x)
{
	int	i;

	i = -1;
	if (x != 0)
	{
		while (++i <= (int)ft_strlen(line))
		{
			printf("%c", line[i]);
			if (i == x)
				printf("%s'%c' => '%c'%s ", COL_RED, line[i - 1],
					line[i], COL_RES);
		}
		printf("\n");
	}
	else
	{
		while (++i <= (int)ft_strlen(line))
		{
			if (i == x)
				printf("%s'%c' <= '%c'%s", COL_RED, line[i - 1],
					line[i], COL_RES);
			printf("%c", line[i]);
		}
		printf("\n");
	}
}

int	manage_map_error(char *line, int y, int x, int err)
{
	printf("\n%sThere is an error on line:	%d%s\n\n", COL_RED, y, COL_RES);
	if (err == 1)
		print_right_line(line, x);
	if (err == 2)
		print_right_line(line, x);
	if (err == 3)
		print_right_line(line, x);
	return (1);
}

int	print_error(int ret, int cause)
{
	if (ret == 0)
	{
		if (cause == 1)
			printf("crash because of size\n", stderr);
		else if (cause == 2)
			printf("crash because of creation tab\n", stderr);
	}
	if (ret == 1)
		printf("crash 1\n", stderr);
	if (ret == 2)
		printf("crash 2\n", stderr);
	if (ret == 3)
		printf("crash 3\n", stderr);
	if (ret == 4)
		printf("crash 4\n", stderr);
	if (ret == 5)
		printf("crash 5\n", stderr);
	return (1);
}
