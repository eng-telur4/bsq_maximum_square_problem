/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_max_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eng-telur4 <eng-telur4@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:22:50 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 02:46:57 by eng-telur4       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

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
