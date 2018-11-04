#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "player.h"

// SCALABLE FOUR
bool playGame(char board[][WIDTH], Player p1, Player p2) {
	if (not (p1.playATurn(board) and p2.playATurn(board)))
		return false;
	return true;
}

void classicGame() {
	srand(time(NULL));
	initializeBoard(board);
	Player player_1('X');
	Player player_2('O');
	while (playGame(board, player_1, player_2)) {}
}

int main() {
	classicGame();
}
