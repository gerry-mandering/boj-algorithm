#include <iostream>

enum check_visited {
    UNVISITED,
    VISITED,
};

int *num_arr, *visited_arr;
int number, cipher, operation_count, max_number;

void count_cipher(int temp_number) {
    for (cipher = 1; temp_number > 9; temp_number /= 10)
        cipher++;
}

void init_num_arr(int temp_number) {
    int i;
    num_arr = new int[cipher];

    for (i = cipher - 1; i >= 0; temp_number /= 10) {
        num_arr[i--] = temp_number % 10;
    }
    num_arr[i] = temp_number % 10;
}

void init_visited_arr() {
    visited_arr = new int[cipher];
}

void combination(int i) {

}

void find_max_number() {
    for (int i = 0; i < cipher; i++) {
        visited_arr[i] = VISITED;
        combination(i);
    }
}

int main(void) {
    std::cin >> number >> operation_count;
    count_cipher(number);
    init_num_arr(number);
    find_max_number();

    return 0;
}