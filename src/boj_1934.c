#include <stdio.h>

int	get_least_common_multiple(int num1, int num2, int greatest_common_divider);
int	get_greatest_common_divider(int num1, int num2);

int main(void)
{
	int repeat, num1, num2;

	scanf("%d", &repeat);

	for (int i = 0; i < repeat; i++)
	{
		scanf("%d %d", &num1, &num2);
		printf("%d\n", get_least_common_multiple(num1, num2, get_greatest_common_divider(num1, num2)));
	}

	return (0);
}

int	get_greatest_common_divider(int num1, int num2)
{
	int	greatest_common_divider = num1 < num2 ? num1 : num2;

	while (1)
	{
		if (num1 % greatest_common_divider == 0 && num2 % greatest_common_divider == 0)
			break;
		greatest_common_divider--;
	}

	return (greatest_common_divider);
}

int	get_least_common_multiple(int num1, int num2, int greatest_common_divier)
{
	int	least_common_multiple = (num1 * num2) / greatest_common_divier;

	return (least_common_multiple);
}
