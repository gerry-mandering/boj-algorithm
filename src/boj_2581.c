#include <stdio.h>

int	main(void)
{
	int	start, end;
	int	i = 2;
	int	key = 1;
	int sum = 0;
	int	min = 0;

	scanf("%d", &start);
	scanf("%d", &end);

	while (start <= end)
	{
		i = 2;
		key = 1;
		if (start < 2)
			key = 0;
		while (i <= start / i)
		{
			if (start % i == 0)
			{
				key = 0;
				break;
			}
			i++;
		}
		if (key == 1 && sum == 0)
			min = start;
		if (key == 1)
			sum += start;
		start++;
	}
	if (sum == 0)
		printf("-1\n");
	else
	{
		printf("%d\n", sum);
		printf("%d\n", min);
	}
	return (0);
}
