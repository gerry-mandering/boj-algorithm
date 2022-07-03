#include <stdio.h>

void	print_length(char str[]);

int main(void)
{
	char	str[101];

	scanf("%s", str);

	print_length(str);
	return (0);
}

void	print_length(char str[])
{
	int	length = 0;

	while (str[length])
		length++;

	printf("%d\n", length);
}
