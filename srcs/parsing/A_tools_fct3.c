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

char	*free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}
//		printf("tab[%d]  %s\n", i, tab[i]);

char	*manage_array_n(char *array)
{
	free(array);
	return (NULL);
}

void	free_all(t_text *dirct, char *str1, char *str2)
{
	if (!dirct->f && !dirct->c)
	{
		if (str1)
			free(str1);
		if (str2)
			free(str2);
	}
}
