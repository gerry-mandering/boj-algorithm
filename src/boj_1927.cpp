//
// Created by 김민석 on 2023/06/07.
//
#include <iostream>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int> > queue;
int count, input, current_size;

int main(void) {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> count;

    for (int i = 0; i < count; i++) {
        std::cin >> input;

        if (input == 0) {
            if (current_size == 0)
                std::cout << "0\n";
            else {
                std::cout << queue.top() << "\n";
                queue.pop();
                --current_size;
            }
        } else {
            queue.push(input);
            ++current_size;
        }
    }

    return 0;
}