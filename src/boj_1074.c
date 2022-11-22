#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	z_visit_recursive(int *count, int n, int row, int col, int target_row, int target_col)
{
	int	size;

	size = pow(2.0, n);
	if (n == 0)
	{
		if (row == target_row && col == target_col)
		{
			printf("%d\n", *count);
			exit(0);
		}
		return ;
	}
	if (target_row < row + (size / 2))
	{
		if (target_col < col + (size / 2))
		{
			z_visit_recursive(count, n - 1, row, col, target_row, target_col);
		}
		else
		{
			(*count) += ((int)pow(4.0, n - 1)) * 1;
			z_visit_recursive(count, n - 1, row, col + (size / 2), target_row, target_col);
		}
	}
	else
	{
		if (target_col < col + (size / 2))
		{
			(*count) += ((int)pow(4.0, n - 1)) * 2;
			z_visit_recursive(count, n - 1, row + (size / 2), col, target_row, target_col);
		}
		else
		{
			(*count) += ((int)pow(4.0, n - 1)) * 3;
			z_visit_recursive(count, n - 1, row + (size / 2), col + (size / 2), target_row, target_col);
		}
	}
}

int	main(void)
{
	int	n, row, col;
	int	count = 0;

	scanf("%d %d %d", &n, &row, &col);
	z_visit_recursive(&count, n, 0, 0, row, col);
	return (0);
}
