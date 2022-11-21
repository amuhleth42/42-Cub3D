/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:53:16 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 15:21:48 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_params(t_args *input)
{
	int	i;

	i = 0;
	while (input->input[i])
	{
		printf("params =	%s\n", input->input[i]);
		i++;
	}
}

void	print_map(t_map *pars)
{
	int	i;

	i = -1;
	while (pars->map[++i])
		printf("%s\n", pars->map[i]);
}

char	*manage_space(char *array)
{
	char	*str;
	char	**tab;
	int		i;

	str = NULL;
	i = -1;
	if ((ft_strchr(array, 'C')) || (ft_strchr(array, 'F')))
		str = array;
	if (str)
	{
		tab = ft_split(str, ' ');
		while (tab[i])
			i++;
		if (i == 3)
		{
			tab[1] = ft_strjoin(tab[1], tab[2]);
			tab[0] = ft_strjoin(tab[0], " ");
			str = ft_strjoin(tab[0], tab[1]);
			while (--i >= 0)
				free(tab[i]);
			tab = NULL;
		}
		array = str;
	}
	return (array);
}

char	*check_space(char *array, int ret)
{
	char	**str;
	char	*ret_str;

	ret_str = NULL;
	if (ft_strchr(array, 'C') || ft_strchr(array, 'F'))
		array = manage_space(array);
	str = ft_split(array, ' ');
	if (ret == 0)
		ret_str = str[0];
	else
		ret_str = str[1];
	return (ret_str);
}

t_text	struct_init(t_text *dirct)
{
	dirct->ea = 0;
	dirct->we = 0;
	dirct->no = 0;
	dirct->so = 0;
	dirct->f = 0;
	dirct->c = 0;
	return (*dirct);
}
