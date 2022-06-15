#include <stdio.h>

int	main(void)
{
	int kilo = 0;
	int	bag_5k = 0;
	int	bag_3k = 0;

	scanf("%d", &kilo);
	bag_5k = kilo / 5;
	if (kilo >= 5)
	{
		while (bag_5k >= 0)
		{
			if (kilo - (bag_5k * 5) == 0)
			{
				printf("%d", bag_5k);
				return (0);
			}
			else if ((kilo - (bag_5k * 5)) % 3 == 0)
			{
				bag_3k = (kilo - (bag_5k * 5)) / 3;
				printf("%d", bag_5k + bag_3k);
				return (0);
			}
			bag_5k--;
		}
		printf("-1");
	}
	else if (kilo == 3)
		printf("1");
	else
		printf("-1");
	return (0);
}
