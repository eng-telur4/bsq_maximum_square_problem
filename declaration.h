/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eng-telur4 <eng-telur4@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:41:48 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 02:26:29 by eng-telur4       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATION_H
# define DECLARATION_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # define DEBUG

// 図の情報型
typedef struct s_map_info
{
	int		rows;
	char	empty;
	char	obstacle;
	char	full;
}			t_map_info;

// 真偽値
typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

// ft_file_io.c
char		*read_file(char *file_name);
int			get_file_size(char *file_name);
char		**read_lines(char *buf);
// int			get_line_count(char *buf);
// int			get_line_countl(char **lines);

// ft_putstr.c
void		ft_putstr(char *str);

// ft_split.c
char		**ft_split(char *str, char *charset);
int			ft_strs_count(char *str, char *charset);
int			find_start_end(char *str, char *charset, int *j, int flag);
int			ft_c_is_charset(char c, char *charset);

// ft_substr.c
char		*ft_substr(char *str, int start, int len);

// ft_free.c
void		free_2d_array(void **array, int h);
void		free_2d_array_en_route(void **arr, int i);

// check_format.c
t_bool		check_format(char **lines);
// t_bool		is_info_def(char *line);
// t_bool		is_match_linenum(char **lines, t_map_info *val);
// t_bool		is_match_charset(char **lines, t_map_info *val);
// t_bool		is_same_column(char **lines);

// ft_strlen.c
int			ft_strlen(char *s);

// ft_atoi.c
int			ft_atoi(char *str);
// int			ft_isspace(char c);

// ft_str_is_printable.c
int			ft_str_is_printable(char *str);

// map.c
t_map_info	*create_map_info(char *line);
char		**create_map(char **lines, int row_len);
int			**create_map_n(char **lines, t_map_info *map_info);
void		display_map(t_map_info *map_info, char **map);
void		display_map_n(t_map_info *map_info, int **map);

// ft_strcpy.c
char		*ft_strcpy(char *dest, char *src);

// get_largest_square.c
int			get_largest_square(int h, int w, int **g_g, int **g_dp);

// ft_min_max.c
int			min(int a, int b);
int			max(int a, int b);

// ft_putnbr.c
void		ft_putnbr(int nb);

// ft_putchar.c
void		ft_putchar(char c);

#endif
