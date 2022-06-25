#include <stdio.h>

int find_greatest_common_divisor(int num1, int num2)
{
	int min = num1 < num2 ? num1 : num2;

	while (min >= 1)
	{
		if (num1 % min == 0 && num2 % min == 0)
			return (min);
		min--;
	}
	return (min);
}

int find_least_common_multiple(int num1, int num2)
{
	int	min = num1 < num2 ? num1 : num2;
	int	common_multiple = min;
	int i = 1;

	while (i)
	{
		if (common_multiple % num1 == 0 && common_multiple % num2 == 0)
			return (common_multiple);
		common_multiple = min * i++;
	}
	return (common_multiple);
}

int main(void)
{
	int	num1, num2;

	scanf("%d %d", &num1, &num2);
	printf("%d\n", find_greatest_common_divisor(num1, num2));
	printf("%d\n", find_least_common_multiple(num1, num2));
	return (0);
}
