#include "Board.h"

Board::Board()
{

}

Board::Board(int length, int height)
{
	boardHeight = height;
	boardLength = length;


	for (int i = 0; i < length; ++i) {
		vector<Characters*> thing;
		board.push_back(thing);
	}

	populateBoard();
}

Board::~Board()
{
}

void Board::displayBoard()
{
	for (int i = 0; i < boardHeight; ++i) {
		for (int j = 0; j < boardLength; ++j) {
			string tempType = board[i][j]->type;
			if (tempType == "Space") {
				cout << 'x';
			}
			else if (tempType == "Wall") {
				cout << 'W';
			}
			else if (tempType == "Enemy") {
				cout << 'E';
			}
			else if (tempType == "Player") {
				cout << 'P';
			}
		}
		cout << endl;
	}
}

void Board::populateBoard()
{
	for (unsigned short i = 0; i < boardHeight; ++i) {
		for (unsigned short j = 0; j < boardLength; ++j) {
			Space* blank = new Space();
			board[i].push_back(blank);
		}
	}


}



