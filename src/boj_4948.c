#include <stdio.h>

int	is_prime(int number)
{
	int	i = 2;

	if (number < 2)
		return (0);
	while (i <= number / i)
	{
		if (number % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	count_prime(int	number)
{
	int count = 0;
	int	end = number * 2;

	number++;
	while (number <= end)
	{
		if (is_prime(number))
			count++;
		number++;
	}
	return (count);
}

int main(void)
{
	int	number = 0;

	while (scanf("%d", &number) && number != 0)
		printf("%d\n", count_prime(number));
	return (0);
}
