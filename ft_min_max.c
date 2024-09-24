/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:07:11 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 03:28:15 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 2つの整数のうち最小値を見つける
 * @param a 比較対象の整数
 * @param b 比較対象の整数
 * @return aとbのうち小さいほう
 */
int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

/**
 * @fn
 * 2つの整数のうち最大値を見つける
 * @param a 比較対象の整数
 * @param b 比較対象の整数
 * @return aとbのうち大きいほう
 */
int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
