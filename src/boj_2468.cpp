#include <iostream>
#include <map>
#include <utility>

enum flooded_map_element {
	GROUND,
	FLOODED,
	SAFE,
};

int	map_size, min_height, max_height, max_safe_zone_count = 1;
int	**map, **flooded_map;
std::map<std::pair<int, int>, bool>	remain_ground;

void	print_map() {

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void	init_map() {

	std::cin >> map_size;

	map = new int*[map_size];
	for (int i = 0; i < map_size; i++) {
		map[i] = new int[map_size];
	}
}

void	get_height_info() {

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			std::cin >> map[i][j];

			if (i == 0 && j == 0) {
				min_height = map[i][j];
				max_height = map[i][j];
				continue;
			}
			if (map[i][j] < min_height)
				min_height = map[i][j];
			if (map[i][j] > max_height)
				max_height = map[i][j];
		}
	}
}

void	make_flooded_map(int flooded_height) {

	flooded_map = new int*[map_size];
	for (int i = 0; i < map_size; i++) {
		flooded_map[i] = new int[map_size];
	}

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if (map[i][j] <= flooded_height)
				flooded_map[i][j] = FLOODED;
			else {
				flooded_map[i][j] = GROUND;

				std::pair<int, int>	coord = std::make_pair(i, j);
				remain_ground.insert(std::make_pair(coord, true));
			}
		}
	}
}

void	flood_fill(int row, int col) {
	if (row < 0 || row == map_size || col < 0 || col == map_size)
		return;
	else if (flooded_map[row][col] == FLOODED || flooded_map[row][col] == SAFE)
		return;
	flooded_map[row][col] = SAFE;
	std::pair<int, int>	coord = std::make_pair(row, col);
	remain_ground.erase(coord);
	flood_fill(row - 1, col);
	flood_fill(row + 1, col);
	flood_fill(row, col - 1);
	flood_fill(row, col + 1);
}

void	delete_flooded_map() {

	for (int i = 0; i < map_size; i++) {
		delete[] flooded_map[i];
	}
	delete[] flooded_map;
}

int	get_safe_zone_count(int flood_height) {

	int	safe_zone_count = 0;
	std::map<std::pair<int, int>, bool>::iterator	current_remain_ground;
	std::pair<int, int>	coord;

	make_flooded_map(flood_height);
	while (remain_ground.size() != 0) {
		current_remain_ground = remain_ground.begin();
		coord = current_remain_ground->first;
		flood_fill(coord.first, coord.second);
		safe_zone_count++;
	}
	delete_flooded_map();

	return safe_zone_count;
}

int	main(void) {

	init_map();
	get_height_info();

	int	flood_height, safe_zone_count;

	for (flood_height = min_height; flood_height <= max_height; flood_height++) {
		safe_zone_count = get_safe_zone_count(flood_height);
		if (safe_zone_count > max_safe_zone_count)
			max_safe_zone_count = safe_zone_count;
	}

	std::cout << max_safe_zone_count << std::endl;

	return 0;
}
