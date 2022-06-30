#include <stdio.h>

int main(void)
{
	int	score_arr[5];
	int	sum = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &score_arr[i]);
		if (score_arr[i] < 40)
			sum += 40;
		else
			sum += score_arr[i];
	}

	printf("%d\n", sum / 5);

	return (0);
}
