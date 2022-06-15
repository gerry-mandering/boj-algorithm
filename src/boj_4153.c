#include <stdio.h>

int main(void)
{
	int	num[3];
	int max = 0;
	int i;
	int	sum = 0;

	while (1)
	{
		i = 1;
		sum = 0;
		scanf ("%d %d %d", &num[0], &num[1], &num[2]);
		if (num[0] == 0 && num[1] == 0 && num[2] == 0)
			break;
		max = num[0];
		while (i < 3)
		{
			if (num[i] > max)
				max = num[i];
			i++;
		}
		i = 0;
		while (i < 3)
		{
			if (num[i] != max)
			{
				sum += num[i] * num[i];
			}
			i++;
		}
		if (sum == max * max)
			printf("right\n");
		else
			printf("wrong\n");
	}
	return (0);
}
