#include <stdio.h>
#include <stdlib.h>

int max3(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b > c)
			return (b);
		else
			return (c);
	}
}

int main(void)
{
	int	*arr;
	int	*dp_arr;
	int	size;

	scanf("%d", &size);

	arr = (int *)malloc(sizeof(int) * size);
	dp_arr = (int *)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			dp_arr[i] = arr[i];
		else if (i == 1)
			dp_arr[i] = arr[i - 1] + arr[i];
		else if (i == 2)
			dp_arr[i] = max3(arr[i - 2] + arr[i - 1], arr[i - 2] + arr[i], arr[i - 1] + arr[i]);
		else
			dp_arr[i] = max3(dp_arr[i - 3] + arr[i - 1] + arr[i], dp_arr[i - 2] + arr[i], dp_arr[i - 1]);
	}
	printf("%d\n", dp_arr[size - 1]);
}
