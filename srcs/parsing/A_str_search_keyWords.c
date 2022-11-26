/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_str_search_keyWords.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:50:25 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/22 23:50:29 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*stock_modif(char **tab, char *array, int i)
{
	char	*tmp;
	char	*tmp2;
	char	*str;

	if (i == 3)
	{
		tmp = ft_strjoin(tab[1], tab[2]);
		tmp2 = ft_strjoin(tab[0], " ");
		str = ft_strjoin(tmp2, tmp);
		free(tmp2);
	}
	if (i == 2)
	{
		tmp = ft_strjoin(tab[0], " ");
		str = ft_strjoin(tmp, tab[1]);
	}
	ft_strlcpy(array, str, ft_strlen(str) + 1);
	free(tmp);
	free(str);
	return (array);
}

int	manage_nb_player(int player_nb)
{
	if (!player_nb)
		return (manage_map_error(0, 0, 0, 0));
	if (player_nb > 1)
		return (manage_map_error(0, 0, 0, 4));
	return (1);
}

int	manage_letter_sprite(char *str, int i)
{
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		return (1);
	else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		return (1);
	else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		return (1);
	else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		return (1);
	return (0);
}

int	manage_letter_color(char *str, int i)
{
	if ((str[i] == 'C' && str[i + 1] == ' '))
	{
		if (i >= 1 && (str[i - 1] != 'F' && str[i - 1] != 'C'))
			return (1);
		if (i == 0)
			return (1);
	}
	if ((str[i] == 'F' && str[i + 1] == ' '))
	{
		if (i >= 1 && (str[i - 1] != 'C' && str[i - 1] != 'F'))
			return (1);
		if (i == 0)
			return (1);
	}
	return (0);
}
//	printf("str = %d	%s	%d\n", (int)ft_strlen(str), str, i);

int	ret_space(char *str, int ret)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ret == 1)
		{
			if (manage_letter_sprite(str, i))
				return (0);
		}
		if (ret == 2)
		{
			if (manage_letter_color(str, i))
				return (0);
		}
		i++;
	}
	return (1);
}
