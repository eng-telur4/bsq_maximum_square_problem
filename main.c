/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:47:35 by eng-telur4        #+#    #+#             */
/*   Updated: 2024/09/25 03:21:27 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

char	**check_file_format(char *file_name)
{
	char		*buf;
	char		**lines;

	buf = read_file(file_name);
	if (buf == NULL)
		return (NULL);
	lines = read_lines(buf);
	if (lines == NULL)
	{
		free(buf);
		return (NULL);
	}
	if (!ft_check_format(lines))
	{
		free(buf);
		free_2d_array((void **)lines, get_line_countl(lines));
		ft_putstr("map error\n");
		return (NULL);
	}
	free(buf);
	return (lines);
}

void	find_max_width(int max_width, t_map_info *map_info, int **fill,
		t_point_2d *point)
{
	t_bool	flag;
	int		i;
	int		j;

	flag = FALSE;
	i = 0;
	while (i < map_info->rows)
	{
		j = 0;
		while (fill[i][j] != -1)
		{
			if (fill[i][j] == max_width)
			{
				flag = TRUE;
				break ;
			}
			j++;
		}
		if (flag)
			break ;
		i++;
	}
	point->x = i;
	point->y = j;
}

void	reflect_answer(int **fill, char **answer, t_map_info *map_info,
		int max_width)
{
	t_point_2d	point;
	int			i;
	int			j;

	find_max_width(max_width, map_info, fill, &point);
	i = point.x;
	while (i >= point.x - max_width + 1)
	{
		j = point.y;
		while (j >= point.y - max_width + 1)
		{
			answer[i][j] = map_info->full;
			j--;
		}
		i--;
	}
}

void	main_process(char **lines)
{
	t_map_info	*map_info;
	char		**answer;
	int			**map_n;
	int			**fill;
	int			max_width;

	map_info = create_map_info(lines[0]);
	if (map_info == NULL)
	{
		free_2d_array((void **)lines, get_line_countl(lines));
		return ;
	}
	answer = create_map(lines, map_info->rows);
	init_map(lines, answer);
	map_n = create_map_n(lines, map_info);
	init_map_n(lines, map_n, map_info);
	fill = create_map_n(lines, map_info);
	init_map_n(lines, fill, map_info);
	max_width = ft_calc_max_square(map_info->rows, ft_strlen(lines[1]), map_n,
			fill);
	reflect_answer(fill, answer, map_info, max_width);
	display_map(map_info, answer);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**lines;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			lines = check_file_format(argv[i]);
			if (lines != NULL)
				main_process(lines);
			i++;
		}
	}
}

// https://itsfoss.com/install-woeusb-ubuntu/
