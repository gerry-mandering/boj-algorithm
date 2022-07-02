#include <stdio.h>
#include <stdlib.h>

long long	*init_memo(void);
long long	fibo_memo(int n, long long memo[]);

int main(void)
{
	long long	*memo;
	int			n;

	memo = init_memo();

	scanf("%d", &n);
	printf("%lld\n", fibo_memo(n, memo));

	return (0);
}

long long *init_memo(void)
{
	long long	*memo;

	memo = (long long *)malloc(sizeof(long long) * 91);
	if (memo == NULL)
	{
		puts("메모리 할당에 실패했습니다.");
		return (0);
	}

	for (int i = 0; i < 91; i++)
	{
		memo[i] = -1;
	}

	return (memo);
}

long long fibo_memo(int n, long long memo[])
{
	if (memo[n] != -1)
		return (memo[n]);
	else
	{
		if (n == 0 || n == 1)
			return memo[n] = n;
		else
			return memo[n] = fibo_memo(n - 1, memo) + fibo_memo(n - 2, memo);
	}
}
