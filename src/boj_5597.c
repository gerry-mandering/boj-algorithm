#include <stdio.h>

int main(void)
{
	int	arr[30];
	int	num;

	for (int i = 0; i < 30; i++)
	{
		arr[i] = 0;
	}

	for (int j = 0; j < 28; j++)
	{
		scanf("%d", &num);
		arr[num - 1] = 1;
	}

	for (int k = 0; k < 30; k++)
	{
		if (arr[k] == 0)
			printf("%d\n", k + 1);
	}

	return (0);
}
