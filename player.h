#include <iostream>
#include <map>

#include "connect_four_helper.h"

class Player {
// This is a class for players in Connect Four
	public: 
		char PIECE;
		const std::map<char, char> opposition = {
			{'X', 'O'},
			{'O', 'X'}
		};

		// Paramter Constructor
		Player(char piece) {
			std::cout << "Player " << piece << " created." << std::endl;
			PIECE = piece;
		}

		// Check for losing situations
		void checkForLosing(char board[][WIDTH]) {
			char copy_board[HEIGHT][WIDTH];
			memcpy(copy_board, board, sizeof(copy_board));
			for (int w = 0; w < WIDTH; ++w) {
				playTurn(copy_board, w, opposition.find(PIECE) -> second);
			}
			std::cout << "This is the copy board" << std::endl;
			printBoard(copy_board);
			std::cout << "End" << std::endl;

		}
			
};
