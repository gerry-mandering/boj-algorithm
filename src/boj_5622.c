#include <stdio.h>

int	cal_min_time(char *str)
{
	int	min_time;

	min_time = 0;
	while (*str)
	{
		if (*str >= 'A' && 'C' >= *str)
			min_time += 3;
		else if (*str >= 'D' && 'F' >= *str)
			min_time += 4;
		else if (*str >= 'G' && 'I' >= *str)
			min_time += 5;
		else if (*str >= 'J' && 'L' >= *str)
			min_time += 6;
		else if (*str >= 'M' && 'O' >= *str)
			min_time += 7;
		else if (*str >= 'P' && 'S' >= *str)
			min_time += 8;
		else if (*str >= 'T' && 'V' >= *str)
			min_time += 9;
		else if (*str >= 'W' && 'Z' >= *str)
			min_time += 10;
		str++;
	}
	return (min_time);
}

int main(void)
{
	char	str[15];

	scanf("%s", str);
	printf("%d\n", cal_min_time(str));
	return (0);
}
