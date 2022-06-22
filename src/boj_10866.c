#include <stdio.h>

int	arr[10000];
static int size_val;
static int front_index;
static int back_index;

void	reset(void)
{
	front_index = 0;
	back_index = 0;
}

void	push_one_space(void)
{
	int	i = back_index - 1;

	while (i >= 0)
	{
		arr[i + 1] = arr[i];
		i--;
	}
}

void	push_front(int input)
{
	if (size_val >= 1)
		push_one_space();
	arr[front_index] = input;
	size_val++;
	back_index++;
}

void	push_back(int input)
{
	arr[back_index] = input;
	size_val++;
	back_index++;
}

void	pop_front(void)
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

void	pop_back(void)
{
	if (size_val == 0)
		printf("-1\n");
	else
	{
		printf("%d\n", arr[back_index - 1]);
		size_val--;
		if (size_val == 0)
			reset();
		else
			back_index--;
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
		printf("%d\n", arr[back_index - 1]);
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
	char	command[11];
	int		num;
	int		i = 0;

	scanf("%d", &command_count);
	while (i < command_count)
	{
		scanf("%s", command);
		if (ft_strcmp(command, "push_front") == 0)
		{
			scanf("%d", &num);
			push_front(num);
		}
		else if (ft_strcmp(command, "push_back") == 0)
		{
			scanf("%d", &num);
			push_back(num);
		}
		else if (ft_strcmp(command, "pop_front") == 0)
			pop_front();
		else if (ft_strcmp(command, "pop_back") == 0)
			pop_back();
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
