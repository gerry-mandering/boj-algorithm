#include <stdio.h>

int	arr[10000];
static int	index;

void	push(int input)
{
	arr[index] = input;
	index++;
}

void	pop(void)
{
	if (index == 0)
		printf("-1\n");
	else
		printf("%d\n", arr[--index]);
}

void	size(void)
{
	printf("%d\n", index);
}

void	empty(void)
{
	if (index == 0)
		printf("1\n");
	else
		printf("0\n");
}

void	top(void)
{
	if (index == 0)
		printf("-1\n");
	else
		printf("%d\n", arr[index - 1]);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int	main(void)
{
	int		command_count = 0;
	char	command[10];
	int		num;
	int		i = 0;

	scanf("%d", &command_count);
	while (i < command_count)
	{
		scanf("%s", command);
		if (ft_strcmp(command, "push") == 0)
		{
			scanf("%d", &num);
			push(num);
		}
		else if (ft_strcmp(command, "pop") == 0)
			pop();
		else if (ft_strcmp(command, "size") == 0)
			size();
		else if (ft_strcmp(command, "empty") == 0)
			empty();
		else if (ft_strcmp(command, "top") == 0)
			top();
		i++;
	}
	return (0);
}
