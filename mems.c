#include <stdlib.h>

void	free_2d_array_en_route(void **arr, int i)
{
	int	k;

	k = i - 1;
	while (k >= 0)
		free(arr[k--]);
	free(arr);
}

// 2次元配列のメモリ割り当てを行う関数
int	**allocate_2d_array(int h, int w)
{
	int	i;
	int	**array;

	array = (int **)malloc(h * sizeof(int *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < h)
	{
		array[i] = (int *)malloc(w * sizeof(int));
		if (array[i] == NULL)
		{
			free_2d_array_en_route((void **)array, i);
			return (NULL);
		}
		i++;
	}
	return (array);
}

// 2次元配列のメモリ解放を行う関数
void	free_2d_array(void **array, int h)
{
	int	i;

	i = 0;
	while (i < h)
		free(array[i++]);
	free(array);
}
