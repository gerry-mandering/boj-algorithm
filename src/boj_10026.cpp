#include <cstdlib>
#include <iostream>
#include <map>
#include <utility>

enum map_element {
	RED,
	GREEN,
	BLUE,
	RED_GREEN,
	FLOODED,
};

int	map_size;
int	**map, **flood_map;
std::map<std::pair<int, int>, int>	remain_section;
std::map<std::pair<int, int>, int>	remain_section_color_weakness;

void	init() {

	std::cin >> map_size;

	map = new int*[map_size];
	for (int i = 0; i < map_size; i++) {
		map[i] = new int[map_size];
	}
}

void	get_rgb() {

	char	rgb_value;

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {

			std::cin >> rgb_value;

			switch (rgb_value) {
				case 'R':
					map[i][j] = RED;
					remain_section.insert(std::make_pair(std::make_pair(i, j), RED));
					remain_section_color_weakness.insert(std::make_pair(std::make_pair(i, j), RED_GREEN));
					break;
				case 'G':
					map[i][j] = GREEN;
					remain_section.insert(std::make_pair(std::make_pair(i, j), GREEN));
					remain_section_color_weakness.insert(std::make_pair(std::make_pair(i, j), RED_GREEN));
					break;
				case 'B':
					map[i][j] = BLUE;
					remain_section.insert(std::make_pair(std::make_pair(i, j), BLUE));
					remain_section_color_weakness.insert(std::make_pair(std::make_pair(i, j), BLUE));
					break;
			}
		}
	}
}

void	init_flood_map() {

	flood_map = new int*[map_size];
	for (int i = 0; i < map_size; i++) {
		flood_map[i] = new int[map_size];
	}

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			flood_map[i][j] = map[i][j];
		}
	}
}

void	flood_fill(int i, int j, int color) {
	if (i < 0 || j < 0 || i == map_size || j == map_size)
		return;
	else if (flood_map[i][j] != color)
		return;
	flood_map[i][j] = FLOODED;
	std::pair<int, int>	current_coord = std::make_pair(i, j);
	remain_section.erase(current_coord);
	flood_fill(i - 1, j, color);
	flood_fill(i + 1, j, color);
	flood_fill(i, j - 1, color);
	flood_fill(i, j + 1, color);
}

int	count_section() {

	init_flood_map();

	int	section_count = 0;

	while (remain_section.size() != 0) {
		std::map<std::pair<int, int>, int>::iterator	itor;
		itor = remain_section.begin();
		std::pair<int, int>	current_coord = itor->first;
		flood_fill(current_coord.first, current_coord.second, itor->second);
		section_count++;
	}
	return section_count;
}

void	flood_fill_color_weakness(int i, int j, int color) {
	if (i < 0 || j < 0 || i == map_size || j == map_size)
		return;
	else if (flood_map[i][j] != color)
		return;
	flood_map[i][j] = FLOODED;
	std::pair<int, int>	current_coord = std::make_pair(i, j);
	remain_section_color_weakness.erase(current_coord);
	flood_fill_color_weakness(i - 1, j, color);
	flood_fill_color_weakness(i + 1, j, color);
	flood_fill_color_weakness(i, j - 1, color);
	flood_fill_color_weakness(i, j + 1, color);
}

void	init_flood_map_color_weakness() {

	flood_map = new int*[map_size];
	for (int i = 0; i < map_size; i++) {
		flood_map[i] = new int[map_size];
	}

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if (map[i][j] == RED || map[i][j] == GREEN)
				flood_map[i][j] = RED_GREEN;
			else
				flood_map[i][j] = BLUE;
		}
	}
}

int	count_section_color_weakness(){

	init_flood_map_color_weakness();

	int	section_count = 0;

	while (remain_section_color_weakness.size() != 0) {
		std::map<std::pair<int, int>, int>::iterator	itor;
		itor = remain_section_color_weakness.begin();
		std::pair<int, int>	current_coord = itor->first;
		flood_fill_color_weakness(current_coord.first, current_coord.second, itor->second);
		section_count++;
	}
	return section_count;
}

int	main(void) {

	int	section_count, section_count_color_weakness;

	init();
	get_rgb();
	section_count = count_section();
	for (int i = 0; i < map_size; i++) {
		delete [] flood_map[i];
	}
	delete [] flood_map;
	section_count_color_weakness = count_section_color_weakness();

	std::cout << section_count << " " << section_count_color_weakness << std::endl;

	return 0;
}
