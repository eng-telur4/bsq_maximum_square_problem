/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:04:56 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 04:45:03 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * ファイルに入ってる図の列数が指定と同じか確認する
 * @param lines ファイルを行ごとに区切った文字列配列
 * @param map_info 図の情報を格納したt_map_info型構造体
 * @return 列数がすべて指定通りだったらTRUE、そうでなかったらFALSEを返す
 */
t_bool	is_match_linenum(char **lines, t_map_info *map_info)
{
	int	i;

	i = 0;
	while (lines[i + 1] != NULL)
		i++;
	if (i != map_info->rows)
		return (FALSE);
	return (TRUE);
}

/**
 * @fn
 * ファイルに入ってる図の文字が指定と同じか確認する
 * @param lines ファイルを行ごとに区切った文字列配列
 * @param map_info 図の情報を格納したt_map_info型構造体
 * @return 文字がすべて指定通りだったらTRUE、そうでなかったらFALSEを返す
 */
t_bool	is_match_charset(char **lines, t_map_info *map_info)
{
	int	i;
	int	j;

	i = 1;
	while (lines[i] != NULL)
	{
		j = 0;
		while (lines[i][j] != '\0')
		{
			if (lines[i][j] != map_info->empty
				&& lines[i][j] != map_info->obstacle)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

/**
 * @fn
 * ファイルに入ってる図の列数がすべて同じか確認する
 * @param lines ファイルを行ごとに区切った文字列配列
 * @return 列数がすべて同じだったらTRUE、そうでなかったらFALSEを返す
 */
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

/**
 * @fn
 * 障害物が1つの行が少なくとも1つ存在するかテストする
 * @param lines ファイルを行ごとに区切った文字列配列
 * @param map_info 図の情報を格納したt_map_info型構造体
 * @return 1つでも存在すればTRUE、そうでないならFALSEを返す
 */
t_bool	is_exist_one_obstacle_line(char **lines, t_map_info *map_info)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	while (lines[i + 1] != NULL)
	{
		count = 0;
		j = 0;
		while (lines[i + 1][j] != '\0')
		{
			if (lines[i + 1][j] == map_info->obstacle)
				count++;
			j++;
		}
		if (count == 1)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

/**
 * @fn
 * ファイルのフォーマットをチェックする
 * @param lines ファイルを行ごとに区切った文字列配列
 * @return フォーマットがあってたらTRUE、そうでなかったらFALSEを返す
 */
t_bool	ft_check_format(char **lines)
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
	if (!is_exist_one_obstacle_line(lines, map_info))
		return (FALSE);
	return (TRUE);
}
