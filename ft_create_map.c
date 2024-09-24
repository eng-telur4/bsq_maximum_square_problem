/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:08:54 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 04:02:10 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 図の情報をt_map_info型構造体に格納する
 * @param line 図の情報が入ってる文字列(1行目)
 * @return 作成したt_map_info型構造体のポインタ
 * @attention メモリ確保(malloc)できなかった場合はNULLが返る
 */
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
		return (ret_val);
	ret_val->rows = ft_atoi(s1);
	ret_val->empty = s2[0];
	ret_val->obstacle = s2[1];
	ret_val->full = s2[2];
	return (ret_val);
}

/**
 * @fn
 * (文字ベースの)図を入れる領域を確保する
 * @param lines 図が入ってる文字列配列
 * @param row_len 図の行数
 * @return 作成した図が入っている二次元配列のポインタ
 * @attention メモリ確保(malloc)できなかった場合はNULLが返る
 */
char	**create_map(char **lines, int row_len)
{
	int		i;
	char	**ret_val;
	int		col_len;

	i = 0;
	ret_val = (char **)malloc((row_len + 1) * sizeof(char *));
	if (ret_val == NULL)
		return (NULL);
	col_len = ft_strlen(lines[1]);
	while (i < row_len)
	{
		ret_val[i] = (char *)malloc((col_len + 1) * sizeof(char));
		if (ret_val[i] == NULL)
		{
			free_2d_array_en_route((void **)ret_val, i);
			return (NULL);
		}
		i++;
	}
	ret_val[i] = NULL;
	return (ret_val);
}

/**
 * @fn
 * (文字ベースの)図をコピーする
 * @param lines 図が入ってる文字列配列
 * @param map 図が入っている二次元配列のポインタ
 */
void	init_map(char **lines, char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_strcpy(map[i], lines[i + 1]);
		i++;
	}
}

/**
 * @fn
 * (数字ベースの)図を入れる領域を確保する
 * @param lines 図が入ってる文字列配列
 * @param map_info 図の情報を格納したt_map_info型構造体
 * @return 作成した図が入っている二次元配列のポインタ
 * @attention メモリ確保(malloc)できなかった場合はNULLが返る
 */
int	**create_map_n(char **lines, t_map_info *map_info)
{
	int	i;
	int	**ret_val;
	int	col_len;

	i = 0;
	ret_val = (int **)malloc((map_info->rows + 1) * sizeof(int *));
	if (ret_val == NULL)
		return (NULL);
	col_len = ft_strlen(lines[1]);
	while (i < map_info->rows)
	{
		ret_val[i] = (int *)malloc((col_len + 1) * sizeof(int));
		if (ret_val[i] == NULL)
		{
			free_2d_array_en_route((void **)ret_val, i);
			return (NULL);
		}
		i++;
	}
	ret_val[i] = NULL;
	return (ret_val);
}

/**
 * @fn
 * (数字ベースの)図をコピーする
 * @param lines 図が入ってる文字列配列
 * @param map_n 図が入っている二次元配列のポインタ
 * @param map_info 図の情報を格納したt_map_info型構造体
 */
void	init_map_n(char **lines, int **map_n, t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i + 1] != NULL)
	{
		j = 0;
		while (lines[i + 1][j] != '\0')
		{
			if (lines[i + 1][j] == map_info->empty)
				map_n[i][j] = 0;
			else
				map_n[i][j] = 1;
			j++;
		}
		map_n[i][j] = -1;
		i++;
	}
}
