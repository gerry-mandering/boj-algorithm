#include <stdio.h>
#include <stdlib.h>
#define SWAP(type, x, y) do { type temp = x; x = y; y = temp; } while (0)

void bubble_sort(int *arr, int size);
void print_number(int *arr, int size);

int main(void)
{
	int	*arr;
	int repeat;

	scanf("%d", &repeat);
	
	arr = (int *)malloc(sizeof(int) * repeat);
	if (arr == NULL)
	{
		puts("메모리 할당에 실패했습니다.");
		return (0);
	}

	for (int i = 0; i < repeat; i++)
	{
		scanf("%d", &arr[i]);
	}

	bubble_sort(arr, repeat);
	print_number(arr, repeat);

	return (0);
}

void bubble_sort(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				SWAP(int, arr[j], arr[j + 1]);
			}
		}
	}
}

void print_number(int *arr, int size)
{
	int min_index = 0, max_index = size - 1;

	printf("%d\n", (arr[min_index] * arr[max_index]));
}
