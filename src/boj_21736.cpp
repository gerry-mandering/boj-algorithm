//
// Created by 김민석 on 2023/06/07.
//
#include <iostream>

enum map_element {
    ROAD,
    WALL,
    PLAYER,
    PERSON,
};

typedef struct coord {
    int row, col;
} Coord;

int **map;
int count;
Coord size, player_location;

void init_map() {
    std::cin >> size.row >> size.col;

    map = new int *[size.row];
    for (int i = 0; i < size.row; i++)
        map[i] = new int[size.col];
}

void get_map_element() {
    char input;

    for (int i = 0; i < size.row; i++) {
        for (int j = 0; j < size.col; j++) {
            std::cin >> input;
            switch (input) {
                case 'O':
                    map[i][j] = ROAD;
                    break;
                case 'X':
                    map[i][j] = WALL;
                    break;
                case 'I':
                    map[i][j] = ROAD;
                    player_location.row = i;
                    player_location.col = j;
                    break;
                case 'P':
                    map[i][j] = PERSON;
                    break;
            }
        }
    }
}

void flood_fill(int row, int col) {
    if (row < 0 || col < 0 || row == size.row || col == size.col)
        return;
    if (map[row][col] == WALL)
        return;
    if (map[row][col] == PERSON) {
        count++;
        map[row][col] = WALL;
    }
    if (map[row][col] == ROAD)
        map[row][col] = WALL;
    flood_fill(row - 1, col);
    flood_fill(row + 1, col);
    flood_fill(row, col - 1);
    flood_fill(row, col + 1);
}

int main(void) {
    init_map();
    get_map_element();
    flood_fill(player_location.row, player_location.col);

    if (count == 0)
        std::cout << "TT" << std::endl;
    else
        std::cout << count << std::endl;

    return 0;
}