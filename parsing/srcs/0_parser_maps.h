/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_maps.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:13:56 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 11:14:32 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSER_MAPS_H
# define PARSER_MAPS_H

# define      COL_RED        "\033[31;1m"
# define      COL_RES        "\033[0m"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../../libft/libft.h"
# include "../../cub3d.h"

typedef struct s_tools
{
	int	len;
	int	idx;
	int	x;
	int	y;
	int	hparams;
}	t_tools;

typedef struct s_args
{
	char	**input;
	int		x;
	int		y;
}	t_args;

typedef struct s_color
{
	char	**tab;
	int		x;
	int		y;
	char	*c;
	char	*f;
}	t_color;

typedef struct s_sprite
{
	char	**tab;
	int		x;
	int		y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_sprite;

typedef struct s_text
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_text;

/*	parser_main.c */
char	**read_file(char *path, t_data *a);
char	**lst_to_split(t_list *lines);
int		manage_args(int ac, char **av);

/*	parser_color.c */
int		parse_colors(t_args *input);
int		check_color(char *array, t_text *dirct, t_color *color);
int		check_the_rest_color(char *input);

/*	checker_color.c */
int		manage_path_dirct_c(t_color *color, t_text *dirct, char *str, int ret);
int		check_code_c(t_color *color, char *str);
int		check_space_color(char *array);
int		manage_digit_color(char *str1, char *str2, char *str3);
int		travel_number(char *str1, char *str2, char *str3);

/*	parser_sprite.c */
int		parse_sprite(t_args *input, t_sprite *sprite);
int		check_sprite(char *array, t_text *dirct, t_sprite *sprite);
int		check_the_rest_sprite(char *input);

/*	checker_sprite.c */
int		manage_path_dirct_s(t_sprite *sprite, t_text *dirct, char *str, int r);
int		check_path_s(t_sprite *sprite, char *str, int ret);
char	check_path(char *array);

/*	parser_map.c */
int		parse_map(char **lines, t_cam *cam, t_map *map);
int		check_map(t_map *map);

/*	stock_arguments.c */
void	fill_input(char **file_data, t_args *input);
int		create_input(t_args *input);
void	reset_input(t_args *input);
int		parse_input_size(char **file_data, t_args *input);
int		parse_arguments(char **file_data, t_args *input);

/*	stock_map.c */
int		fill_map(char **lines, t_map *map, t_cam *cam);
int		parse_player(char c, int y, int x, t_cam *cam);
int		create_map(t_map *map);
void	reset_map(t_map *map);

/*	tools_fcts.c */
t_text	struct_init(t_text *dirct);
char	*check_space(char *array, int ret);
void	print_map(t_map *pars);
int		find_first_occurrence(t_args *input);

/*	height_calculator.c */
int		parse_map_size(char **lines, t_map *map);
int		calculat_h(char **file_data);

/*	error_manager */
int		manage_args(int ac, char **av);
int		print_error(int ret, int cause);
int		manage_map_error(char *line, int y, int x, int err);

/*	color.c */
void	colorTheChar(char **tab, int H, int L);
void	colorFirst(char *str);
void	colorTheRest(char *str, int H, int index);
void	colorLast(char *str, int H);

#endif //INC_42_CUB3D_MAPS_H
