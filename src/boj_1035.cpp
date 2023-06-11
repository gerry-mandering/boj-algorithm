/*
 * 로직
 *
 * 연결된 갯수 트레킹 매 번마다
 *
 */
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

enum map_element {
    EMPTY,
    STAR,
    VISITED,
};

typedef struct coord {
    int row, col;
} Coord;

int map[5][5], original_map[5][5], min_move_count;
deque<Coord> coord_deque;
vector<vector<Coord> > coord_links(5);

void print_map() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j];
            if (j != 4)
                cout << " ";
        }
        cout << "\n";
    }
}

void get_map_element() {
    char input;
    Coord star_coord;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> input;
            if (input == '.')
                original_map[i][j] = EMPTY;
            else {
                original_map[i][j] = STAR;
                star_coord.row = i;
                star_coord.col = j;
                coord_deque.push_back(star_coord);
            }
        }
    }
}

void copy_original_map() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = original_map[i][j];
        }
    }
}

void flood_fill(int row, int col, int current_index) {
    Coord current_coord;

    if (row < 0 || col < 0 || row == 5 || col == 5)
        return;
    else if (map[row][col] == EMPTY || map[row][col] == VISITED)
        return;
    current_coord.row = row;
    current_coord.col = col;
    coord_links[current_index].push_back(current_coord);
    map[row][col] = VISITED;
    flood_fill(row - 1, col, current_index);
    flood_fill(row + 1, col, current_index);
    flood_fill(row, col - 1, current_index);
    flood_fill(row, col + 1, current_index);
}

void make_coord_links() {
    Coord current_coord;
    int current_index = 0;

    copy_original_map();
    while (coord_deque.size() != 0) {
        current_coord = coord_deque.front();
        coord_deque.pop_front();

        flood_fill(current_coord.row, current_coord.col, current_index);
        current_index++;
    }
}

void find_minimum_move_count() {
    for (int i = 0; i < 5; i++) {
        if (coord_links[i].size() == 0)
            return;


    }
}

int main(void) {
    get_map_element();
    make_coord_links();
    vector<Coord>::iterator iter;
    Coord current_coord;
    for (int i = 0; i < 5; i++) {
        for (iter = coord_links[i].begin(); iter != coord_links[i].end(); iter++) {
            current_coord = *iter;
            cout << "(" << current_coord.row << ", " << current_coord.col << ") ";
        }
        cout << "\n";
    }

    find_minimum_move_count();

    return 0;
}