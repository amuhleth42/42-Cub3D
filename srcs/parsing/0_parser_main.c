/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:37:00 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 16:58:38 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

char	**read_file(char *path, t_data *a)
{
	t_list	*lines;
	char	**map;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		quit(a, "open : an error occured when opening file.\n");
	line = ft_strtrim(get_next_line(fd), "\n");
	if (!line)
		quit(a, "parsing : empty file.\n");
	lines = NULL;
	while (line)
	{
		ft_lstadd_back(&lines, ft_lstnew(line));
		line = ft_strtrim(get_next_line(fd), "\n");
	}
	close(fd);
	map = lst_to_split(lines);
	ft_lstclear(&lines, &free);
	return (map);
}

int	parser(int ac, char **av, t_data *a)
{
	int			line_array;
	int			i;

	i = -1;
	manage_args(a, ac, av);
	a->file_data = read_file(av[1], a);
	while (a->file_data[++i])
		printf("file data: %s\n", a->file_data[i]);
	parse_arguments(a, &a->input);
	line_array = calculat_h(a->file_data);
	printf("line array: %d\n", line_array);
	if (parse_sprite(&a->input, &a->sprite))
		quit(a, "Parse sprite failed\n");
	printf("yo\n");
	if (parse_colors(&a->input))
		quit(a, "Parse colors failed\n");
	printf("yo\n");
	if (parse_map(a->file_data + line_array, &a->cam, &a->map))
		quit(a, "Parse map failed\n");
	printf("yo\n");
	return (0);
}
