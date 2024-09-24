/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 02:37:19 by eng-telur4        #+#    #+#             */
/*   Updated: 2024/09/25 03:35:32 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * (文字ベースの)図mapを標準出力に表示する
 * @param map_info 図の情報を格納したt_map_info型構造体
 * @param map (文字ベースの)図
 */
void	display_map(t_map_info *map_info, char **map)
{
	int	i;

	i = 0;
	while (i < map_info->rows)
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
}

/**
 * @fn
 * (数字ベースの)図mapを標準出力に表示する
 * @param map_info 図の情報を格納したt_map_info型構造体
 * @param map (数字ベースの)図
 */
void	display_map_n(t_map_info *map_info, int **map_n)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->rows)
	{
		j = 0;
		while (map_n[i][j] != -1)
		{
			ft_putnbr(map_n[i][j]);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
