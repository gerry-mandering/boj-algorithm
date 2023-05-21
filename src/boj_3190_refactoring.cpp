#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

enum	board_element {
	ROAD,
	SNAKE,
	APPLE
};

typedef enum turn {
	LEFT,
	RIGHT
}	Turn;

typedef enum direction {
	NORTH,
	SOUTH,
	EAST,
	WEST
}	Direction;

typedef struct location {
	int	row, col;
}	Location;

int	board_size, game_sec;
int	**board;
std::queue< std::pair<int, Turn> >	instruction_queue;

void	init_board() {

	std::cin >> board_size;

	board = new int*[board_size];
	for (int i = 0; i < board_size; i++) {
		board[i] = new int[board_size];
		memset(board[i], ROAD, sizeof(int) * board_size);
	}
	board[0][0] = SNAKE;
}

void	init_apple() {
	int	apple_count, row, col;

	std::cin >> apple_count;

	for (int i = 0; i < apple_count; i++) {
		std::cin >> row >> col;
		board[row - 1][col - 1] = APPLE;
	}
}

void	get_instructions() {
	int		instruction_count;
	Turn	turn;

	std::cin >> instruction_count;

	for (int i = 0; i < instruction_count; i++) {
		int		sec;
		char	input_character;

		std::cin >> sec >> input_character;

		if (input_character == 'L')
			turn = LEFT;
		else
			turn = RIGHT;

		std::pair<int, Turn>	instruction = std::make_pair(sec, turn);
		instruction_queue.push(instruction);
	}
}

void	moveSnake(Location& snake_location, Direction direction) {
	if (direction == NORTH)
		snake_location.row--;
	else if (direction == SOUTH)
		snake_location.row++;
	else if (direction == EAST)
		snake_location.col++;
	else if (direction == WEST)
		snake_location.col--;
}

bool	isOutOfBoudary(Location location) {
	if (location.row == 0 || location.col == 0 || location.row > board_size || location.col > board_size)
		return true;
	else
		return false;
}

bool	isBumpedItSelf(Location location) {
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

void	start_game() {
	Direction				direction = EAST;
	Location				snake_location;
	Location				prev_snake_location;
	std::queue<Location>	body_queue;

	snake_location.row = 1;
	snake_location.col = 1;

	while (true) {
		prev_snake_location.row = snake_location.row;
		prev_snake_location.col = snake_location.col;

		moveSnake(snake_location, direction);
		game_sec++;
		if (isOutOfBoudary(snake_location) || isBumpedItSelf(snake_location)) {
			break;
		} else {
			if (board[snake_location.row - 1][snake_location.col - 1] == APPLE) {
				board[snake_location.row - 1][snake_location.col - 1] = SNAKE;
				body_queue.push(prev_snake_location);
			} else if (board[snake_location.row - 1][snake_location.col - 1] == ROAD) {
				board[snake_location.row - 1][snake_location.col - 1] = SNAKE;
				body_queue.push(prev_snake_location);
				if (body_queue.size() != 0) {
					Location	tail = body_queue.front();
					body_queue.pop();
					board[tail.row - 1][tail.col - 1] = ROAD;
				}
			}
		}
		std::pair<int, Turn>	front_instruction = instruction_queue.front();
		if (front_instruction.first == game_sec) {
			changeDirection(direction, front_instruction.second);
			instruction_queue.pop();
		}
	}
}

int	main(void) {

	init_board();
	init_apple();
	get_instructions();
	start_game();

	std::cout << game_sec << std::endl;

	return 0;
}
