/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:47:35 by eng-telur4        #+#    #+#             */
/*   Updated: 2024/09/25 01:45:28 by skamijo          ###   ########.fr       */
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

	// ファイルを読み込む
	buf = read_file(file_name);
	if (buf == NULL)
	{
		ft_putstr("[FAILED] reading file\n");
		return ;
	}
	ft_putstr("reading file was successful\n");
	// 列ごとに分割する
	lines = read_lines(buf);
	if (lines == NULL)
	{
		ft_putstr("[FAILED] split to line\n");
		free(buf);
		return ;
	}
	ft_putstr("split to line was successful\n");
	// フォーマットをチェックする
	if (!check_format(lines))
	{
		free(buf);
		free_2d_all((void **)lines);
		ft_putstr("map error\n");
		return ;
	}
	ft_putstr("correct file format\n");
	// 情報を構造体に格納する
	map_info = create_map_info(lines[0]);
	if (map_info == NULL)
	{
		free(buf);
		free_2d_all((void **)lines);
		ft_putstr("[FAILED] create map info\n");
		return ;
	}
	ft_putstr("complete create map info\n");
	ft_putstr("rows : ");
	ft_putnbr(map_info->rows);
	ft_putstr(", empty : '");
	ft_putchar(map_info->empty);
	ft_putstr("', obstacle : '");
	ft_putchar(map_info->obstacle);
	ft_putstr("', full : '");
	ft_putchar(map_info->full);
	ft_putstr("'\n");
	map = create_map(lines, map_info->rows);
	ft_putstr("complete create map\n");
	answer = create_map(lines, map_info->rows);
	ft_putstr("complete create answer\n");
	map_n = create_map_n(lines, map_info);
	ft_putstr("complete create map_n\n");
	fill = create_map_n(lines, map_info);
	ft_putstr("complete create fill\n");
	display_map(map_info, map);
	display_map(map_info, answer);
	display_map_n(map_info, map_n);
	display_map_n(map_info, fill);
	max_width = get_largest_square(map_info->rows, ft_strlen(lines[1]), map_n,
			fill);
	display_map_n(map_info, map_n);
	display_map_n(map_info, fill);
	ft_putnbr(max_width);
	ft_putstr("\n");
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
	ft_putstr("i : ");
	ft_putnbr(i);
	ft_putstr(", j : ");
	ft_putnbr(j);
	ft_putstr("\n");
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
