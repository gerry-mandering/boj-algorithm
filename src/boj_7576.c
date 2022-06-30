#include <stdio.h>
#include <stdlib.h>

typedef struct Index
{
	int	i;
	int	j;
} Index;

int **init_box(int width, int height);
Index *init_ripe_list(int width, int height);
int	is_all_ripe(int **box, int width, int height);
int	is_surrounding_tomatos_unripe(int **box, int i, int j);
void ripen_surrounding_tomatos(int **box, int i, int j, Index *tomorrow_ripe_list, int *tomorrow_ripe_list_count);
int get_ripen_days_recursive(int **box, Index *today_ripe_list, int today_ripe_list_count, int width, int height, int days);

int main(void)
{
	int		**box;
	Index	*today_ripe_list;
	int		width, height, days;

	scanf("%d %d", &width, &height);

	box = init_box(width, height);
	today_ripe_list = init_ripe_list(width, height);

	//토마토들 입력받기
	for (int j = 1; j <= height; j++)
	{
		for (int k = 1; k <= width; k++)
		{
			scanf("%d", &box[j][k]);
		}
	}

	days = get_ripen_days_recursive(box, today_ripe_list, 0, width, height, 0);
	printf("%d\n", days);

	free(box);

	return (0);
}

int **init_box(int width, int height)
{
	int	**box;

	box = (int **)malloc(sizeof(int *) * (height + 2));
	if (box == NULL)
	{
		puts("메모리 할당에 실패했습니다.");
		return (0);
	}

	for (int i = 0; i < height + 2; i++)
	{
		*(box + i) = (int *)calloc(width + 2, sizeof(int));
		if (*(box + i) == NULL)
		{
			puts("메모리 할당에 실패했습니다.");
			return (0);
		}
	}

	for (int j = 0; j < height + 2; j++)
	{
		for (int k = 0; k < width + 2; k++)
		{
			if (j == 0 || j == height + 1 || k == 0 || k == width + 1)
				box[j][k] = 1;
		}
	}
	
	return (box);
}

Index *init_ripe_list(int width, int height)
{
	Index	*ripe_list;

	ripe_list = (Index *)malloc(sizeof(Index) * (width * height));
	if (ripe_list == NULL)
	{
		puts("메모리 할당에 실패했습니다.");
		return (0);
	}

	return (ripe_list);
}

int	is_all_ripe(int **box, int width, int height)
{
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (box[i][j] == 0)
				return (0);
		}
	}

	return (1);
}

int	is_surrounding_tomatos_unripe(int **box, int i, int j)
{
	if (box[i - 1][j] == 0 || box[i][j - 1] == 0 || box[i + 1][j] == 0 || box[i][j + 1] == 0)
		return (1);
	else
		return (0);
}

void ripen_surrounding_tomatos(int **box, int i, int j, Index *tomorrow_ripe_list, int *tomorrow_ripe_list_count)
{
	if (box[i - 1][j] == 0)
	{
		box[i - 1][j] = 1;
		tomorrow_ripe_list[*tomorrow_ripe_list_count].i = i - 1;
		tomorrow_ripe_list[*tomorrow_ripe_list_count].j = j;
		(*tomorrow_ripe_list_count)++;
	}
	if (box[i][j - 1] == 0)
	{
		box[i][j - 1] = 1;
		tomorrow_ripe_list[*tomorrow_ripe_list_count].i = i;
		tomorrow_ripe_list[*tomorrow_ripe_list_count].j = j - 1;
		(*tomorrow_ripe_list_count)++;
	}
	if (box[i + 1][j] == 0)
	{
		box[i + 1][j] = 1;
		tomorrow_ripe_list[*tomorrow_ripe_list_count].i = i + 1;
		tomorrow_ripe_list[*tomorrow_ripe_list_count].j = j;
		(*tomorrow_ripe_list_count)++;
	}
	if (box[i][j + 1] == 0)
	{
		box[i][j + 1] = 1;
		tomorrow_ripe_list[*tomorrow_ripe_list_count].i = i;
		tomorrow_ripe_list[*tomorrow_ripe_list_count].j = j + 1;
		(*tomorrow_ripe_list_count)++;
	}
}

int get_ripen_days_recursive(int **box, Index *today_ripe_list, int today_ripe_list_count, int width, int height, int days)
{
	if (is_all_ripe(box, width, height))
		return (days);
	else
	{
		if (today_ripe_list_count == 0)
		{
			for (int i = 1; i <= height; i++)
			{
				for (int j = 1; j <= width; j++)
				{
					if (box[i][j] == 1 && is_surrounding_tomatos_unripe(box, i, j))
					{
						today_ripe_list[today_ripe_list_count].i = i;
						today_ripe_list[today_ripe_list_count].j = j;
						today_ripe_list_count++;
					}
				}
			}
			if (today_ripe_list_count == 0)
				return (-1);
		}

		Index	*tomorrow_ripe_list;
		int		tomorrow_ripe_list_count = 0;

		tomorrow_ripe_list = init_ripe_list(width, height);
		
		for (int k = 0; k < today_ripe_list_count; k++)
		{
			ripen_surrounding_tomatos(box, today_ripe_list[k].i, today_ripe_list[k].j, tomorrow_ripe_list, &tomorrow_ripe_list_count);
		}

		free(today_ripe_list);
		
		return (get_ripen_days_recursive(box, tomorrow_ripe_list, tomorrow_ripe_list_count, width, height, days + 1));
	}
}
