#include <stdio.h>
#include <stdlib.h>

int	is_prime(int number)
{
	int i = 2;
	
	if (number < 2)
		return (0);
	while (i <= number / i)
	{
		if (number % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	*find_middle_to_end_prime(int *arr_size, int middle, int end)
{
	int	*arr;	

	while (middle <= end)
	{
		if (is_prime(middle))
		{
			(*arr_size)++;
			if (*arr_size == 1)
			{
				arr = (int *)malloc(sizeof(int) * *arr_size);
				arr[*arr_size - 1] = middle;
			}
			else
			{
				arr = (int *)realloc(arr, sizeof(int) * *arr_size);
				arr[*arr_size - 1] = middle;
			}
		}
		middle++;
	}
	return (arr);
}

void solve(int number, int middle, int start, int *middle_to_end_prime_arr, int middle_to_end_prime_arr_size)
{
	int i = 0;

	while (middle >= start)
	{
		i = 0;
		if (is_prime(middle))
		{
			while (i < middle_to_end_prime_arr_size)
			{
				if (middle + middle_to_end_prime_arr[i] == number)
				{
					printf("%d %d\n", middle, middle_to_end_prime_arr[i]);
					return ;
				}
				i++;
			}
		}
		middle--;
	}
}

int main(void)
{
	int	repeat = 0;
	int	number = 0;
	int	start = 2, middle, end;
	int	*middle_to_end_prime_arr;
	int	middle_to_end_prime_arr_size = 0;

	scanf("%d", &repeat);
	for (int i = 0; i < repeat; i++)
	{
		middle_to_end_prime_arr_size = 0;
		scanf("%d", &number);
		middle = number / 2;
		end = number;
		middle_to_end_prime_arr = find_middle_to_end_prime(&middle_to_end_prime_arr_size, middle, end);
		solve(number, middle, start, middle_to_end_prime_arr, middle_to_end_prime_arr_size);
		free(middle_to_end_prime_arr);
	}
	return (0);
}
