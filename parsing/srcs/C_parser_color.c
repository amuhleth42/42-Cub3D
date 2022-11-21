/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:05:31 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 14:05:33 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0_parser_maps.h"

int	check_the_rest_color(char *input)
{
	char	**new_array;
	int		args;

	args = 0;
	new_array = ft_split(input, ',');
	while (new_array[args])
		args++;
	return (args);
}

int	check_color(char *array, t_text *dirct, t_color *color)
{
	int		i;
	char	*tmp_color;

	i = 0;
	tmp_color = check_space(array, 1);
	if (!ft_isalpha(array[i]) && array[i])
		array = check_space(array, 0);
	if (!dirct->f || !dirct->c)
	{
		if (!array || !tmp_color)
			return (0);
		if ((array[0] != 'F' && array[0] != 'C') && !ft_isalnum(array[1]))
			return (0);
	}
	if (!ft_strncmp(array, "F", 1))
		manage_path_dirct_c(color, dirct, tmp_color, 1);
	else if (!ft_strncmp(array, "C", 1))
		manage_path_dirct_c(color, dirct, tmp_color, 2);
	printf("F=%d	C=%d\n", dirct->f, dirct->c);
	if (dirct->f == 1 && dirct->c == 1)
		return (2);
	return (0);
}
//	printf("len array = %lu	%s\n", ft_strlen(array), array);

int	parse_colors(t_args *input)
{
	int		idx_color;
	t_text	dirct;
	t_color	color;

	input->y = 0;
	idx_color = 0;
	struct_init(&dirct);
	while (input->input[input->y])
	{
		idx_color = check_color(input->input[input->y], &dirct, &color);
		if (idx_color == 2 && input->input[input->y + 1] == 0)
		{
			if (check_the_rest_color(input->input[input->y]) != 2)
				break ;
		}
		input->y++;
	}
	if (idx_color != 2)
		print_error(3, 0);
	return (0);
}
