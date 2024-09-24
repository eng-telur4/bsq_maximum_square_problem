/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eng-telur4 <eng-telur4@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:08:54 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 02:32:31 by eng-telur4       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

// 図の情報を構造体に格納
t_map_info	*create_map_info(char *line)
{
	t_map_info	*ret_val;
	int			len;
	char		*s1;
	char		*s2;

	len = ft_strlen(line);
	s1 = ft_substr(line, 0, len - 3);
	s2 = ft_substr(line, len - 3, 3);
	ret_val = (t_map_info *)malloc(sizeof(t_map_info));
	if (ret_val == NULL)
		return (ret_val);
	ret_val->rows = ft_atoi(s1);
	ret_val->empty = s2[0];
	ret_val->obstacle = s2[1];
	ret_val->full = s2[2];
	return (ret_val);
}

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
			free_2d_array_en_route((void **)ret_val, i);
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
			free_2d_array_en_route((void **)ret_val, i);
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
