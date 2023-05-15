#include <iostream>
#include <list>

bool	isHigherPriorityExist(std::list<int> task_list) {
	std::list<int>::iterator	iter;
	int	front = task_list.front();
	int	i = 0;

	for (iter = task_list.begin(); iter != task_list.end(); iter++) {
		if (i == 0) {
			i++;
			continue;
		}
		if (*iter > front)
			return true;
		i++;
	}
	return false;
}

int	getPrintSequence(int current_index, std::list<int> task_list) {
	int	sequence = 0;

	while (true) {
		if (isHigherPriorityExist(task_list)) {
			int	front = task_list.front();
			task_list.pop_front();
			task_list.push_back(front);

			if (current_index == 0) {
				current_index = task_list.size() - 1;
			} else {
				current_index--;
			}
		} else {
			task_list.pop_front();
			sequence++;

			if (current_index == 0) {
				break;
			} else {
				current_index--;
			}
		}
	}

	return sequence;
}

int	main(void) {
	int	count, paper_count, index;
	std::list<int>	task_list;
	std::list<int>::iterator	iter;

	std::cin >> count;

	for (int i = 0; i < count; i++) {
		std::cin >> paper_count >> index;
		for (int j = 0; j < paper_count; j++) {
			int	priority;
			std::cin >> priority;
			task_list.push_back(priority);
		}
		std::cout << getPrintSequence(index, task_list) << std::endl;
		task_list.clear();
	}

	return 0;
}
