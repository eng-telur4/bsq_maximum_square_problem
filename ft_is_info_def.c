/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_info_def.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 04:42:49 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 04:42:52 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 3つの引数がすべて違う種類の文字かどうか
 * @param c1 対象の文字
 * @param c2 対象の文字
 * @param c3 対象の文字
 * @return すべて違う種類の文字ならTRUE、そうでないならFALSEを返す
 */
t_bool	is_not_same_char(char c1, char c2, char c3)
{
	if (c1 != c2 && c2 != c3 && c3 != c1)
		return (TRUE);
	return (FALSE);
}

/**
 * @fn
 * 引数が0を除いた自然数かどうか
 * @param num 対象の整数
 * @return 自然数ならTRUE、そうでないならFALSEを返す
 */
t_bool	is_natural_num(int num)
{
	if (num <= 0)
		return (FALSE);
	return (TRUE);
}

/**
 * @fn
 * 図の情報を表す構造になっているかどうか確認する
 * @param line 図の情報を表すとみられる文字列(ファイルの一行目)
 * @return 図の情報を表す構造になってたらTRUE、そうでなかったらFALSEを返す
 */
t_bool	is_info_def(char *line)
{
	int		len;
	char	*s1;
	char	*s2;

	len = ft_strlen(line);
	s1 = ft_substr(line, 0, len - 3);
	s2 = ft_substr(line, len - 3, len);
	if (!is_natural_num(ft_atoi(s1)))
		return (FALSE);
	if (ft_strlen(s2) != 3)
		return (FALSE);
	if (!ft_str_is_printable(s2))
		return (FALSE);
	if (!is_not_same_char(s2[0], s2[1], s2[2]))
		return (FALSE);
	return (TRUE);
}
