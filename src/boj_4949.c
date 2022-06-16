#include <stdio.h>

char	arr[100];
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

char	top(void)
{
	if (index == 0)
		return (0);
	return (arr[index - 1]);
}

void	check_vps(char input[])
{
	int	i = 0;
	char c;

	while (input[i])
	{
		if (input[i] == '(' || input[i] == '[')
			push(input[i]);
		else if (input[i] == ')')
		{
			c = top();
			if (c == '(')
				pop();
			else
			{
				printf("no\n");
				clear();
				return ;
			}
		}
		else if (input[i] == ']')
		{
			c = top();
			if (c == '[')
				pop();
			else
			{
				printf("no\n");
				clear();
				return ;
			}
		}
		i++;
	}
	if (index == 0)
		printf("yes\n");
	else
		printf("no\n");
	clear();
}

int	only_dot(char input[])
{
	int	length = 0;

	while (input[length])
		length++;
	if (length == 1 && input[--length] == '.')
		return (1);
	return (0);
}

int	main(void)
{
	char input[100];

	while (1)
	{
		gets(input);	
		if (only_dot(input))
			break ;
		check_vps(input);
	}
	return (0);
}
