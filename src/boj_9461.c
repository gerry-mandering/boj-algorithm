#include <stdio.h>
#include <stdlib.h>

long long padovan_memo(long long *memo, int n);

int main(void)
{
	long long	*memo;
	int			repeat, n;

	memo = (long long *)calloc(100, sizeof(long long));
	if (memo == NULL)
	{
		puts("메모리 할당에 실패했습니다.");
		return (0);
	}
	
	scanf("%d", &repeat);
	for (int i = 0; i < repeat; i++)
	{
		scanf("%d", &n);
		printf("%lld\n", padovan_memo(memo, n));
	}

	return (0);
}

long long padovan_memo(long long *memo, int n)
{
	if (memo[n] != 0)
		return (memo[n]);
	else
	{
		if (n >= 1 && n <= 3)
		{
			memo[n] = 1;
			return (memo[n]);
		}
		else if (n >= 4 && n <= 5)
		{
			memo[n] = 2;
			return (memo[n]);
		}
		else if (n == 6)
		{
			memo[n] = 3;
			return (memo[n]);
		}
		else if (n == 7)
		{
			memo[n] = 4;
			return (memo[n]);
		}
		else if (n == 8)
		{
			memo[n] = 5;
			return (memo[n]);
		}
		else
		{
			memo[n] = padovan_memo(memo, n - 5) + padovan_memo(memo, n - 1);
			return (memo[n]);
		}
	}
}
