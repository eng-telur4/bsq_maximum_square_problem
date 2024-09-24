/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_max_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:22:50 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 03:49:39 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 動的計画法を用いて最大正方形問題を解く(ft_calc_max_squareで使用する)
 * @param h 図の高さ
 * @param w 図の幅
 * @param g_g 操作する図
 * @param g_dp 回答を入れるための図
 * @return
 */
int	calc_one(int h, int w, int **g_g, int **g_dp)
{
	int	max_width;
	int	i;
	int	j;

	max_width = 0;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			g_dp[i][j] = (g_g[i][j] + 1) % 2;
			max_width |= g_dp[i][j];
			j++;
		}
		i++;
	}
	return (max_width);
}

/**
 * @fn
 * 動的計画法を用いて最大正方形問題を解く
 * @param h 図の高さ
 * @param w 図の幅
 * @param g_g 操作する図
 * @param g_dp 回答を入れるための図
 * @return 入れることができる正方形の一片の長さ
 */
int	ft_calc_max_square(int h, int w, int **g_g, int **g_dp)
{
	int	max_width;
	int	i;
	int	j;

	max_width = calc_one(h, w, g_g, g_dp);
	i = 1;
	while (i < h)
	{
		j = 1;
		while (j < w)
		{
			if (g_g[i][j])
				g_dp[i][j] = 0;
			else
			{
				g_dp[i][j] = min(g_dp[i - 1][j - 1], min(g_dp[i - 1][j],
							g_dp[i][j - 1])) + 1;
				max_width = max(max_width, g_dp[i][j]);
			}
			j++;
		}
		i++;
	}
	return (max_width);
}
