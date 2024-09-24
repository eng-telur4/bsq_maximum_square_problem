/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eng-telur4 <eng-telur4@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:47:35 by eng-telur4        #+#    #+#             */
/*   Updated: 2024/09/25 02:33:23 by eng-telur4       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

void	main_process(char *file_name)
{
	t_map_info	*map_info;
	char		*buf;
	char		**lines;
	char		**map;
	char		**answer;
	int			**map_n;
	int			**fill;
	int			max_width;
	t_bool		flag;
	int			i;
	int			j;
	int			x;
	int			y;

	buf = read_file(file_name);
	if (buf == NULL)
		return ;
	lines = read_lines(buf);
	if (lines == NULL)
	{
		free(buf);
		return ;
	}
	if (!check_format(lines))
	{
		free(buf);
		free_2d_array((void **)lines, ft_strs_count(buf, "\n"));
		ft_putstr("map error\n");
		return ;
	}
	map_info = create_map_info(lines[0]);
	if (map_info == NULL)
	{
		free(buf);
		free_2d_array((void **)lines, ft_strs_count(buf, "\n"));
		return ;
	}
	map = create_map(lines, map_info->rows);
	answer = create_map(lines, map_info->rows);
	map_n = create_map_n(lines, map_info);
	fill = create_map_n(lines, map_info);
	max_width = get_largest_square(map_info->rows, ft_strlen(lines[1]), map_n,
			fill);
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
	x = i;
	while (x >= i - max_width + 1)
	{
		y = j;
		while (y >= j - max_width + 1)
		{
			answer[x][y] = map_info->full;
			y--;
		}
		x--;
	}
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
			main_process(argv[i]);
			i++;
		}
	}
}

// https://itsfoss.com/install-woeusb-ubuntu/
