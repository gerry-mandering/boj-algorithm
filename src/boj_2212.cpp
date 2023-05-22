/*
 * <����>
 * ������ ��ǥ���� ���Ϳ� ���� -> ���� ����
 * ���ĵ� ���͵鿡�� �� ��ҵ��� ���� ���̰��� ���ο� ���Ϳ� ����
 * ���� ���̰��� ����� ���Ϳ��� ���� ū ���� ������ ���� �����س��ư��鼭
 * �����̰� toll_center_count�� �ɶ����� �ݺ��Ѵ�.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int	sensor_count, toll_center_count;
std::vector<int>	coord_vector;
std::vector<int>	interval_vector;

void	init() {

	std::cin >> sensor_count;
	std::cin >> toll_center_count;

	for (int i = 0; i < sensor_count; i++) {
		int	coord;

		std::cin >> coord;
		coord_vector.push_back(coord);
	}
	std::sort(coord_vector.begin(), coord_vector.end());
}

void	init_interval_vector() {
	
	int	prev_coord, cur_coord;
	std::vector<int>::iterator	itor;

	for (itor = coord_vector.begin(); itor != coord_vector.end(); itor++) {
		cur_coord = *itor;

		if (itor != coord_vector.begin()) {
			int	interval;

			interval = cur_coord - prev_coord;
			interval_vector.push_back(interval);
		}
		prev_coord = cur_coord;
	}
}

void	greedy_algorithm() {

	int							segment_count = 1;
	std::vector<int>::iterator	max_element_itor;

	while (segment_count != toll_center_count) {
		max_element_itor = std::max_element(interval_vector.begin(), interval_vector.end());
		*max_element_itor = 0;
		segment_count++;
	}
}

int	main(void) {

	init();
	if (toll_center_count >= sensor_count) {
		std::cout << 0 << std::endl;
		return 0;
	}

	init_interval_vector();
	greedy_algorithm();

	int	minimum_sum = std::accumulate(interval_vector.begin(), interval_vector.end(), 0);
	std::cout << minimum_sum << std::endl;

	return 0;
}
