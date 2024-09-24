/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eng-telur4 <eng-telur4@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 02:32:17 by eng-telur4        #+#    #+#             */
/*   Updated: 2024/09/25 02:32:18 by eng-telur4       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @fn
 * 二次元配列をフリーする(確保中用)
 * @param arr 対象の二次元配列
 * @param i インデックス1
 */
void	free_2d_array_en_route(void **arr, int i)
{
	int	k;

	k = i - 1;
	while (k >= 0)
		free(arr[k--]);
	free(arr);
}

/**
 * @fn
 * 2次元配列のメモリ確保を全てフリーする
 * @param arr 対象の配列
 */
void	free_2d_array(void **array, int h)
{
	int	i;

	i = 0;
	while (i < h)
		free(array[i++]);
	free(array);
}
