#include <iostream>
#include <string>

#include "player.h"

// SCALABLE FOUR
bool playGame(char board[][WIDTH], Player p1, Player p2) {
	if (not (p1.playATurn(board) and p2.playATurn(board)))
		return false;
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
	Player player_2('O');
	while (playGame(board, player_1, player_2)) {}
}
