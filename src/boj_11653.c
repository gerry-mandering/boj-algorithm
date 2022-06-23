#include <stdio.h>
#include <stdlib.h>

int	is_prime(int num)
{
	int i = 2;

	if (num < 2)
		return (0);
	while (i <= num / i)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	find_next_prime(int index)
{
	int	i = 0;
	int	count = -1;

	while (1)
	{
		if (is_prime(i))
		{
			count++;
			if (count == index)
				return (i);
		}
		i++;
	}
}

void	bubble_sort(int *result_arr, int result_size)
{
	int temp = 0;

	for (int i=0; i<result_size-1; i++)
	{
		for (int j=0; j<result_size-1-i; j++)
		{
			if (result_arr[j] > result_arr[j + 1])
			{
				temp = result_arr[j];
				result_arr[j] = result_arr[j + 1];
				result_arr[j + 1] = temp;
			}
		}
	}
}

int	main(void)
{
	int	number = 0;
	int	index = 0;
	int	result = 1;
	int	result_size = 0;
	int	*result_arr;

	scanf("%d", &number);
	if (number == 1)
		return (0);
	while (!is_prime(number))
	{
		index = 1;
		result = 2;
		while (1)
		{
			if (number % result == 0)
			{
				result_size++;
				break;
			}
			result = find_next_prime(index);
			index++;
		}
		if (result_size == 1)
			result_arr = (int *)malloc(sizeof(int) * result_size);
		else
			result_arr = (int *)realloc(result_arr, sizeof(int) * result_size);
		result_arr[result_size - 1] = result;
		number /= result;
	}
	result_size++;
	if (result_size == 1)
		result_arr = (int *)malloc(sizeof(int) * result_size);
	else
		result_arr = (int *)realloc(result_arr, sizeof(int) * result_size);
	result_arr[result_size - 1] = number;
	for (int i=0; i<result_size; i++)
		printf("%d\n", result_arr[i]);
	return (0);
}
