#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ADD		0
#define REMOVE	1
#define CHECK	2
#define TOGGLE	3
#define ALL		4
#define EMPTY	5

typedef void (*t_command_fp)(long long *bitmask, int number);

void	add(long long *bitmask, int number)
{
	*bitmask |= (1 << number);
}

void	remove_(long long *bitmask, int number)
{
	*bitmask &= ~(1 << number);
}

void	check(long long *bitmask, int number)
{
	if (*bitmask & (1 << number))
		printf("1\n");
	else
		printf("0\n");
}

void	toggle(long long *bitmask, int number)
{
	if (*bitmask & (1 << number))
		remove_(bitmask, number);
	else
		add(bitmask, number);
}

void	all(long long *bitmask, int number)
{
	*bitmask |= LLONG_MAX;
	(void)number;
}

void	empty(long long *bitmask, int number)
{
	*bitmask &= 0;
	(void)number;
}

int	main(void)
{
	int				size;
	long long		bitmask;
	int				number;
	char			input_command[7];
	char			commands[6][7] = 
	{
		"add",
		"remove",
		"check",
		"toggle",
		"all",
		"empty"
	};
	t_command_fp	command_fp[6] = 
	{
		add, remove_, check, toggle, all, empty
	};

	bitmask = 0;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%s", input_command);
		number = 0;
		for (int j = 0; j < 6; j++)
		{
			if (memcmp(input_command, commands[j], strlen(input_command)) == 0)
			{
				if (j != ALL && j != EMPTY)
					scanf("%d", &number);
				command_fp[j](&bitmask, number);
			}
		}
	}
	return (0);
}
