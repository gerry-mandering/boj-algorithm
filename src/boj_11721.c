#include <stdio.h>

int main(void)
{
	char	str[101];
	int		i = 0;

	scanf("%s", str);
	
	while (str[i])
	{
		printf("%c", str[i]);
		if (i % 10 == 9)
			printf("\n");
		i++;
	}

	return (0);
}
