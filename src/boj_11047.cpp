#include <iostream>
#include <stack>

int	coin_type_count, sum, min_coin_count;
std::stack<int>	coin_type_stack;

void	init() {

	std::cin >> coin_type_count >> sum;

	for (int i = 0; i < coin_type_count; i++) {
		int	coin_type;

		std::cin >> coin_type;
		coin_type_stack.push(coin_type);
	}
}

void	greedy_algorithm() {

	int	current_coin_type;

	while (sum != 0) {
		current_coin_type = coin_type_stack.top();
		coin_type_stack.pop();

		min_coin_count += sum / current_coin_type;
		sum -= (sum / current_coin_type) * current_coin_type;
	}
}

int	main(void) {

	init();
	greedy_algorithm();

	std::cout << min_coin_count << std::endl;

	return 0;
}
