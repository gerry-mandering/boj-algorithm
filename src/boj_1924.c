#include <stdio.h>
#include <math.h>

typedef enum Day {SAT, SUN, MON, TUE, WED, THU, FRI} DAY;

int getDay(int year, int month, int q);

int main(void)
{
	DAY	day_of_the_week;
	int	month, day;

	scanf("%d %d", &month, &day);

	day_of_the_week = getDay(2007, month, day);

	switch (day_of_the_week)
	{
		case SAT:
			printf("SAT\n");
			break;
		case SUN:
			printf("SUN\n");
			break;
		case MON:
			printf("MON\n");
			break;
		case TUE:
			printf("TUE\n");
			break;
		case WED:
			printf("WED\n");
			break;
		case THU:
			printf("THU\n");
			break;
		case FRI:
			printf("FRI\n");
			break;
	}

	return (0);
}

int getDay(int year, int month, int q) {
	int h = 0;
    double m, K, J;

    if (month <= 2) {
        m = month + 12;
        K = (int)(year - 1) % 100;
        J = (int)(year - 1) / 100;
    } else {
		m = month;
        K = (int)year % 100;
        J = (int)year / 100;
    }

    // Zeller's congruence
    h = (q +
            (int)floor((13 * (m + 1)) / 5) +
            (int)K +
            (int)floor(K / 4) +
            (int)floor(J / 4) -
            (int)(2 * J)
		) % 7;

    if (h < 0) {
		h += 7;
    }

    return h;
}
