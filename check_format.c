/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:04:56 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 01:26:51 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

// lineが(0を含まない)自然数かどうかテストする
t_bool	is_natural_num(int num)
{
	int	i;

	if (num <= 0)
		return (FALSE);
	return (TRUE);
}

// (1行目が)図の情報を表しているかどうか
t_bool	is_info_def(char *line)
{
	int		len;
	char	*s1;
	char	*s2;

	len = ft_strlen(line);
	s1 = ft_substr(line, 0, len - 3);
	s2 = ft_substr(line, len - 3, len);
	// (0を含まない)自然数かどうか
	if (!is_natural_num(ft_atoi(s1)))
		return (FALSE);
	// 数字以外の部分が3文字かどうか
	if (ft_strlen(s2) != 3)
		return (FALSE);
	// 数字以外の部分が表示可能な文字であるかどうか
	if (!ft_str_is_printable(s2))
		return (FALSE);
	return (TRUE);
}

// 図の情報を構造体に格納
t_map_info	*create_map_info(char *line)
{
	t_map_info	*ret_val;
	int			len;
	char		*s1;
	char		*s2;

	len = ft_strlen(line);
	s1 = ft_substr(line, 0, len - 3);
	s2 = ft_substr(line, len - 3, 3);
	ret_val = (t_map_info *)malloc(sizeof(t_map_info));
	if (ret_val == NULL)
		return ret_val;
	ret_val->rows = ft_atoi(s1);
	ret_val->empty = s2[0];
	ret_val->obstacle = s2[1];
	ret_val->full = s2[2];
	return (ret_val);
}

// 行数が指定と同じかどうか
t_bool	is_match_linenum(char **lines, t_map_info *val)
{
	int	i;

	i = 0;
	while (lines[i + 1] != NULL)
		i++;
	if (i != val->rows)
		return (FALSE);
	return (TRUE);
}

// 文字が指定と同じかどうか
t_bool	is_match_charset(char **lines, t_map_info *val)
{
	int	i;
	int	j;

	i = 1;
	while (lines[i] != NULL)
	{
		j = 0;
		while (lines[i][j] != '\0')
		{
			if (lines[i][j] != val->empty && lines[i][j] != val->obstacle)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

// 列数がすべて同じかどうか
t_bool	is_same_column(char **lines)
{
	int	i;

	i = 1;
	while (lines[i + 1] != NULL)
	{
		if (ft_strlen(lines[i]) != ft_strlen(lines[i + 1]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// フォーマットをチェックする
t_bool	check_format(char **lines)
{
	t_map_info	*map_info;

	// (1行目が)図の情報を表しているかどうか
	if (!is_info_def(lines[0]))
	{
		ft_putstr("[FAILED] info def\n");
		return (FALSE);
	}
	map_info = create_map_info(lines[0]);
	ft_putstr("rows : ");
	ft_putnbr(map_info->rows);
	ft_putstr(", empty : '");
	ft_putchar(map_info->empty);
	ft_putstr("', obstacle : '");
	ft_putchar(map_info->obstacle);
	ft_putstr("', full : '");
	ft_putchar(map_info->full);
	ft_putstr("'\n");
	// 行数が指定と同じかどうか
	if (!is_match_linenum(lines, map_info))
	{
		ft_putstr("[FAILED] match linenum\n");
		return (FALSE);
	}
	// 列数がすべて同じかどうか
	if (!is_same_column(lines))
	{
		ft_putstr("[FAILED] same column\n");
		return (FALSE);
	}
	// 文字がすべて指定(emptyかobstacle)と同じかどうか
	if (!is_match_charset(lines, map_info))
	{
		ft_putstr("[FAILED] match charset\n");
		return (FALSE);
	}
	return (TRUE);
}
