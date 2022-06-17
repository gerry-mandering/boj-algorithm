#include <stdio.h>

int main(void)
{
	int	repeat = 0;
	int i = 0;
	int num1, num2;

	scanf("%d", &repeat);
	while (i < repeat)
	{
		scanf("%d %d", &num1, &num2);
		printf("Case #%d: %d + %d = %d\n", i + 1, num1, num2, num1 + num2);
		i++;
	}
	return (0);
}
