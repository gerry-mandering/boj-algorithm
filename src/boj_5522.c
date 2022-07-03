#include <stdio.h>

int main(void)
{
	int sum = 0, score;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &score);
		sum += score;
	}

	printf("%d\n", sum);

	return (0);
}
