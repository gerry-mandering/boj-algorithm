#include <stdio.h>

int	get_digit(int number)
{
	int digit = 0;

	while (number > 0)
	{
		number /= 10;
		digit++;
	}
	return (digit);
}

int	get_sum(int input, int digit)
{
	if (digit == 1)
		return (input);
	else
		return (input % 10 + get_sum(input / 10, digit - 1));
}

int	is_self_number(int number)
{
	for (int i = 1; i < number; i++)
	{
		if (i + get_sum(i, get_digit(i)) == number)
		{
			return (0);
		}
	}
	return (1);
}

int main(void)
{
	for (int i = 1; i <= 10000; i++)
	{
		if (is_self_number(i))
			printf("%d\n", i);
	}
	return (0);
}
