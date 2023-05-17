#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define ROAD	0
#define SNAKE	1
#define APPLE	2

typedef enum direction {
	NORTH,
	SOUTH,
	EAST,
	WEST
}	Direction;

typedef enum turn {
	LEFT,
	RIGHT
}	Turn;

typedef struct location {
	int row, col;
}	Location;

void	moveLocation(Location& location, Direction direction) {
	if (direction == NORTH)
		location.row--;
	else if (direction == SOUTH)
		location.row++;
	else if (direction == EAST)
		location.col++;
	else if (direction == WEST)
		location.col--;
}

bool	isOutOfBoudary(Location location, int size) {
	if (location.row == 0 || location.col == 0 || location.row > size || location.col > size)
		return true;
	else
		return false;
}

bool	isBumpedItSelf(Location location, int **board) {
	if (board[location.row - 1][location.col - 1] == SNAKE)
		return true;
	else
		return false;
}

void	changeDirection(Direction &direction, Turn turn) {
	if (direction == NORTH) {
		if (turn == LEFT)
			direction = WEST;
		else if (turn == RIGHT)
			direction = EAST;
	} else if (direction == SOUTH) {
		if (turn == LEFT)
			direction = EAST;
		else if (turn == RIGHT)
			direction = WEST;
	} else if (direction == EAST) {
		if (turn == LEFT)
			direction = NORTH;
		else if (turn == RIGHT)
			direction = SOUTH;
	} else if (direction == WEST) {
		if (turn == LEFT)
			direction = SOUTH;
		else if (turn == RIGHT)
			direction = NORTH;
	}
}

int	main(void) {
	int	size, apple_count, instruction_count;

	std::cin >> size;
	int	**board = new int*[size];
	for (int i = 0; i < size; i++) {
		board[i] = new int[size];
		memset(board[i], 0, sizeof(int) * size);
	}

	std::cin >> apple_count;
	for (int i = 0; i < apple_count; i++) {
		int	row, col;
		std::cin >> row >> col;
		board[row - 1][col - 1] = APPLE;
	}

	std::queue< std::pair<int, Turn> >	instruction_queue;

	std::cin >> instruction_count;

	for (int i = 0; i < instruction_count; i++) {
		int		sec;
		char	turn_c;
		Turn	turn;

		std::cin >> sec >> turn_c;

		if (turn_c == 'L')
			turn = LEFT;
		else
			turn = RIGHT;

		std::pair<int, Turn>	instruction = std::make_pair(sec, turn);
		instruction_queue.push(instruction);
	}

	board[0][0] = SNAKE;

	int	game_sec = 0;
	Direction	direction;
	Location	location;
	Location	previous_location;
	std::queue<Location>	body_queue;

	direction = EAST;
	location.row = 1;
	location.col = 1;

	while (true) {
		previous_location.row = location.row;
		previous_location.col = location.col;

		moveLocation(location, direction);
		game_sec++;
		if (isOutOfBoudary(location, size) || isBumpedItSelf(location, board)) {
			break;
		} else {
			if (board[location.row - 1][location.col - 1] == APPLE) {
				board[location.row - 1][location.col - 1] = SNAKE;
				body_queue.push(previous_location);
			} else if (board[location.row - 1][location.col - 1] == ROAD) {
				board[location.row - 1][location.col - 1] = SNAKE;
				body_queue.push(previous_location);
				if (body_queue.size() != 0) {
					Location	tail = body_queue.front();
					board[tail.row - 1][tail.col - 1] = ROAD;
					body_queue.pop();
				}
			}
		}
		std::pair<int, Turn>	front = instruction_queue.front();
		if (front.first == game_sec) {
			changeDirection(direction, front.second);
			instruction_queue.pop();
		}
	}
	std::cout << game_sec << std::endl;

	return 0;
}
