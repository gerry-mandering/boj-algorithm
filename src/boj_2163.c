#include <stdio.h>

int main(void)
{
	int size_n, size_m, min, max;

	scanf ("%d %d", &size_n, &size_m);
	
	min = size_n < size_m ? size_n : size_m;
	max = size_n > size_m ? size_n : size_m;

	printf("%d\n", (min * (max - 1)) + (min - 1));

	return (0);
}
