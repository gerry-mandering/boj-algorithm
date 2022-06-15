#include <stdio.h>

int	main(void)
{
	int	start;
	int end;
	int key;

	scanf("%d %d", &start, &end);
	while (start <= end)
	{
		key = 1;
		if (start < 2)
			key = 0;
		for (int i = 2; i <= start / i; i++)
		{
			if (start % i == 0)
			{
				key = 0;
				break;
			}
		}
		if (key == 1)
			printf("%d\n", start);
		start++;
	}
	return (0);
}
