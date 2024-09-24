/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:36:53 by totake            #+#    #+#             */
/*   Updated: 2024/09/22 22:29:12 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 文字cが文字列charsetにある各文字のどれかと一致しているかどうか判定する関数
 * @param c 比較対象の文字
 * @param charset 比較対象の文字列
 * @return 一致する文字があった場合は1を、それ以外は0を返す
 */
int	ft_c_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * @fn
 * 文字列charsetにある各文字に応じて、文字列strをj文字目から分割した場合、
 * 次の分割後の単語の開始地点、もしくは単語の終端地点ののアドレスを返す
 * @param str 分割目標のヌル終端文字列
 * @param charset 分割対象の文字を列挙したヌル終端文字列
 * @param j 何文字目から捜査するか
 * @param flag 最初を検出するか(=1)、最後を検出するか(=0)のフラグ
 * @return 次の分割後の単語の開始地点、もしくは単語の終端地点ののアドレスを返す
 */
int	find_start_end(char *str, char *charset, int *j, int flag)
{
	if (flag)
	{
		while (str[*j] && ft_c_is_charset(str[*j], charset))
			*j = *j + 1;
		return (*j);
	}
	else
	{
		while (str[*j] && !ft_c_is_charset(str[*j], charset))
			*j = *j + 1;
		return (*j);
	}
}

/**
 * @fn
 * 文字列charsetにある各文字に応じて、文字列を分割する。
 * charset文字列にある各文字は、str文字列を分割するために使用される。
 * @param str 分割目標のヌル終端文字列
 * @param charset 分割対象の文字を列挙したヌル終端文字列
 * @return charset文字列にある各文字がstr文字列を分割し、分割された
 * 文字列の要素数を返す。
 */
int	ft_strs_count(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_c_is_charset(str[i], charset))
			i++;
		if (str[i] && !ft_c_is_charset(str[i], charset))
			count++;
		while (str[i] && !ft_c_is_charset(str[i], charset))
			i++;
	}
	return (count);
}

/**
 * @fn
 * 文字列charsetにある各文字に応じて、文字列を分割する。
 * @param str 分割目標のヌル終端文字列
 * @param charset 分割対象の文字を列挙したヌル終端文字列
 * @return charset文字列にある各文字がstr文字列を分割し、分割された
 * 文字列の配列を返す。配列の最後の要素は、配列の最後であることを示すために
 * 0が代入される。
 * @attention 文字列strが空だった場合、もしくはメモリ確保(malloc)に失敗した場合はNULLを返す。
 */
char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;
	int		j;
	int		start;
	int		strs_count;

	i = -1;
	j = 0;
	strs_count = ft_strs_count(str, charset);
	ret = (char **)malloc(sizeof(char *) * (strs_count + 1));
	if (ret == NULL)
		return (NULL);
	while (++i < strs_count)
	{
		start = find_start_end(str, charset, &j, 1);
		ret[i] = ft_substr(str, start, find_start_end(str, charset, &j, 0)
				- start);
		if (ret[i] == NULL)
		{
			free_2d((void **)ret, i);
			return (NULL);
		}
	}
	ret[i] = NULL;
	return (ret);
}
