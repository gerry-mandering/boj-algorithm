#include <stdio.h>

int main(void)
{
	int	hour;
	int min;
	int	duration;
	int	dur_hour;
	int	dur_min;

	scanf("%d %d", &hour, &min);
	scanf("%d", &duration);
	dur_hour = duration / 60;
	dur_min = duration % 60;
	
	if (min + dur_min > 59)
	{
		dur_hour++;
		min += dur_min - 60;
	}
	else
		min += dur_min;

	if (hour + dur_hour > 23)
		hour += dur_hour - 24;
	else
		hour += dur_hour;
	printf("%d %d", hour, min);
	return (0);
}
