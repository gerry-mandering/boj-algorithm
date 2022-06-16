#include <stdio.h>

int	arr[10000];
static int size_val;
static int index;
static int front_index;
static int back_index;

void	reset(void)
{
	index = 0;
	front_index = 0;
	back_index = 0;
}

void	push(int input)
{
	arr[index] = input;
	size_val++;
	back_index = index;
	index++;
}

void	pop(void)
{
	if (size_val == 0)
		printf("-1\n");
	else
	{
		printf("%d\n", arr[front_index]);
		size_val--;
		if (size_val == 0)
			reset();
		else
			front_index++;
	}
}

void	size(void)
{
	printf("%d\n", size_val);
}

void	empty(void)
{
	if (size_val == 0)
		printf("1\n");
	else
		printf("0\n");
}

void	front(void)
{
	if (size_val == 0)
		printf("-1\n");
	else
		printf("%d\n", arr[front_index]);
}

void	back(void)
{
	if (size_val == 0)
		printf("-1\n");
	else
		printf("%d\n", arr[back_index]);
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
		else if (ft_strcmp(command, "front") == 0)
			front();
		else if (ft_strcmp(command, "back") == 0)
			back();
		i++;
	}
	return (0);
}
