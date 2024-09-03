#include "Board.h"

Board::Board()
{
	boardHeight = rand() % 25 + 10;
	boardLength = rand() % 25 + 10;

	alive = true;

	for (int i = 0; i < boardLength; ++i) {
		vector<Characters*> thing;
		board.push_back(thing);
	}

	populateBoard();
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
			xMove = -1;
			break;
		case 'a':
			yMove = -1;
			break;
		case 's':
			xMove = 1;
			break;
		case 'd':
			yMove = 1;
			break;
	}

	updateBoard(xMove, yMove);
}

void Board::moveEnemies()
{

}

void Board::updateBoard(int x, int y)
{
	//boardheight is x and boardlength is y bc of how the vectors are contained
	if (playerPtr->xPos + x <= boardHeight - 1 && 
		playerPtr->yPos + y <= boardLength - 1 && 
		playerPtr->xPos + x >= 0 && 
		playerPtr->yPos + y >= 0) {
		if (board[playerPtr->xPos + x][playerPtr->yPos + y]->type == "Space") {
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
		else if (board[playerPtr->xPos + x][playerPtr->yPos + y]->type == "Enemy") {
			delete board[playerPtr->xPos + x][playerPtr->yPos + y];
			Characters* newSpace = new Space(playerPtr->xPos + x, playerPtr->yPos + y);
			board[playerPtr->xPos + x][playerPtr->yPos + y] = newSpace;
		}
		assignCosts();
	}
}

void Board::displayBoard()
{
	for (int i = 0; i < boardHeight; ++i) {
		for (int j = 0; j < boardLength; ++j) {
			string tempType = board[i][j]->type;
			if (tempType == "Space") {
				cout << board[i][j]->cost;
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
			cout << " ";
		}
		cout << endl;
	}
}

void Board::populateBoard()
{
	for (unsigned short i = 0; i < boardHeight; ++i) {
		for (unsigned short j = 0; j < boardLength; ++j) {
			Characters* object;
			if (rand() % 10 >= 9) {
				object = new Wall(i, j);
			}
			else {
				object = new Space(i, j);
			}
			board[i].push_back(object);
		}
	}

	Player* player = new Player(3,3);
	playerPtr = player;
	board[playerPtr->xPos][playerPtr->yPos] = playerPtr;
	assignCosts();
}

void Board::assignCosts() {
	for (unsigned short i = 0; i < boardHeight; ++i) {
		for (unsigned short j = 0; j < boardLength; ++j) {
			if (board[i][j]->type == "Space") {
				board[i][j]->cost = abs(i - playerPtr->xPos) + abs(j - playerPtr->yPos);
			}
		}
	}
}

bool Board::isPlayerAlive()
{
	return alive;
}

void Board::moveEnemy(Enemy* enemyToMove) {
	vector<Characters*> spotsToCheck;

	if ((enemyToMove->xPos + 1 <= boardHeight - 1) && 
		(board[enemyToMove->xPos + 1][enemyToMove->yPos]->type == "Space"))
	{
		spotsToCheck.push_back(board[enemyToMove->xPos + 1][enemyToMove->yPos]);
	}
	if ((enemyToMove->yPos + 1 <= boardLength - 1) && 
		(board[enemyToMove->xPos][enemyToMove->yPos + 1]->type == "Space"))
	{
		spotsToCheck.push_back(board[enemyToMove->xPos][enemyToMove->yPos + 1]);
	}
	if ((enemyToMove->xPos - 1 >= 0) &&
		(board[enemyToMove->xPos - 1][enemyToMove->yPos]->type == "Space"))
	{
		spotsToCheck.push_back(board[enemyToMove->xPos - 1][enemyToMove->yPos]);

	}
	if ((enemyToMove->yPos - 1 >= 0) &&
		(board[enemyToMove->xPos][enemyToMove->yPos - 1]->type == "Space"))
	{
		spotsToCheck.push_back(board[enemyToMove->xPos][enemyToMove->yPos - 1]);

	}

	for (Characters* spots : spotsToCheck) {
		for (int i = 0; i < spotsToCheck.size(); ++i) {
			if (spots == spotsToCheck[i]) {
				enemyToMove->openList.push_back(spots);
				break;
			}
		}
	}


}



