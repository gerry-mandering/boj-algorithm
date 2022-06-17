#include <stdio.h>

double over_average(int sum, int score[], int students)
{
	int count = 0;
	int	average = 0;

	average = sum / students;
	for (int i=0; i<students; i++)
	{
		if (score[i] > average)
			count++;
	}
	return ((double)count / (double)students * (double)100);
}

int main(void)
{
	int repeat = 0;
	int	score[1000];
	int sum = 0;
	int students = 0;

	scanf("%d", &repeat);
	for (int i=0; i<repeat; i++)
	{
		sum = 0;
		scanf("%d", &students);
		for (int j=0; j<students; j++)
		{
			scanf("%d", &score[j]);
			sum += score[j];
		}
		printf("%.3lf%%\n", over_average(sum, score, students));
	}
	return (0);
}
