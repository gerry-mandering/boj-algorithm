#include <stdio.h>

int main(void)
{
	int repeat = 0;
	int i = 0;
	int num1, num2;

	scanf("%d", &repeat);
	while (i < repeat)
	{
		scanf("%d %d", &num1, &num2);
		printf("%d\n", num1 + num2);
		i++;
	}
	return (0);
}
