#include <stdio.h>

void	display(int h, int w, int **arr, int now_i, int now_j, int target)
{
	int	i;
	int	j;

	printf("========== ========== ========== ========== ==========\n");
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			// 地面の状態
			if (i == now_i && j == now_j)
				printf("\x1b[41m%d", arr[i][j]);
			else if (arr[i][j] == 0)
				printf("\x1b[44m%d", arr[i][j]);
			else if (arr[i][j] == target)
				printf("\x1b[42m%d", arr[i][j]);
			else
				printf("\x1b[40m%d", arr[i][j]);
			printf("\x1b[40m ");
			j++;
		}
		printf("\n");
		i++;
	}
	printf("========== ========== ========== ========== ==========\n");
}
