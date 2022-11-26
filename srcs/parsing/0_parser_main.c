/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:37:00 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/22 14:05:24 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	**lst_to_split(t_list *lines)
{
	char	**map;
	int		size;
	int		i;

	size = ft_lstsize(lines);
	map = ft_calloc(size + 1, sizeof(char *));
	i = 0;
	while (lines)
	{
		map[i] = ft_strdup(lines->content);
		lines = lines->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**read_file(t_list *lst_l, char *path, t_data *a)
{
	char	**map;
	char	*line;
	char 	*ret;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		quit(a, "Error: open failed");
	ret = get_next_line(fd);
	line = ft_strtrim(ret, "\n");
	free(ret);
	if (!line)
		quit(a, "Error: parsing: empty file");
	lst_l = NULL;
	while (line)
	{
		ft_lstadd_back(&lst_l, ft_lstnew(line));
		ret = get_next_line(fd);
		line = ft_strtrim(ret, "\n");
		free(ret);
	}
	close(fd);
	map = lst_to_split(lst_l);
	ft_lstclear(&lst_l, &free);
	return (map);
}

void	free_input(t_data *a)
{
	int	i;

	i = 0;
	while (a->input.input[i] != NULL)
	{
		free(a->input.input[i]);
		a->input.input[i] = NULL;
		i++;
	}
	if (a->input.input != NULL)
	{
		free(a->input.input);
		a->input.input = NULL;
	}
}

void	free_parser(t_data *a)
{
	if (a->input.input)
		free_input(a);
	if (a->sprite.no)
		free(a->sprite.no);
	if (a->sprite.so)
		free(a->sprite.so);
	if (a->sprite.we)
		free(a->sprite.we);
	if (a->sprite.ea)
		free(a->sprite.ea);
}

int	parser(int ac, char **av, t_data *a)
{
	int		line_array;
	t_list 	lst_l;

	manage_args(a, ac, av);
	a->file_data = read_file(&lst_l, av[1], a);
	parse_arguments(a, &a->input);
	line_array = calculat_h(a->file_data);
	if (parse_sprite(a, &a->input, &a->sprite))
		quit(a, "Error: Parse sprite failed");
	if (parse_colors(a, &a->input))
		quit(a, "Error: Parse colors failed");
	if (parse_map(a->file_data + line_array, &a->cam, &a->map))
		quit(a, "Error: Parse map failed");
	return (0);
}

// 2 leaks strjoin.