#include <iostream>

using namespace std;

enum map_element {
    SEARCHED = -1,
};

typedef struct coord {
    int row, col;
} Coord;

int **map;
int mountaintop_count;
bool remain_flag;
Coord map_size;

void init_map() {
    cin >> map_size.row >> map_size.col;

    map = new int *[map_size.row];
    for (int i = 0; i < map_size.row; i++)
        map[i] = new int[map_size.col];
}

void get_height() {
    for (int i = 0; i < map_size.row; i++) {
        for (int j = 0; j < map_size.col; j++) {
            cin >> map[i][j];
        }
    }
}

Coord find_unsearched_highest_coord() {
    bool find_flag = false;
    int max = 0;
    Coord unsearched_coord;

    for (int i = 0; i < map_size.row; i++) {
        for (int j = 0; j < map_size.col; j++) {
            if (map[i][j] != SEARCHED) {
                if (!find_flag) {
                    find_flag = true;
                    max = map[i][j];
                    unsearched_coord.row = i;
                    unsearched_coord.col = j;
                } else {
                    if (map[i][j] > max) {
                        unsearched_coord.row = i;
                        unsearched_coord.col = j;
                    }
                }
            }
        }
    }
    if (find_flag)
        return unsearched_coord;
    else {
        unsearched_coord.row = -1;
        unsearched_coord.col = -1;
        return unsearched_coord;
    }
}

void flood_fill(int row, int col, int prev_height) {
    if (row < 0 || col < 0 || row == map_size.row || col == map_size.col) {
        return;
    } else if (map[row][col] == SEARCHED) {
        return;
    } else if (prev_height != -1) {
        if (prev_height < map[row][col]) {
            return;
        }
    }
    prev_height = map[row][col];
    map[row][col] = SEARCHED;
    flood_fill(row - 1, col, prev_height);
    flood_fill(row + 1, col, prev_height);
    flood_fill(row, col - 1, prev_height);
    flood_fill(row, col + 1, prev_height);
    flood_fill(row - 1, col - 1, prev_height);
    flood_fill(row - 1, col + 1, prev_height);
    flood_fill(row + 1, col - 1, prev_height);
    flood_fill(row + 1, col + 1, prev_height);
}

void count_mountaintop() {
    Coord unsearched_coord;

    while (true) {
        unsearched_coord = find_unsearched_highest_coord();
        if (unsearched_coord.row == -1 && unsearched_coord.col == -1)
            break;
        flood_fill(unsearched_coord.row, unsearched_coord.col, -1);
        mountaintop_count++;
    }
}

int main(void) {
    init_map();
    get_height();
    count_mountaintop();

    cout << mountaintop_count << "\n";

    return 0;
}