#include <stdio.h>

int main(void)
{
	int a, b, v;
	int	day;

	scanf("%d %d %d", &a, &b, &v);
	if ((v - b) % (a - b) == 0)
		day = (v - b) / (a - b);
	else
		day = (v - b) / (a - b) + 1;
	printf("%d\n", day);
	return (0);
}
