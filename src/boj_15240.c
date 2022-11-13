#include <stdio.h>
#include <stdlib.h>

void	flood_fill(char **map, char orignal_color, char color, int col, int row, int col_size, int row_size)
{
	if (col < 0 || row < 0)
		return ;
	if (col >= col_size || row >= row_size)
		return ;
	if (map[col][row] != orignal_color || map[col][row] == color)
		return ;
	map[col][row] = color;
	flood_fill(map, orignal_color, color, col - 1, row, col_size, row_size);
	flood_fill(map, orignal_color, color, col + 1, row, col_size, row_size);
	flood_fill(map, orignal_color, color, col, row - 1, col_size, row_size);
	flood_fill(map, orignal_color, color, col, row + 1, col_size, row_size);
}

void	print_map(char **map, int col_size)
{
	for (int i = 0; i < col_size; i++)
		printf("%s\n", map[i]);
}

int main(void)
{
	char	**map;
	int	col_size;
	int	row_size;
	int	start_col;
	int	start_row;
	int	color;
	char	orignal_color;

	scanf("%d %d", &col_size, &row_size);
	map = (char **)malloc(sizeof(char *) * col_size);
	for (int i = 0; i < col_size; i++)
		*(map + i) = (char *)malloc(sizeof(char) * (row_size + 1));
	for (int i = 0; i < col_size; i++)
		scanf("%s", map[i]);
	scanf("%d %d %d", &start_col, &start_row, &color);
	orignal_color = map[start_col][start_row];
	flood_fill(map, orignal_color, color + '0', start_col, start_row, col_size, row_size);
	print_map(map, col_size);
	return (0);
}
