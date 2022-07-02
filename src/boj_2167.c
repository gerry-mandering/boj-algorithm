#include <stdio.h>
#include <stdlib.h>

int **init_map(int height, int width);
void print_sum(int **map, int start_i, int start_j, int end_x, int end_y);

int main(void)
{
	int	**map;
	int	height, width, repeat, start_i, start_j, end_x, end_y;

	scanf("%d %d", &height, &width);
	map = init_map(height, width);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	scanf("%d", &repeat);

	for (int k = 0; k < repeat; k++)
	{
		scanf("%d %d %d %d", &start_i, &start_j, &end_x, &end_y);
		print_sum(map, start_i - 1, start_j - 1, end_x - 1, end_y - 1);
	}
	
	for (int u = 0; u < height; u++)
	{
		free(*(map + u));
	}
	free(map);

	return (0);
}

int **init_map(int height, int width)
{
	int **map;

	map = (int **)malloc(sizeof(int *) * height);
	if (map == NULL)
	{
		puts("메모리 할당에 실패했습니다.");
		return (0);
	}

	for (int i = 0; i < height; i++)
	{
		*(map + i) = (int *)malloc(sizeof(int) * width);
		if (*(map + i) == NULL)
		{
			puts("메모리 할당에 실패했습니다.");
			return (0);
		}
	}
	
	return (map);
}

void print_sum(int **map, int start_i, int start_j, int end_x, int end_y)
{
	int	sum = 0;

	for (int i = start_i; i <= end_x; i++)
	{
		for (int j = start_j; j <=end_y; j++)
		{
			sum += map[i][j];
		}
	}

	printf("%d\n", sum);
}
