#include "Board.h"

Board::Board()
{
	boardHeight = rand() % 25 + 10;
	boardLength = rand() % 25 + 10;

	alive = true;
	level = 1;

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
	level = 1;

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
	
	xMove += playerPtr->xPos;
	yMove += playerPtr->yPos;

	updateBoard(xMove, yMove, playerPtr);

	for (Enemy* enemies : listOfEnemies) {
		moveEnemy(enemies);
	}
}

void Board::updateBoard(int x, int y, Characters* characterToMove)
{
	//boardheight is x and boardlength is y bc of how the vectors are contained
	if (x <= boardHeight - 1 && y <= boardLength - 1 && x >= 0 && y >= 0) {
		if (board[x][y]->type == "Space") {
			holdingSpot.push_back(board[characterToMove->xPos][characterToMove->yPos]);
			holdingSpot.push_back(board[x][y]);

			board[characterToMove->xPos][characterToMove->yPos] = NULL;
			board[x][y] = NULL;

			board[characterToMove->xPos][characterToMove->yPos] = holdingSpot[1];
			board[x][y] = holdingSpot[0];

			board[characterToMove->xPos][characterToMove->yPos]->updatePosition(characterToMove->xPos, characterToMove->yPos);
			characterToMove->updatePosition(x, y);

			holdingSpot.clear();
		}
		else if (board[x][y]->type == "Enemy") {
			delete board[x][y];
			board[x][y] = nullptr;
			Characters* newSpace = new Space(x, y);
			board[x][y] = newSpace;
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
				cout << 's';
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
			if (rand() % 10 >= 9) {
				Wall* object = new Wall(i, j);
				board[i].push_back(object);
			}
			else {
				Space* object = new Space(i, j);
				board[i].push_back(object);
			}
		}
	}
	

	Enemy* object = new Enemy(0, 0);
	listOfEnemies.push_back(object);
	board[0][0] = object;


	Player* player = new Player(3,3);
	playerPtr = player;
	board[playerPtr->xPos][playerPtr->yPos] = playerPtr;
	assignCosts();
}

void Board::assignCosts() {
	for (unsigned short i = 0; i < boardHeight; ++i) {
		for (unsigned short j = 0; j < boardLength; ++j) {
			if (board[i][j]->type == "Space") {
				board[i][j]->hCost = abs(i - playerPtr->xPos) + abs(j - playerPtr->yPos);
			}
		}
	}
}

bool Board::isPlayerAlive()
{
	return alive;
}

void Board::moveEnemy(Enemy* enemyToMove) {
	Characters* goal = playerPtr;
	Characters* start = enemyToMove;
	Characters* current = start;

	Characters* lowestCostSpace;
	
	enemyToMove->openList.clear();
	enemyToMove->closedList.clear();

	enemyToMove->closedList.push_back(enemyToMove);

	goal->parent = nullptr;

	for (unsigned short i = 0; i < boardHeight; ++i) {
		for (unsigned short j = 0; j < boardLength; ++j) {
			if (board[i][j]->type == "Space") {
				board[i][j]->parent = nullptr;
				board[i][j]->moveCost = 0;
			}
		}
	}

	while (current != goal) {
		vector<Characters*> spotsToCheck;

		if ((current->xPos + 1 <= boardHeight - 1) &&
			((board[current->xPos + 1][current->yPos]->type == "Space") || (board[current->xPos + 1][current->yPos]->type == "Player")))
		{
			spotsToCheck.push_back(board[current->xPos + 1][current->yPos]);
		}
		if ((current->yPos + 1 <= boardLength - 1) &&
			((board[current->xPos][current->yPos + 1]->type == "Space") || (board[current->xPos][current->yPos + 1]->type == "Player")))
		{
			spotsToCheck.push_back(board[current->xPos][current->yPos + 1]);
		}
		if ((current->xPos - 1 >= 0) &&
			((board[current->xPos - 1][current->yPos]->type == "Space") || (board[current->xPos - 1][current->yPos]->type == "Player")))
		{
			spotsToCheck.push_back(board[current->xPos - 1][current->yPos]);

		}
		if ((current->yPos - 1 >= 0) &&
			((board[current->xPos][current->yPos - 1]->type == "Space") || (board[current->xPos][current->yPos - 1]->type == "Space")))
		{
			spotsToCheck.push_back(board[current->xPos][current->yPos - 1]);	

		}

		for (Characters* spots : spotsToCheck) {
			if (spots->parent == nullptr && find(enemyToMove->openList.begin(), enemyToMove->openList.end(), spots) == enemyToMove->openList.end()) {
				enemyToMove->openList.push_back(spots);
				spots->parent = current;
				spots->moveCost = spots->hCost + current->moveCost;
			}
			else {
				if (spots->moveCost > spots->hCost + current->moveCost) {
					spots->parent = current;
				}
			}
		}

		lowestCostSpace = enemyToMove->openList[0];

		for (Characters* spots : enemyToMove->openList) {
			if (lowestCostSpace->moveCost > spots->moveCost) {
				lowestCostSpace = spots;
			}
		}

		enemyToMove->closedList.push_back(lowestCostSpace);
		enemyToMove->openList.erase(find(enemyToMove->openList.begin(), enemyToMove->openList.end(), lowestCostSpace));

		current = lowestCostSpace;
	}

	while (current->parent != start) {
		current = current->parent;
	}

	updateBoard(current->xPos, current->yPos, enemyToMove);
}