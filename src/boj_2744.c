#include <stdio.h>

int main(void)
{
	char str[101];

	scanf("%s", str);
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
	}
	printf("%s\n", str);
	return (0);
}
