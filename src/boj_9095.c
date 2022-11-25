#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*dp_arr;
	int	size;
	int	input;

	scanf("%d", &size);
	dp_arr = (int *)malloc(sizeof(int) * 11);
	for (int i = 0; i < 11; i++)
	{
		if (i == 0)
			dp_arr[i] = 1;
		else if (i == 1)
			dp_arr[i] = 2;
		else if (i == 2)
			dp_arr[i] = 4;
		else
		{
			dp_arr[i] = dp_arr[i - 3] + dp_arr[i - 2] + dp_arr[i - 1];
		}
	}
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &input);
		printf("%d\n", dp_arr[input - 1]);
	}
	return (0);
}
