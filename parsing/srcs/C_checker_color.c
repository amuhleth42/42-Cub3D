/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:41 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 14:11:45 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0_parser_maps.h"

int	travel_number(char *str1, char *str2, char *str3)
{
	int	i;

	i = 0;
	while (ft_isdigit(str1[i]))
		i++;
	if (i != (int)ft_strlen(str1))
		return (1);
	i = 0;
	while (ft_isdigit(str2[i]))
		i++;
	if (i != (int)ft_strlen(str2))
		return (1);
	i = 0;
	while (ft_isdigit(str3[i]))
		i++;
	if (i != (int)ft_strlen(str3))
		return (1);
	return (0);
}

int	manage_digit_color(char *str1, char *str2, char *str3)
{
	int	i;

	i = 0;
	if (ft_strlen(str1) > 3 || !ft_strlen(str1)
		|| (ft_strlen(str2) > 3 || !ft_strlen(str2))
		|| ft_strlen(str3) > 3 || !ft_strlen(str3))
		return (1);
	if (travel_number(str1, str2, str3))
		return (1);
	if (!ft_isalnum(str1[i]) || (!ft_isalnum(str2[i]))
		|| (!ft_isalnum(str3[i])))
		return (1);
	if ((ft_atoi(str1) > 255 || ft_atoi(str1) < 0)
		|| (ft_atoi(str2) > 255 || ft_atoi(str2) < 0)
		|| (ft_atoi(str3) > 255 || ft_atoi(str3) < 0))
		return (1);
	return (0);
}
//	printf("%d	%d	%d\n", ft_atoi(str1), ft_atoi(str2), ft_atoi(str3));

int	check_space_color(char *array)
{
	char	**str;
	char	*ret_str;
	int		i;

	i = 0;
	ret_str = NULL;
	str = ft_split(array, ' ');
	while (str[i])
		i++;
	if (i != 1)
		return (1);
	str = ft_split(str[0], ',');
	while (str[i])
		i++;
	if (i != 3)
		return (1);
	if (manage_digit_color(str[0], str[1], str[2]))
	{
		printf("ko\n");
		return (1);
	}
	return (0);
}
//	if (!check_path(str[1]))
//		return (NULL);

int	check_code_c(t_color *color, char *str)
{
	int	i;

	(void) color;
	i = 0;
	if (!ft_isalnum(str[i]) && str[i])
	{
		if (check_space_color(str))
			return (1);
		return (0);
	}
	if (check_space_color(str))
		return (1);
	return (0);
}

int	manage_path_dirct_c(t_color *color, t_text *dirct, char *str, int ret)
{
	if (ret == 1)
	{
		if (check_code_c(color, str))
			return (1);
		color->f = str;
		dirct->f++;
	}
	if (ret == 2)
	{
		if (check_code_c(color, str))
			return (1);
		color->c = str;
		dirct->c++;
	}
	return (0);
}
//	printf("check_S %s\n", str);
