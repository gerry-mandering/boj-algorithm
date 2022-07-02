#include <stdio.h>
#include <stdlib.h>

char **init_file_name_arr(int file_count);
char *get_file_name_pattern(char **file_name_arr, int file_count);

int main(void)
{
	int		file_count;
	char	*file_name_pattern;
	char	**file_name_arr;

	scanf("%d", &file_count);
	file_name_arr = init_file_name_arr(file_count);

	for (int i = 0; i < file_count; i++)
	{
		scanf("%s", *(file_name_arr + i));
	}

	file_name_pattern = get_file_name_pattern(file_name_arr, file_count);
	printf("%s\n", file_name_pattern);

	return (0);
}

char **init_file_name_arr(int file_count)
{
	char	**file_name_arr;

	file_name_arr = (char **)malloc(sizeof(char *) * file_count);
	if (file_name_arr == NULL)
	{
		puts("메모리 할당에 실패했습니다.");
		return (0);
	}

	for (int i = 0; i < file_count; i++)
	{
		*(file_name_arr + i) = (char *)calloc(50, sizeof(char));
		if (*(file_name_arr + i) == NULL)
		{
			puts("메모리 할당에 실패했습니다.");
			return (0);
		}
	}

	return (file_name_arr);
}

char *get_file_name_pattern(char **file_name_arr, int file_count)
{
	char	*file_name_pattern;
	int		is_same;

	file_name_pattern = (char *)calloc(50, sizeof(char));
	if (file_name_pattern == NULL)
	{
		puts("메모리 할당에 실패했습니다.");
		return (0);
	}

	for (int i = 0; file_name_arr[0][i]; i++)
	{
		is_same = 1;
		for (int j = 0; j < file_count - 1; j++)
		{
			if (file_name_arr[j][i] != file_name_arr[j + 1][i])
				is_same = 0;
		}

		if (is_same == 1)
			file_name_pattern[i] = file_name_arr[0][i];
		else
			file_name_pattern[i] = '?';
	}

	return (file_name_pattern);
}
