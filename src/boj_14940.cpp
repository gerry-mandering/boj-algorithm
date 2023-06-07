#include <iostream>
#include <queue>

enum map_element {
    WALL = -1,
    ROAD = -2,
};

int **map;
int row_size, col_size;
std::queue<std::pair<int, int> > waiting_queue, temp_queue;

void print_map() {
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (map[i][j] == WALL)
                std::cout << 0;
            else if (map[i][j] == ROAD)
                std::cout << -1;
            else
                std::cout << map[i][j];
            if (j != col_size - 1)
                std::cout << " ";
        }
        std::cout << "\n";
    }
}

void init_map() {
    std::cin >> row_size >> col_size;

    map = new int *[row_size];
    for (int i = 0; i < row_size; i++)
        map[i] = new int[col_size];
}

void get_map_element() {
    int input;

    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            std::cin >> input;
            switch (input) {
                case 0:
                    map[i][j] = WALL;
                    break;
                case 1:
                    map[i][j] = ROAD;
                    break;
                case 2:
                    map[i][j] = 0;
                    waiting_queue.push(std::make_pair(i, j));
                    break;
            }
        }
    }
}

void fill_distance(int row, int col, int distance) {
    if (row < 0 || col < 0 || row == row_size || col == col_size)
        return;
    else if (map[row][col] == WALL)
        return;
    else if (map[row][col] == ROAD) {
        temp_queue.push(std::make_pair(row, col));
        map[row][col] = distance;
    }
}

void bfs() {
    int distance = 1;

    do {
        while (waiting_queue.size() != 0) {
            std::pair<int, int> coord = waiting_queue.front();
            waiting_queue.pop();

            fill_distance(coord.first, coord.second + 1, distance);
            fill_distance(coord.first + 1, coord.second, distance);
            fill_distance(coord.first, coord.second - 1, distance);
            fill_distance(coord.first - 1, coord.second, distance);
        }
        std::swap(waiting_queue, temp_queue);
        distance++;
    } while (waiting_queue.size() != 0);
}

int main(void) {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    init_map();
    get_map_element();
    bfs();
    print_map();

    return 0;
}