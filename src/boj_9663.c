#include <stdio.h>
#include <stdlib.h>

int	count = 0;

int *init_board(int size);
int	abs(int input);
int is_possible_board(int *board, int n);
void n_queen(int *board, int n, int max_size);

int main(void)
{
	int	*board;
	int	n;

	scanf("%d", &n);
	board = init_board(n);

	n_queen(board, 0, n);
	printf("%d\n", count);

	return (0);
}

int *init_board(int size)
{
	int	*board;

	board = (int *)calloc(size, sizeof(int));
	if (board == NULL)
	{
		puts("메모리 할당에 실패했습니다.");
		return (0);
	}

	return (board);
}

int	abs(int input)
{
	if (input < 0)
		return (input * -1);
	else
		return (input);
}

int is_possible_board(int *board, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (board[n] == board[i])
			return (0);
		if (abs(board[i] - board[n]) == n - i)
			return (0);
	}

	return (1);
}

void n_queen(int *board, int n, int max_size)
{
	if (n == max_size)
	{
		count++;
		return ;
	}
	else
	{
		for (int i = 0; i < max_size; i++)
		{
			board[n] = i;
			if (is_possible_board(board, n))
				n_queen(board, n + 1, max_size);
		}
	}
}
