/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:53:16 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/22 13:40:19 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

char	*manage_space(char *array, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	if (go_on(array, 1))
		return (NULL);
	if (array)
	{
		tab = ft_split(array, ' ');
		while (tab[i])
			i++;
		if ((i != 2 && i != 3))
			return (free_tab(tab));
		if (i == 3)
			str = stock_modif(tab, array, i);
		if (i == 2)
			str = stock_modif(tab, array, i);
		free_tab(tab);
	}
	return (str);
}

char	*check_space(char *array, int ret)
{
	char	**tab;
	char	*ret_str;
	char	*str;

	ret_str = NULL;
	str = NULL;
	if (ft_strchr(array, 'C') || ft_strchr(array, 'F'))
		array = manage_space(array, str);
	if (!array)
		return (NULL);
	tab = ft_split(array, ' ');
	if (!tab)
		free_tab(tab);
	if (tab)
	{
		if (ret == 0)
			ret_str = ft_strdup(tab[0]);
		else if (ret == 1)
			ret_str = ft_strdup(tab[1]);
		free_tab(tab);
	}
	free(str);
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
