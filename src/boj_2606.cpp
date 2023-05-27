//
// Created by 김민석 on 2023/05/27.
//
#include <iostream>
#include <set>

enum map_element {
    UNLINKED,
    LINKED,
};

int computer_count, link_count;
int **map;
std::set<int> infected_computer_set;

void init_map() {
    map = new int *[computer_count + 1];
    for (int i = 0; i < computer_count + 1; i++) {
        map[i] = new int[computer_count + 1];
    }
}

void init() {
    std::cin >> computer_count;
    std::cin >> link_count;

    init_map();

    int row, col;
    for (int i = 0; i < link_count; i++) {
        std::cin >> row >> col;
        map[row][col] = LINKED;
        map[col][row] = LINKED;
    }
}

void recursive_search(int &infected_computer_count, int current_infected_computer) {
    int row, col;

    row = current_infected_computer;
    for (col = 1; col < computer_count + 1; col++) {
        if (map[row][col] == LINKED) {
            auto ret = infected_computer_set.insert(col);
            if (ret.second) {
                infected_computer_count++;
                recursive_search(infected_computer_count, col);
            }
        }
    }
}

int count_infected_computer() {
    int infected_computer_count = 0;

    infected_computer_set.insert(1);
    recursive_search(infected_computer_count, 1);

    return infected_computer_count;
}

int main(void) {

    init();
    std::cout << count_infected_computer() << std::endl;

    return 0;
}