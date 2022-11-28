#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	**cost_arr;
	int	string_count, brand_count;
	int	package_min, single_min;
	int	only_single, only_package, both, total_cost;

	scanf("%d %d", &string_count, &brand_count);
	cost_arr = (int **)malloc(sizeof(int*) * brand_count);
	for (int i = 0; i < brand_count; i++)
		cost_arr[i] = (int *)malloc(sizeof(int) * 2);
	for (int i = 0; i < brand_count; i++)
	{
		scanf("%d %d", &cost_arr[i][0], &cost_arr[i][1]);
		if (i == 0)
		{
			package_min = cost_arr[i][0];
			single_min = cost_arr[i][1];
		}
		else
		{
			if (cost_arr[i][0] < package_min)
				package_min = cost_arr[i][0];
			if (cost_arr[i][1] < single_min)
				single_min = cost_arr[i][1];
		}
	}
	if (package_min > single_min * 6)
	{
		only_single = string_count * single_min;
		printf("%d\n", only_single);
		return (0);
	}
	if (string_count % 6 == 0)
		only_package = string_count / 6 * package_min;
	else
		only_package = ((string_count / 6) + 1) * package_min;
	both = ((string_count / 6) * package_min) + ((string_count % 6) * single_min);
	total_cost = only_package < both ? only_package : both;
	printf("%d\n", total_cost);
	return (0);
}
