#include <iostream>
#include <string>

#include "player.h"

// SCALABLE FOUR
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
	Player player_1('X');
	while (true) {
	//	player_1.checkForLosing(board);
		if (not (playGame(board, 'X') and playGame(board, 'O')))
			return 0;
	}
}
