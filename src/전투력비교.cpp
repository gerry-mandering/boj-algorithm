//
// Created by 김민석 on 2023/05/28.
//
#include <iostream>
#include <vector>

typedef enum condition {
    GREATER_THAN = 1,   // >
    LESS_THAN = 2,      // <
    EQUAL_TO = 3,       // ==
    NONE = 4,           // 조건 없음
} Condition;

int total_warriors_count, arrangement_count;
std::vector<int> combat_power_vec;
std::vector<Condition> condition_vec;

void get_total_warriors_count() {
    std::cin >> total_warriors_count;
}

void get_combat_powers() {
    int combat_power;

    for (int i = 0; i < total_warriors_count; i++) {
        std::cin >> combat_power;
        combat_power_vec.push_back(combat_power);
    }
}

void get_conditions() {
    int condition;

    for (int i = 0; i < total_warriors_count - 1; i++) {
        std::cin >> condition;

        switch (condition) {
            case 1:
                condition_vec.push_back(GREATER_THAN);
                break;
            case 2:
                condition_vec.push_back(LESS_THAN);
                break;
            case 3:
                condition_vec.push_back(EQUAL_TO);
                break;
            case 4:
                condition_vec.push_back(NONE);
                break;
        }
    }
}

void print(std::vector<int> arrangement_vec) {
    std::cout << "[ ";
    for (int i = 0; i < total_warriors_count; i++) {
        std::cout << arrangement_vec[i];
        if (i != total_warriors_count - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

bool is_condition_fit(std::vector<int> arrangement_vec, int depth, int next_power_value) {
    if (depth == 0)
        return true;

    Condition condition = condition_vec[depth - 1];

    switch (condition) {
        case GREATER_THAN:
            if (arrangement_vec[depth - 1] > next_power_value)
                return true;
            else
                return false;
        case LESS_THAN:
            if (arrangement_vec[depth - 1] < next_power_value)
                return true;
            else
                return false;
        case EQUAL_TO:
            if (arrangement_vec[depth - 1] == next_power_value)
                return true;
            else
                return false;
        case NONE:
            return true;
    }
}

void backtracking(std::vector<int> arrangement_vec, std::vector<bool> visited_vec, int depth) {
    if (depth == total_warriors_count) {
        print(arrangement_vec);
        arrangement_count++;
        return;
    }
    for (int i = 0; i < total_warriors_count; i++) {
        if (visited_vec[i] == false && is_condition_fit(arrangement_vec, depth, combat_power_vec[i])) {
            visited_vec[i] = true;
            arrangement_vec[depth] = combat_power_vec[i];
            backtracking(arrangement_vec, visited_vec, depth + 1);
            visited_vec[i] = false;
        }
    }
}

int main(void) {

    get_total_warriors_count();
    get_combat_powers();
    get_conditions();

    std::vector<int> arragement_vec(total_warriors_count);
    std::vector<bool> visited_vec(total_warriors_count, false);

    backtracking(arragement_vec, visited_vec, 0);

    std::cout << arrangement_count << std::endl;

    return 0;
}