#include <stdio.h>

int	main(void)
{
	int	target_len;
	int	count = 0;

	scanf("%d", &target_len);
	for (int i = 0; i <= 6; i++)
	{
		if ((1 << i) & target_len)
			count++;
	}
	printf("%d\n", count);
	return (0);
}
