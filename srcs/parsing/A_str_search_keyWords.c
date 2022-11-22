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
	if (str[i] == 'C' && str[i + 1] == ' ')
		return (1);
	if (str[i] == 'F' && str[i + 1] == ' ')
		return (1);
	return (0);
}

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
