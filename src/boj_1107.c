#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	get_digit(int num)
{
	int	digit = 1;

	while (num > 9)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

int	diff_abs(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

int	is_all_number_available(int channel, int button_bitbask)
{
	int	digit_number;

	if (channel == 0)
	{
		if (button_bitbask & 1)
			return (1);
		else
			return (0);
	}
	while (channel > 0)
	{
		digit_number = channel % 10;
		if (!(button_bitbask & (1 << digit_number)))
			return (0);
		channel /= 10;
	}
	return (1);
}

int	get_closest_number(int channel_down, int channel_up, int button_bitbask)
{
	while (1)
	{
		if (is_all_number_available(channel_up, button_bitbask))
			return (channel_up);
		if (is_all_number_available(channel_down, button_bitbask))
			return (channel_down);
		channel_up++;
		channel_down--;
	}
}

int	main(void)
{
	int	button_bitbask = INT_MAX;
	int	closest_number;
	int	size, channel, broken_button, min_count;

	scanf("%d", &channel);
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &broken_button);
		button_bitbask &= ~(1 << broken_button);
	}
	min_count = diff_abs(channel, 100);
	if (size == 10)
	{
		printf("%d\n", min_count);
		return (0);
	}
	if (is_all_number_available(channel, button_bitbask) && get_digit(channel) < min_count)
	{
		printf("%d\n", get_digit(channel));
		return (0);
	}
	closest_number = get_closest_number(channel - 1, channel + 1, button_bitbask);
	if (get_digit(closest_number) + diff_abs(channel, closest_number) < min_count)
		min_count = get_digit(closest_number) + diff_abs(channel, closest_number);
	printf("%d\n", min_count);
	return (0);
}
