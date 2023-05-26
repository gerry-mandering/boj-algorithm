#include <iostream>
#include <list>
#include <ostream>
#include <string>

typedef enum direction {
	FORWARD,
	BACKWARD,
}	Direction;

int				count, elements_count;
std::string		task;
std::list<int>	list;

bool	is_numeric(char character) {
	if (character >= '0' && character <= '9')
		return true;
	else
		return false;
}

void	read_task() {
	std::cin >> task;
}

void	read_elements() {
	std::string				elements_string, number;
	std::string::iterator	itor;

	std::cin >> elements_count;
	std::cin >> elements_string;
	if (elements_count == 0)
		return;

	elements_string = elements_string.substr(1, elements_string.size() - 2);

	itor = elements_string.begin();
	while (true) {
		while (itor != elements_string.end() && *itor != ',') {
			number += *itor;
			itor++;
		}
		list.push_back(std::stoi(number));
		number.clear();
		if (itor == elements_string.end())
			break;
		if (*itor == ',')
			itor++;
	}
}

void	execute_task() {
	std::string::iterator	itor;
	Direction				direction = FORWARD;

	for (itor = task.begin(); itor != task.end(); itor++) {
		if (*itor == 'R') {
			direction = (direction == FORWARD) ? BACKWARD : FORWARD;
		} else if (*itor == 'D') {
			if (list.size() == 0) {
				std::cout << "error" << std::endl;
				return;
			}
			(direction == FORWARD) ? list.pop_front() : list.pop_back();
		}
	}

	std::cout << "[";
	while (list.size() != 0) {
		if (direction == FORWARD) {
			std::cout << list.front();
			list.pop_front();
		} else {
			std::cout << list.back();
			list.pop_back();
		}
		if (list.size() != 0)
			std::cout << ",";
	}
	std::cout << "]" << std::endl;
}

int	main(void) {
	std::cin >> count;

	for (int i = 0; i < count; i++) {
		read_task();
		read_elements();
		execute_task();
		list.clear();
	}

	return 0;
}
