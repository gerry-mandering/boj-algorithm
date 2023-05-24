#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

int	unheard_count, unseen_count;
std::map<std::string, bool>	unheard_map;
std::vector<std::string>	result_vector;

int	main(void) {

	std::cin >> unheard_count >> unseen_count;

	std::string	input;

	for (int i = 0; i < unheard_count; i++) {
		std::cin >> input;
		unheard_map.insert(std::make_pair(input, true));
	}

	for (int j = 0; j < unseen_count; j++) {
		std::cin >> input;
		auto ret = unheard_map.insert(std::make_pair(input, true));
		if (ret.second == false)
			result_vector.push_back(input);
	}

	std::sort(result_vector.begin(), result_vector.end());

	std::vector<std::string>::iterator	itor;

	std::cout << result_vector.size() << std::endl;
	for (itor = result_vector.begin(); itor != result_vector.end(); itor++) {
		std::cout << *itor << std::endl;
	}

	return 0;
}
