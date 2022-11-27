#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int		row, col, row_count, col_count, patrol;
	char	**map;

	scanf("%d %d", &row, &col);
	map = (char **)malloc(sizeof(char *) * row);
	for (int i = 0; i < row; i++)
		map[i] = (char *)malloc(sizeof(char) * (col + 1));
	for (int i = 0; i < row; i++)
		scanf("%s", map[i]);
	row_count = 0;
	col_count = 0;
	for (int i = 0; i < row; i++)
	{
		patrol = 0;
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] == 'X')
			{
				patrol = 1;
				break;
			}
		}
		if (patrol != 1)
			row_count++;
	}
	for (int i = 0; i < col; i++)
	{
		patrol = 0;
		for (int j = 0; j < row; j++)
		{
			if (map[j][i] == 'X')
			{
				patrol = 1;
				break;
			}
		}
		if (patrol != 1)
			col_count++;
	}
	printf("%d\n", row_count > col_count ? row_count : col_count);
	return (0);
}
