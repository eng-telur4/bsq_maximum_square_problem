/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:08:54 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 01:15:43 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

char	**create_map(char **lines, int row_len)
{
	int		i;
	char	**ret_val;
	int		col_len;

	i = 0;
	ret_val = (char **)malloc((row_len + 1) * sizeof(char *));
	if (ret_val == NULL)
		return (NULL);
	col_len = ft_strlen(lines[1]);
	while (i < row_len)
	{
		ret_val[i] = (char *)malloc((col_len + 1) * sizeof(char));
		if (ret_val[i] == NULL)
		{
			free_2d((void **)ret_val, i);
			return (NULL);
		}
		ft_strcpy(ret_val[i], lines[i + 1]);
		i++;
	}
	ret_val[i] = NULL;
	return (ret_val);
}

int	**create_map_n(char **lines, t_map_info *map_info)
{
	int	i;
	int	**ret_val;
	int	col_len;
	int	j;

	i = 0;
	ret_val = (int **)malloc((map_info->rows + 1) * sizeof(int *));
	if (ret_val == NULL)
		return (NULL);
	col_len = ft_strlen(lines[1]);
	while (i < map_info->rows)
	{
		ret_val[i] = (int *)malloc((col_len + 1) * sizeof(int));
		if (ret_val[i] == NULL)
		{
			free_2d((void **)ret_val, i);
			return (NULL);
		}
		j = 0;
		while (j < col_len)
		{
			if (lines[i + 1][j] == map_info->empty)
				ret_val[i][j] = 0;
			else
				ret_val[i][j] = 1;
			j++;
		}
		ret_val[i][j] = -1;
		i++;
	}
	ret_val[i] = NULL;
	return (ret_val);
}

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

	i = 0;
	while (i < map_info->rows)
	{
		int j = 0;
		while (map[i][j] != -1)
		{
			ft_putnbr(map[i][j]);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
