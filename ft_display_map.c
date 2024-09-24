/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eng-telur4 <eng-telur4@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 02:37:19 by eng-telur4        #+#    #+#             */
/*   Updated: 2024/09/25 02:37:52 by eng-telur4       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

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

void	display_map_n(t_map_info *map_info, int **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->rows)
	{
		j = 0;
		while (map[i][j] != -1)
		{
			ft_putnbr(map[i][j]);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
