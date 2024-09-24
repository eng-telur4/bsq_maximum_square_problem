/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:15:33 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 00:37:31 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 文字列strのstart番目からlen分文字列を抜き取る関数
 * @param str 対象の文字列
 * @param start 開始地点
 * @param len 長さ
 * @return 抜き取った文字列を返す
 * @attention メモリ確保(malloc)が失敗した場合はNULLを返す
 */
char	*ft_substr(char *str, int start, int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = str[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
