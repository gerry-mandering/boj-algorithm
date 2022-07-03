#include <stdio.h>
#define ABS(x) (x) < 0 ? ((x) * -1) : (x)

int main(void)
{
	long long n, m;

	scanf("%lld %lld", &n, &m);
	printf("%lld\n", ABS(n - m));

	return (0);
}
