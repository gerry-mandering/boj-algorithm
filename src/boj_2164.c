#include <stdio.h>

int	arr[1000000];
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

int		pop(void)
{
	int return_val = -1;
	if (size_val == 0)
		return (return_val);
	return_val = arr[front_index];
	size_val--;
	if (size_val == 0)
		reset();
	else
		front_index++;
	return (return_val);
}

int	main(void)
{
	int		num = 0;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		push(i + 1);
	}

	while (size_val > 1)
	{
		pop();
		push(pop());
	}

	printf("%d\n", pop());
	return (0);
}
