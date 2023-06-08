/*
 * 로직 구성
 *
 * 1. 전체 상자를 초기화
 * 2. 토마토 정보 받기
 * 3. 토마토의 정보를 받을 때 대기 큐에 익은 토마토 집어넣기
 * 4. 대기 큐에 좌표를 하나씩 꺼내서 주변 6군데를 익힌다. 익힌 장소는 임시 큐에 집어넣기
 * 5. 임시 큐랑 대기 큐 swap
 *
 * 마지막에는 전체 순회하면서 익지 않은 토마토가 있는지 확인해야함 => -1 출력
 */

#include <iostream>
#include <queue>

using namespace std;

typedef struct coord {
    int height, row, col;
} Coord;

enum box_element {
    EMPTY = -1,
    UNRIPE,
    RIPE,
};

int day_count;
int ***box;
Coord box_size;
queue<Coord> waiting_queue, temp_queue;

void print_box() {
    for (int i = 0; i < box_size.height; i++) {
        for (int j = 0; j < box_size.row; j++) {
            for (int k = 0; k < box_size.col; k++) {
                cout << box[i][j][k];
                if (k != box_size.col - 1)
                    cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void init_box() {
    cin >> box_size.col >> box_size.row >> box_size.height;

    box = new int **[box_size.height];
    for (int i = 0; i < box_size.height; i++) {
        box[i] = new int *[box_size.row];
        for (int j = 0; j < box_size.row; j++) {
            box[i][j] = new int[box_size.col];
        }
    }
}

void get_box_element() {
    int input;
    Coord coord;

    for (int i = 0; i < box_size.height; i++) {
        for (int j = 0; j < box_size.row; j++) {
            for (int k = 0; k < box_size.col; k++) {
                cin >> input;
                switch (input) {
                    case EMPTY:
                        box[i][j][k] = EMPTY;
                        break;
                    case UNRIPE:
                        box[i][j][k] = UNRIPE;
                        break;
                    case RIPE:
                        box[i][j][k] = RIPE;
                        coord.height = i;
                        coord.row = j;
                        coord.col = k;
                        waiting_queue.push(coord);
                        break;

                }
            }
        }
    }
}

void ripen_tomato(int height, int row, int col) {
    Coord coord;

    if (height < 0 || row < 0 || col < 0 ||
        height == box_size.height || row == box_size.row || col == box_size.col)
        return;
    else if (box[height][row][col] == RIPE || box[height][row][col] == EMPTY)
        return;
    else if (box[height][row][col] == UNRIPE) {
        box[height][row][col] = RIPE;
        coord.height = height;
        coord.row = row;
        coord.col = col;
        temp_queue.push(coord);
    }
}

void bfs() {
    while (true) {
        while (waiting_queue.size() != 0) {
            Coord coord = waiting_queue.front();
            waiting_queue.pop();
            ripen_tomato(coord.height - 1, coord.row, coord.col);
            ripen_tomato(coord.height + 1, coord.row, coord.col);
            ripen_tomato(coord.height, coord.row - 1, coord.col);
            ripen_tomato(coord.height, coord.row + 1, coord.col);
            ripen_tomato(coord.height, coord.row, coord.col - 1);
            ripen_tomato(coord.height, coord.row, coord.col + 1);
        }
        if (temp_queue.size() == 0)
            break;
        day_count++;
        swap(waiting_queue, temp_queue);
    }
}

bool unripe_tomato_exist() {
    for (int i = 0; i < box_size.height; i++) {
        for (int j = 0; j < box_size.row; j++) {
            for (int k = 0; k < box_size.col; k++) {
                if (box[i][j][k] == UNRIPE)
                    return true;
            }
        }
    }
    return false;
}

int main(void) {
    init_box();
    get_box_element();
    bfs();
    if (unripe_tomato_exist())
        std::cout << -1 << "\n";
    else
        std::cout << day_count << "\n";

    return 0;
}