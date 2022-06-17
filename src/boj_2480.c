#include <stdio.h>

int	find_max(int dice1, int dice2, int dice3)
{
	int max;

	max = dice1 > dice2 ? dice1 : dice2;
	return (dice3 > max ? dice3 : max);
}

int	main(void)
{
	int	dice1, dice2, dice3;

	scanf("%d %d %d", &dice1, &dice2, &dice3);
	if (dice1 == dice2 && dice2 == dice3)
		printf("%d\n", 10000 + (dice1 * 1000));
	else if (dice1 == dice2 || dice2 == dice3 || dice3 == dice1)
	{
		if (dice1 == dice2)
			printf("%d\n", 1000 + (dice1 * 100));
		else if (dice2 == dice3)
			printf("%d\n", 1000 + (dice2 * 100));
		else
			printf("%d\n", 1000 + (dice3 * 100));
	}
	else
		printf("%d\n", find_max(dice1, dice2, dice3) * 100);
	return (0);
}
