/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eng-telur4 <eng-telur4@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:20:50 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/24 16:52:36 by eng-telur4       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

/**
 * @fn
 * 2次元配列のメモリ確保を全てフリーする
 * @param arr 対象の配列
 */
void	free_2d_all(void **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

/**
 * @fn
 * 二次元配列をフリーする(確保中用)
 * @param arr 対象の二次元配列
 * @param i インデックス1
 */
void	free_2d(void **arr, int i)
{
	int	k;

	k = i - 1;
	while (k >= 0)
		free(arr[k--]);
	free(arr);
}
