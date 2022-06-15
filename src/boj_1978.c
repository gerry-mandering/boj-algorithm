#include <stdio.h>

int	main(void)
{
	int number_count;
	int	input_number;
	int	prime_count = 0;
	int	i = 0;
	int	key;

	scanf("%d", &number_count);	
	while (i < number_count)
	{
		key = 1;
		scanf("%d", &input_number);
		if (input_number == 2 || input_number == 3)
			prime_count++;
		if (input_number > 3)
		{
			for (int j = 2; j <= input_number / j; j++)
			{
				if (input_number % j == 0)
				{
					key = 0;
					break;
				}
			}
			if (key == 1)
				prime_count++;
		}
		i++;
	}
	printf("%d", prime_count);
	return (0);
}
