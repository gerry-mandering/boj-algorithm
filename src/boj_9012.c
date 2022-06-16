#include <stdio.h>

char	arr[50];
static	int	index;

void	clear(void)
{
	index = 0;
}

void	push(char input)
{
	arr[index] = input;
	index++;
}

char	pop(void)
{
	if (index == 0)
		return (0);
	return (arr[--index]);
}

void	check_vps(char input[])
{
	int	i = 0;

	while (input[i])
	{
		if (input[i] == '(')
			push(input[i]);
		else if (input[i] == ')')
		{
			if (pop() == 0)
			{
				printf("NO\n");
				return ;
			}
		}
		i++;
	}
	if (index == 0)
		printf("YES\n");
	else
		printf("NO\n");
	clear();
}

int	main(void)
{
	char input[50];
	int	count = 0;
	int	i = 0;
	int j = 0;

	scanf("%d", &count);
	while (i < count)
	{
		j = 0;
		scanf("%s", input);
		check_vps(input);
		i++;
	}
	return (0);
}
