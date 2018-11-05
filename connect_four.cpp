#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <thread>
#include <mutex>

#include <vector>

#include "player.h"

std::mutex mtx;
std::vector<char> gameLog;

// SCALABLE FOUR
bool playGame(char board[][WIDTH], Player p1, Player p2) {
	if (!(p1.playATurn(board) and p2.playATurn(board)))
		return false;
	return true;
}

// Classic Game
void classicGame(Player p1, Player p2) {
    while (playGame(board, p1, p2)) {}
}

// Threaded Game
void threadPlayer(Player * p) {
    mtx.lock();
    p -> playATurn(board);
    gameLog.push_back(p -> PIECE);
    mtx.unlock();
}

void threadedGame(Player p1, Player p2) {
    for (int i = 0; i < 25; ++i) { 
        std::thread thread1(threadPlayer, &p1);
        std::thread thread2(threadPlayer, &p2);

        thread1.join();
        thread2.join();
    }
}

int main() {
    srand(time(NULL));
	initializeBoard(board);
    Player player_1('X');
	Player player_2('O');

    classicGame(player_1, player_2);
    // threadedGame(player_1, player_2);
}
