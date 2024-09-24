/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:12:12 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 03:53:12 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 文字cが標準空白文字であるかどうかをテストする
 * @param c 対象の文字
 * @return 標準空白文字なら1を、そうでないなら0をかえす
 * @sa https://nxmnpg.lemoda.net/ja/3/isspace
 */
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

/**
 * @fn
 * 文字列strによって指示される文字列のはじめの部分をint型整数に変換する
 * @param str ヌル終端文字列
 * @return 変換後の数値を返す
 * @note 42のft_atoiではなく本家に近づけている(マイナスの判定を一度しかしない)
 * @sa https://ja.manpages.org/atoi/3
 */
int	ft_atoi(char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			ret = ret * 10 + (*str - '0');
			str++;
		}
		else
			break ;
	}
	return (ret * sign);
}
