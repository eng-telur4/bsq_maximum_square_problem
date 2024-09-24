/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eng-telur4 <eng-telur4@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:04:56 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 02:32:03 by eng-telur4       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

// (1行目が)図の情報を表しているかどうか
t_bool	is_info_def(char *line)
{
	int		len;
	char	*s1;
	char	*s2;

	len = ft_strlen(line);
	s1 = ft_substr(line, 0, len - 3);
	s2 = ft_substr(line, len - 3, len);
	if (ft_atoi(s1) <= 0)
		return (FALSE);
	if (ft_strlen(s2) != 3)
		return (FALSE);
	if (!ft_str_is_printable(s2))
		return (FALSE);
	return (TRUE);
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

	if (!is_info_def(lines[0]))
		return (FALSE);
	map_info = create_map_info(lines[0]);
	if (!is_match_linenum(lines, map_info))
		return (FALSE);
	if (!is_same_column(lines))
		return (FALSE);
	if (!is_match_charset(lines, map_info))
		return (FALSE);
	return (TRUE);
}
