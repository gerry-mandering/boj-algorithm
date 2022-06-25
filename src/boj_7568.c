#include <stdio.h>
#include <stdlib.h>

typedef struct body
{
	int height;
	int weight;
} body;

int get_body_rank(int index, int size, body *body_arr)
{
	int	rank = 1;
	
	for (int i = 0; i < size; i++)
	{
		if (i != index)
		{
			if (body_arr[i].height > body_arr[index].height && body_arr[i].weight > body_arr[index].weight)
				rank++;
		}
	}
	return (rank);
}

int main(void)
{
	int repeat = 0;
	body *body_arr;
	
	scanf("%d", &repeat);
	body_arr = (body *)malloc(sizeof(body) * repeat);

	for (int i = 0; i < repeat; i++)
	{
		scanf("%d %d", &body_arr[i].height, &body_arr[i].weight);
	}

	for (int i = 0; i < repeat; i++)
	{
		printf("%d", get_body_rank(i, repeat, body_arr));
		if (i != repeat - 1)
			printf(" ");
	}
	free(body_arr);
	return (0);
}
