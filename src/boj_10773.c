#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE	100000

typedef struct s_stack
{
	int	size;
	int	sum;
	int	arr[MAX_SIZE];
}	t_stack;

void	push(t_stack *stack, int number)
{
	if (stack->size < 100000)
	{
		stack->arr[stack->size] = number;
		stack->sum += stack->arr[stack->size];
		stack->size++;
	}
}

int	pop(t_stack *stack)
{
	int	ret;

	if (stack->size != 0)
	{
		ret = stack->arr[--stack->size];
		stack->sum -= ret;
		return (ret);
	}
	else
		return (0);
}

int	main(void)
{
	int		size;
	t_stack	stack;
	int		input_num;

	stack.size = 0;
	stack.sum = 0;
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &input_num);
		if (input_num == 0)
			pop(&stack);
		else
			push(&stack, input_num);
	}
	printf("%d\n", stack.sum);
	return (0);
}
