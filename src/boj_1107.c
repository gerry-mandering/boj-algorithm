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

int	inner_circulate_down(int channel_down, int button_bitbask, int channel, int min_count)
{
	int	channel_down_min_count;

	while (1)
	{
		channel_down_min_count = get_digit(channel_down) + diff_abs(channel, channel_down);
		if (channel_down_min_count > min_count)
			break ;
		if (is_all_number_available(channel_down, button_bitbask))
			min_count = channel_down_min_count;
		if (channel_down == 0)
			break;
		channel_down--;
	}
	return (min_count);
}

int	inner_circulate_up(int channel_up, int button_bitbask, int channel, int min_count)
{
	int	channel_up_min_count;

	while (1)
	{
		channel_up_min_count = get_digit(channel_up) + diff_abs(channel, channel_up);
		if (channel_up_min_count > min_count)
			break ;
		if (is_all_number_available(channel_up, button_bitbask))
			min_count = channel_up_min_count;
		if (channel_up == INT_MAX)
			break;
		channel_up++;
	}
	return (min_count);
}

int	get_closest_number_min_count(int channel_down, int channel_up, int button_bitbask, int channel)
{
	int	min_count;

	if (channel_up != INT_MAX)
		channel_up++;
	if (channel_down != 0)
		channel_down--;
	while (1)
	{
		if (is_all_number_available(channel_up, button_bitbask))
		{
			min_count = get_digit(channel_up) + diff_abs(channel, channel_up);
			return (inner_circulate_down(channel_down, button_bitbask, channel, min_count));
		}
		if (is_all_number_available(channel_down, button_bitbask))
		{
			min_count = get_digit(channel_down) + diff_abs(channel, channel_down);
			return (inner_circulate_up(channel_up, button_bitbask, channel, min_count));
		}
		if (channel_up != INT_MAX)
			channel_up++;
		if (channel_down != 0)
			channel_down--;
	}
}

int	main(void)
{
	int	button_bitbask = INT_MAX;
	int	closest_number_min_count, plus_minus_button_min_count;
	int	size, channel, broken_button;

	scanf("%d", &channel);
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &broken_button);
		button_bitbask &= ~(1 << broken_button);
	}
	plus_minus_button_min_count = diff_abs(channel, 100);
	if (size == 10)
	{
		printf("%d\n", plus_minus_button_min_count);
		return (0);
	}
	if (is_all_number_available(channel, button_bitbask) && get_digit(channel) < plus_minus_button_min_count)
	{
		printf("%d\n", get_digit(channel));
		return (0);
	}
	closest_number_min_count = get_closest_number_min_count(channel, channel, button_bitbask, channel);
	if (closest_number_min_count < plus_minus_button_min_count)
		printf("%d\n", closest_number_min_count);
	else
		printf("%d\n", plus_minus_button_min_count);
	return (0);
}
