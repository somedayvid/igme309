#include "Board.h"

Board::Board()
{

}

Board::Board(int length, int height)
{
	boardHeight = height;
	boardLength = length;

	alive = true;

	for (int i = 0; i < length; ++i) {
		vector<Characters*> thing;
		board.push_back(thing);
	}

	populateBoard();
}

Board::~Board()
{
}

void Board::movePlayer()
{
	char input;
	cin >> input;
	int xMove = 0;
	int yMove = 0;

	switch (input) {
		case 'w':
			yMove = -1;
			break;
		case 'a':
			xMove = -1;
			break;
		case 's':
			yMove = 1;
			break;
		case 'd':
			xMove = 1;
			break;
	}

	updateBoard(xMove, yMove);
}

void Board::moveEnemies()
{

}

void Board::updateBoard(int x, int y)
{
	holdingSpot.push_back(board[playerPtr->xPos][playerPtr->yPos]);
	holdingSpot.push_back(board[playerPtr->xPos + x][playerPtr->yPos + y]);

	board[playerPtr->xPos][playerPtr->yPos] = NULL;
	board[playerPtr->xPos + x][playerPtr->yPos + y] = NULL;

	board[playerPtr->xPos][playerPtr->yPos] = holdingSpot[1];
	board[playerPtr->xPos + x][playerPtr->yPos + y] = holdingSpot[0];

	board[playerPtr->xPos][playerPtr->yPos]->updatePosition(playerPtr->xPos, playerPtr->yPos);
	playerPtr->updatePosition(playerPtr->xPos + x, playerPtr->yPos + y);

	holdingSpot.clear();
}

void Board::displayBoard()
{
	for (int i = 0; i < boardHeight; ++i) {
		for (int j = 0; j < boardLength; ++j) {
			//board display is [j][i] for orientation purposes x and y pos do not need to be adjusted anywhere else
			string tempType = board[j][i]->type;
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
			Characters* object;
			if (rand() % 10 >= 8) {
				object = new Wall(i, j);
			}
			else {
				object = new Space(i, j);
			}
			board[i].push_back(object);
		}
	}



	Player* player = new Player(4,7);
	playerPtr = player;
	board[playerPtr->xPos][playerPtr->yPos] = playerPtr;
}

bool Board::isPlayerAlive()
{
	return alive;
}



