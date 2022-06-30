#include <stdio.h>

int main(void)
{
	int arr[3];
	int	temp;

	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	printf("%d\n", arr[1]);

	return (0);
}
