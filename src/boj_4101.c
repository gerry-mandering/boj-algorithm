#include <stdio.h>

int main(void)
{
	int a, b;

	while (scanf("%d %d", &a, &b) && a != 0 && b != 0)
	{
		if (a > b)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return (0);
}
