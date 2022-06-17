#include <stdio.h>

int main(void)
{
	int	cycle = 0;
	int num = 0;
	int original_num = 0;
	int	new_num = -1;

	scanf("%d", &original_num);
	num = original_num;
	while (1)
	{
		if (new_num == original_num)
			break;
		new_num = ((num % 10) * 10) + (((num / 10) + (num % 10)) % 10);
		num = new_num;
		cycle++;
	}
	printf("%d\n", cycle);
	return (0);
}
