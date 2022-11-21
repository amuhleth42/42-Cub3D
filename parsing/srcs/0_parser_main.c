/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:37:00 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 11:37:06 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0_parser_maps.h"

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

//		exit_all(a);
char	**read_file(char *path, t_data *a)
{
	t_list	*lines;
	char	**map;
	char	*line;
	int		fd;

	(void) a;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		printf("open : an error occured when opening file.\n", stderr);
	line = ft_strtrim(get_next_line(fd), "\n");
	if (!line)
	{
		printf("parsing : empty file.\n", stderr);
	}
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

int	main(int ac, char **av)
{
	t_data		data;
	t_args		input;
	t_sprite	sprite;
	char		**file_data;
	int			line_array;

	manage_args(ac, av);
	file_data = read_file(av[1], &data);
	print_error(0, parse_arguments(file_data, &input));
	line_array = calculat_h(file_data);
	if (parse_sprite(&input, &sprite))
		print_error(2, 0);
	if (parse_colors(&input))
		print_error(4, 0);
	if (parse_map(file_data + line_array, &data.cam, &data.map))
		print_error(5, 0);
	return (0);
}
