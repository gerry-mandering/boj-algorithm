#include <stdio.h>

int	check_croatia_double_alpha(char *input)
{
	int	i = 0;

	if (input[i] == 'c' && input[i + 1] == '=')
		return (1);
	else if (input[i] == 'c' && input[i + 1] == '-')
		return (1);
	else if (input[i] == 'd' && input[i + 1] == '-')
		return (1);
	else if (input[i] == 'l' && input[i + 1] == 'j')
		return (1);
	else if (input[i] == 'n' && input[i + 1] == 'j')
		return (1);
	else if (input[i] == 's' && input[i + 1] == '=')
		return (1);
	else if (input[i] == 'z' && input[i + 1] == '=')
		return (1);
	else
		return (0);
}

int	check_croatia_triple_alpha(char *input)
{
	int	i = 0;

	if (input[i] == 'd' && input[i + 1] == 'z' && input[i + 2] == '=')
		return (1);
	else
		return (0);
}

int count_croatia_alpha(char *input)
{
	int	count = 0;
	int	length = 0;
	int	i = 0;
	
	while (input[length])
		length++;
	while (input[i])
	{
		if (i <= length - 3 && check_croatia_triple_alpha(&input[i]))
		{
			count++;
			i += 3;
			continue ;
		}
		if (i <= length - 2 && check_croatia_double_alpha(&input[i]))
		{
			count++;
			i += 2;
			continue ;
		}
		count++;
		i++;
	}
	return (count);
}

int main(void)
{
	char	input[100];

	scanf("%s", input);
	printf("%d\n", count_croatia_alpha(input));
	return (0);
}
