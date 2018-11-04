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

		int decideTurn(char board[][WIDTH]) {
		// This function contains the logic for deciding which column to play	
			std::cout << "Please enter a column for Player " << PIECE << " (Enter -1 to Quit): ";
			int losing = checkForLosing(board);
			if (losing != -1)
				return losing;
			int column;
			std::cin >> column;
			return column;
		}

		bool playATurn(char board[][WIDTH]) {
			printBoard(board);
			int column = decideTurn(board);
			if (column == -1)
				return false;
			playTurn(board, column, PIECE);
			if (findWinner(board, PIECE)) {
				printBoard(board);
				std::cout << "Player " << PIECE << " wins!" << std::endl;
				return false;
			}
			return true;
		}

	private:
		int checkForLosing(char board[][WIDTH]) {
		// Checks for losing positions. If it was your opponent's turn
		// and they had a winning move, this will return the column of 
		// that move
			char copy_board[HEIGHT][WIDTH];
			for (int w = 0; w < WIDTH; ++w) {
				memcpy(copy_board, board, sizeof(copy_board));
				playTurn(copy_board, w, opposition.find(PIECE) -> second);
				if (findWinner(copy_board, opposition.find(PIECE) -> second))
						return w;
			}
			return -1;
		}
			
};
