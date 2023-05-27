#include <iostream>
#include <map>
#include <utility>
#include <string.h>

enum map_element {
	GROUND,
	CABBAGE,
	FLOODED,
};

int	row_size, col_size, cabbage_count;
int	**map;
std::map<std::pair<int, int>, bool>	cabbage_location_map;

void	init_map() {
	map = new int*[row_size];
	for (int i = 0; i < row_size; i++) {
		map[i] = new int[col_size];
		memset(map[i], GROUND, sizeof(int) * col_size);
	}
}

void	get_cabbage_location() {
	int	row, col;

	for (int i = 0; i < cabbage_count; i++) {
		std::cin >> col >> row;
		map[row][col] = CABBAGE;
		std::pair<int, int>	location = std::make_pair(row, col);
		cabbage_location_map.insert(std::make_pair(location, true));
	}
}

void	flood_fill(int row, int col) {
	if (row < 0 || col < 0 || row == row_size || col == col_size)
		return;
	if (map[row][col] != CABBAGE)
		return;
	map[row][col] = FLOODED;
	cabbage_location_map.erase(std::make_pair(row, col));
	flood_fill(row - 1, col);
	flood_fill(row + 1, col);
	flood_fill(row, col - 1);
	flood_fill(row, col + 1);
}

int	count_section() {
	int	section_count = 0;
	std::map<std::pair<int, int>, bool>::iterator	itor;

	while (cabbage_location_map.size() != 0) {
		itor = cabbage_location_map.begin();
		std::pair<int, int>	location = itor->first;
		flood_fill(location.first, location.second);
		section_count++;
	}

	return section_count;
}

void	delete_map() {

	for (int i = 0; i < row_size; i++) {
		delete [] map[i];
	}
	delete [] map;
}

int	main(void) {

	int	count;

	std::cin >> count;

	for (int i = 0; i < count; i++) {
		std::cin >> col_size >> row_size >> cabbage_count;
		init_map();
		get_cabbage_location();
		std::cout << count_section() << std::endl;
		delete_map();
	}

	return 0;
}
