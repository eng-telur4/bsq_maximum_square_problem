/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_largest_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:22:50 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 01:40:28 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

int	get_largest_square(int h, int w, int **g_g, int **g_dp)
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
			// 1が汚れたタイルなので、面積は0に、0は綺麗なタイルなので、面積が1になる
			g_dp[i][j] = (g_g[i][j] + 1) % 2;
			// 面積が1の場合、最大面積を計算する処理がスルーされるので、面積を暫定でいれる
			max_width |= g_dp[i][j];
			j++;
		}
		i++;
	}
	i = 1;
	while (i < h)
	{
		j = 1;
		while (j < w)
		{
			// 汚れている状態
			if (g_g[i][j])
				g_dp[i][j] = 0;
			else
			{
				// 左上,上,左の最小値の+1がg_dp[i][j]の正方形の最大面積となる
				g_dp[i][j] = min(g_dp[i - 1][j - 1], min(g_dp[i - 1][j],
							g_dp[i][j - 1])) + 1;
				max_width = max(max_width, g_dp[i][j]);
			}
			// display(h, w, g_dp, i, j, max_width);
			j++;
		}
		i++;
	}
	return (max_width);
}
