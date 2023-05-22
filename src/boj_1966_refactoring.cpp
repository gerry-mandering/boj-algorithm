/*
 * <Logic>
 * 작업 리스트를 생성하고 작업들의 우선순위를 차례대로 저장한다
 * 그 다음 처음 작업의 우선순위를 보고 남아있는 우선순위와 비교한다
 * 만약 처음 작업의 우선순위가 남아있는 우선순위들 보다 크다면 해당 작업을 pop() 시키고 sequence 순번을 ++ 해준다.
 * 만약 처음 작업의 우선순위 보다 큰 남아있는 작업이 있다면 해당 작업을 pop() 시키고 다시 push_back()한다.
 * paper_index번째 작업이 언제 수행되는지 알고 싶기에 해당 paper_index를 계속해서 추적하고 만약 paper_index의 값이 0이 되었을때, 즉 추적하던 paper_index를 출력할 시점이 되었을때 해당 작업물의 우선순위가 가장 높다면 해당 작업물을 pop() 하고 ++로 올려준 순번 sequence가 정답이 된다.
 * 하지만 paper_index를 출력할 시점이 되었을때 작업물의 우선순위가 1순위가 아니라면 pop -> push_back 하고 paper_index를 (리스트의 사이즈 - 1)로 다시 조정해준다.
 */

#include <iostream>
#include <list>

int	paper_count, paper_index;
std::list<int>	task_list;

void	init() {
	std::cin >> paper_count >> paper_index;

	for (int i = 0; i < paper_count; i++) {
		int	priority;

		std::cin >> priority;
		task_list.push_back(priority);
	}
}

bool	isHigherPriorityExist() {
	int							front_task_priority = task_list.front();
	std::list<int>::iterator	itor;

	for (itor = task_list.begin(); itor != task_list.end(); itor++) {

		if (itor == task_list.begin())
			continue;

		if (*itor > front_task_priority)
			return true;
	}
	return false;
}

int	getPrintSequence() {

	int	sequence = 0;

	while (true) {
		if (isHigherPriorityExist()) {
			int	front_task = task_list.front();
			task_list.pop_front();
			task_list.push_back(front_task);

			if (paper_index == 0)
				paper_index = task_list.size() - 1;
			else
				paper_index--;
		} else {
			task_list.pop_front();
			sequence++;

			if (paper_index == 0)
				return sequence;
			else
				paper_index--;
		}
	}
}

int	main(void) {

	int	case_count;

	std::cin >> case_count;

	for (int i = 0; i < case_count; i++) {
		init();
		std::cout << getPrintSequence() << std::endl;
		task_list.clear();
	}

	return 0;
}
