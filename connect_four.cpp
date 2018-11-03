#include <iostream>
#include <string>

// SCALABLE FOUR

const int WIDTH = 7;
const int HEIGHT = 6;
const int NinARow = 4;

char board[HEIGHT][WIDTH];

void initializeBoard(char board[][WIDTH]) {
	// Creates an empty board with all entires spaces
	for (int h = 0; h < HEIGHT; ++h) {
		for (int w = 0; w < WIDTH; ++w) {
			board[h][w] = ' ';
		}
	}
}

void printTitle() {
	std::cout << "\n" << std::string(int(WIDTH * 1.5 - 4.5), ' ') << "Connect " << NinARow << std::endl;
}

void printBoard(char board[][WIDTH]) {
	// Prints board with indices for columns
	printTitle();
	for (int h = 0; h < HEIGHT; ++h) {
		std::cout << "|";
		for (int w = 0; w < WIDTH; ++w) {
			std::cout << " " << board[h][w] << " ";
		}
		std::cout << "|" << std::endl;
	}
	for (int w = 0; w < (WIDTH * 3) + 2; ++w){
		std::cout << "_";
	}
	std::cout << std::endl;
	for (int w = 0; w < WIDTH; ++w) {
		std::cout << "  " << w;
	}
	std::cout << std::endl;
}

bool findWinner(char board[][WIDTH], char piece) {
	// Checks for a winner based on piece (X or O), does horzontial check, 
	// vertical check, and diagnol check
	// Horizontal Check
	int start = 1;
	for (int h = 0; h < HEIGHT; ++h) {
		start = 1;
		for (int w = 0; w < WIDTH - 1; ++w) {
			if (board[h][w + 1] == board[h][w] and board[h][w] == piece) {
				++start; 
				if (start == NinARow) 
					return true;
			}
			else
				start = 1;
		}
	}
	// Vertical Check
	start = 1;
	for (int w = 0; w < WIDTH; ++w) {
		start = 1;
		for (int h = 0; h < HEIGHT - 1; ++h) {
			if (board[h + 1][w] == board[h][w] and board[h][w] == piece) {
				++start;
				if (start == NinARow) 
					return true;
			}
			else
				start = 1;
		}
	}
	// Diagnol Check - NorthEast
	start = 1;
	for (int h = 0; h < HEIGHT - NinARow + 1; ++h) {
		for (int w = 0; w < WIDTH - NinARow + 1; ++w) {
			start = 1;
			for (int i = h, j = w; i < HEIGHT - 1 and j  < WIDTH - 1; ++i, ++j) {
				if (board[i][j] == board[i + 1][j + 1] and board[i][j] == piece) {
					++start; 
					if (start == NinARow) 
						return true;
				}
				else
					start = 1;
				}
		}
	}
	// Diagnol Check - SouthEast
	start = 1;
	for (int h = 0; h < HEIGHT - NinARow + 1; ++h) {
		for (int w = NinARow - 1; w < WIDTH; ++w) {
			start = 1;
			for (int i = h, j = w; i < HEIGHT - 1 and j > 0; ++i, --j) {
				if (board[i][j] == board[i + 1][j - 1] and board[i][j] == piece) {
					++start; 
					if (start == NinARow)
						return true;
				}
				else
					start = 1;
				}
		}
	}
	return false;
}

void playTurn(char board[][WIDTH], int column, char piece) {
	// Inserts designated piece in desired column
	while (column < 0 or column > WIDTH - 1) {
		std::cout << "Please enter a valid column: ";
		std::cin >> column;
	}
	for (int h = HEIGHT; h >= 0; h--) {
		if (board[h][column] == ' ') {
			board[h][column] = piece;
			return;
		}
	}
}

bool isDraw(char board[][WIDTH]) {
	// Checks if there are any available moves
	for (int w = 0; w < WIDTH; ++w) {
		if (board[0][w] == ' ')
			return false;
	}
	return true;
}

bool playGame(char board[][WIDTH], char piece) {
	printBoard(board);
	int column;
	std::cout << "Please enter a column for Player " << piece << " (Enter -1 to Quit): ";
	std::cin >> column;
	if (column == -1)
		return false;
	playTurn(board, column, piece);
	if (findWinner(board, piece)) {
		printBoard(board);
		std::cout << "Player " << piece << " wins!" << std::endl;
		return false;
	}
	if (isDraw(board)) {
		printBoard(board);
		std::cout << "The game is a draw." << std::endl;
		return false;
	}
	return true;
}

int main() {
	initializeBoard(board);
	while (true) {
		if (not (playGame(board, 'X') and playGame(board, 'O')))
			return 0;
	}
}
