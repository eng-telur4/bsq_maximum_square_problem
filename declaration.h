/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:41:48 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 04:44:16 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATION_H
# define DECLARATION_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # define DEBUG

// 2次元情報を表すt_point_2d型構造体
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

// 2次元情報型
typedef struct s_point_2d
{
	int		x;
	int		y;
}			t_point_2d;

// ft_read_stdin.c
char		*read_stdin(void);

// ft_file_io.c
char		*read_file(char *file_name);
int			get_file_size(char *file_name);
char		**read_lines(char *buf);
// int			get_line_count(char *buf);
int			get_line_countl(char **lines);

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

// ft_check_format.c
t_bool		ft_check_format(char **lines);
// t_bool		is_match_linenum(char **lines, t_map_info *map_info);
// t_bool		is_match_charset(char **lines, t_map_info *map_info);
// t_bool		is_same_column(char **lines);
// t_bool		is_exist_one_obstacle_line(char **lines, t_map_info *map_info);

// ft_is_info_def.c
t_bool		is_not_same_char(char c1, char c2, char c3);
t_bool		is_natural_num(int num);
t_bool		is_info_def(char *line);

// ft_strlen.c
int			ft_strlen(char *s);

// ft_atoi.c
int			ft_atoi(char *str);
// int			ft_isspace(char c);

// ft_str_is_printable.c
int			ft_str_is_printable(char *str);

// ft_create_map.c
t_map_info	*create_map_info(char *line);
char		**create_map(char **lines, int row_len);
int			**create_map_n(char **lines, t_map_info *map_info);
void		init_map(char **lines, char **map);
void		init_map_n(char **lines, int **map_n, t_map_info *map_info);

// ft_display_map.c
void		display_map(t_map_info *map_info, char **map);
void		display_map_n(t_map_info *map_info, int **map);

// ft_strcpy.c
char		*ft_strcpy(char *dest, char *src);

// ft_calc_max_square.c
int			ft_calc_max_square(int h, int w, int **g_g, int **g_dp);
// int	calc_one(int h, int w, int **g_g, int **g_dp);

// ft_min_max.c
int			min(int a, int b);
int			max(int a, int b);

// ft_putnbr.c
void		ft_putnbr(int nb);

// ft_putchar.c
void		ft_putchar(char c);

#endif
