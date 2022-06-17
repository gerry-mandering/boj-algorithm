#include <stdio.h>

int	sum_recursive(int num)
{
	if (num == 1)
		return (1);
	else
		return (num + sum_recursive(num - 1));
}

int	main(void)
{
	int num;
	
	scanf("%d", &num);
	printf("%d\n", sum_recursive(num));
	return (0);
}
