#include "Board.h"

Board::Board()
{

}

Board::Board(int length, int height)
{
	boardHeight = height;
	boardLength = length;

	board = new char* [length];
	for (int i = 0; i < length; ++i) {
		board[i] = new char[height];
	}

	populateBoard();
}

Board::~Board()
{
}

void Board::displayBoard()
{
	//cout << board[0][0];
	for (int i = 0; i < boardHeight; ++i) {
		for (int j = 0; j < boardLength; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void Board::populateBoard()
{
	for (unsigned short i = 0; i < boardHeight; ++i) {
		for (unsigned short j = 0; j < boardLength; ++j) {
			board[i][j] = 'x';
		}
	}
}



