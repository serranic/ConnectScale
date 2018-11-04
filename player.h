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

		int humanPlay(char board[][WIDTH]) {
			int column;
			std::cout << "Please enter a column for Player " << PIECE << " (Enter -1 to Quit): ";
			std::cin >> column;
			if (column == -1)
				return column;
			while (column < 0 or column > WIDTH - 1 or columnFull(board, column)) {
				std::cout << "Please enter a valid column: ";
				std::cin >> column;
			}
			return column;
		}

		int randomPlay() {
			int column;
			column = rand() % WIDTH;
			std::cout << column << std::endl;
			return column;
		}

		int decideTurn(char board[][WIDTH]) {
		// This function contains the logic for deciding which column to play	
			int winning = checkForWinning(board);
			if (winning != -1)
				return winning;
			int losing = checkForLosing(board);
			if (losing != -1)
				return losing;
			// int column = humanPlay(board);
			int column = randomPlay();
			for (int count = 0; count < WIDTH and checkForBadMove(board,column) and column != -1; ++count) {
				column = (column + 1) % WIDTH;
			}
			return column;
		}

		bool playATurn(char board[][WIDTH]) {
			printBoard(board);
			if (isDraw(board)) {
				printBoard(board);
				std::cout << "The game is a draw." << std::endl;
				return false;
			}
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
		int checkForWinning(char board[][WIDTH]) {
		// Checks for a winning move. If found returns column
			char copy_board[HEIGHT][WIDTH];
			for (int w = 0; w < WIDTH; ++w) {
				memcpy(copy_board, board, sizeof(copy_board));
				playTurn(copy_board, w, PIECE);
				if (findWinner(copy_board, PIECE))
						return w;
			}
			return -1;
		}

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

		bool checkForBadMove(char board[][WIDTH], int column) {
		// Checks if a move is bad. Bad means a move that is that is
		// not winning, and the next move will result in win for my 
		// opponent
			if (columnFull(board, column))
				return true;
			char copy_board[HEIGHT][WIDTH];
			memcpy(copy_board, board, sizeof(copy_board));
			playTurn(copy_board, column, PIECE);
			playTurn(copy_board, column, opposition.find(PIECE) -> second);
			if (findWinner(copy_board, opposition.find(PIECE) -> second))
				return true;
			return false;
		}
};
