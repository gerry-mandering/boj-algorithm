#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	size;
	int	count;
	int	*arr;

	count = 0;
	scanf("%d", &size);
	arr = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == arr[i])
			{
				count++;
				break;
			}
		}
	}
	printf("%d\n", count);
	return (0);
}
