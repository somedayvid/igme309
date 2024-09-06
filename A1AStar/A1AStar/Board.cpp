/*When the term "character" is mentioned it basically means the parent class of every other object in the program as enemy, player, space, and wall all
inherit from it, consider it sort like how unity considers gameObjects for objects that exist in the game*/
#include "Board.h"


/// <summary>
/// Unparameterized constructor which generates a board of a random legnth and width that is greater than 10 x 10
/// </summary>
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

//FOR TESTING ONLY
/// <summary>
/// Parameterized constructor which generates a board of the specified length and height
/// </summary>
/// <param name="length">How mamy tiles the board is from left to right</param>
/// <param name="height">How many tiles the board is from top to bottom</param>
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

/// <summary>
/// Deconstructor for board
/// </summary>
Board::~Board()
{
	playerPtr = nullptr;
	delete playerPtr;

	for (unsigned short i = 0; i < boardHeight; ++i) {
		for (unsigned short j = 0; j < boardLength; ++j) {
			board[i][j] = nullptr;
			delete board[i][j];
		}
	}
}


/// <summary>
/// Takes in input from the user and prompts a move on the board accordingly
/// </summary>
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
		case 'l':
			alive = false;
	}
	//xmove and ymove are the coordinates of the position the player is trying to move to
	xMove += playerPtr->xPos;
	yMove += playerPtr->yPos;

	updateBoard(xMove, yMove, playerPtr);

	//enemies move immediately after the player's move
	for (Enemy* enemies : listOfEnemies) {
		aStarSearch(enemies);
	}
}

/// <summary>
/// Moves enemies and the player around on the board
/// </summary>
/// <param name="x">The x position of the next tile that is being moved to</param>
/// <param name="y">The y position of the next tile that is being moved to</param>
/// <param name="characterToMove">The character that is to be moved, either player or enemy</param>
void Board::updateBoard(int x, int y, Characters* characterToMove)
{
	//boardheight is x and boardlength is y bc of how the vectors are contained
	if (x <= boardHeight - 1 && y <= boardLength - 1 && x >= 0 && y >= 0) { 
		//checks if position trying to be moved is an empty space
		if (board[x][y]->type == "Space") {
			holdingSpot.push_back(board[characterToMove->xPos][characterToMove->yPos]);
			holdingSpot.push_back(board[x][y]);

			board[characterToMove->xPos][characterToMove->yPos] = nullptr;
			board[x][y] = nullptr;

			board[characterToMove->xPos][characterToMove->yPos] = holdingSpot[1];
			board[x][y] = holdingSpot[0];

			board[characterToMove->xPos][characterToMove->yPos]->updatePosition(characterToMove->xPos, characterToMove->yPos);
			characterToMove->updatePosition(x, y);

			holdingSpot.clear();
		}
		//enemies ignore other enemies in their astar algorithm so they are not capable of triggering this piece of code
		else if (board[x][y]->type == "Enemy") {
			holdingSpot.push_back(board[x][y]);
			listOfEnemies.erase(find(listOfEnemies.begin(), listOfEnemies.end(), board[x][y]));

			board[x][y] = new Space(x, y);
			
			holdingSpot[0] = nullptr;
			delete holdingSpot[0];

			holdingSpot.clear();
		}
		assignCosts();
	}
}

/// <summary>
/// Displays the board state
/// </summary>
void Board::displayBoard()
{
	for (int i = 0; i < boardHeight; ++i) {
		for (int j = 0; j < boardLength; ++j) {
			string tempType = board[i][j]->type;
			if (tempType == "Space") {
				printf("\033[1;37ms\033[1;0m");
			}
			else if (tempType == "Wall") {
				printf("\033[1;34mW\033[1;0m");
			}
			else if (tempType == "Enemy") {
				printf("\033[1;31mE\033[1;0m");
			}
			else if (tempType == "Player") {
				printf("\033[1;32mP\033[1;0m");
			}
			cout << " ";
		}
		cout << endl;
	}
}

/// <summary>
/// Called on initialization in order to fill up the 2d matrix which contains the board
/// </summary>
void Board::populateBoard()
{
	for (unsigned short i = 0; i < boardHeight; ++i) {
		for (unsigned short j = 0; j < boardLength; ++j) {
			if (rand() % 10 >= 8) {
				board[i].push_back(new Wall(i, j));
			}
			else if (rand() % 100 >= 97) {
				Enemy* newEnemy = new Enemy(i, j);
				listOfEnemies.push_back(newEnemy);
				board[i].push_back(newEnemy);
			}
			else {
				board[i].push_back(new Space(i,j));
			}
		}
	}

	Player* player = new Player(3,3);
	playerPtr = player;
	board[playerPtr->xPos][playerPtr->yPos] = playerPtr;
	assignCosts();
}

/// <summary>
/// Updates the heuristic cost of each space character as the player moves around the board for the purposes of A*
/// </summary>
void Board::assignCosts() {
	for (unsigned short i = 0; i < boardHeight; ++i) {
		for (unsigned short j = 0; j < boardLength; ++j) {
			if (board[i][j]->type == "Space") {
				//calculated using manhatten distance
				board[i][j]->hCost = abs(i - playerPtr->xPos) + abs(j - playerPtr->yPos);
			}
		}
	}
}

/// <summary>
/// Is the player alive
/// </summary>
/// <returns>Boolean representing the livingness of the player</returns>
bool Board::isPlayerAlive()
{
	return alive;
}

/// <summary>
/// A* algorithm search for the enemies so they can pathfind around walls towards the player, implemented with manhatten distance
/// </summary>
/// <param name="enemyToMove">The enemy that is moving now</param>
void Board::aStarSearch(Enemy* enemyToMove) {
	Characters* goal = playerPtr;
	Characters* start = enemyToMove;
	Characters* current = start;

	Characters* lowestCostSpace;

	bool canKillPlayer = false;
	
	//clears the variables of the enemy for a new search
	enemyToMove->openList.clear();
	enemyToMove->closedList.clear();

	//adds itself to the closedlist
	enemyToMove->closedList.push_back(enemyToMove);

	//clears the parent of the goal so player can be added to openlist and detected
	goal->parent = nullptr;

	//clears the spaces's variables for next enemy a* check
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

		//look in 4 directions around the character for spaces that it can check
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

		if (current == start && find(spotsToCheck.begin(), spotsToCheck.end(), goal) != spotsToCheck.end()) {
			canKillPlayer = true;
			alive = false;
			break;
		}

		if (spotsToCheck.size() == 0) {
			break;
		}

		//of the possible spaces it could check if they do not have a parent and are not on the openlist
		for (Characters* spots : spotsToCheck) {
			if (spots->parent == nullptr && find(enemyToMove->openList.begin(), enemyToMove->openList.end(), spots) == enemyToMove->openList.end()) {
				enemyToMove->openList.push_back(spots);				//we add them to the open list
				spots->parent = current;							//and parent it to the current character we are on
				spots->moveCost = spots->hCost + current->moveCost; //and then adjust the movecost according to the total cost to move from the start to this character
			}
			//if they do have a parent or are on the openlist then we go to the else and compare if the movecost coming from our current character
			//would be lower than the one it currently has, if yes then we update its parent and move cost
			else {
				if (spots->moveCost > spots->hCost + current->moveCost) {
					spots->parent = current;
					spots->moveCost = spots->hCost + current->moveCost;
				}
			}
		}

		//comparing the movecosts of all the characters in our current open list to find the one with the loweset movecost value
		lowestCostSpace = enemyToMove->openList[0];

		for (Characters* spots : enemyToMove->openList) {
			if (lowestCostSpace->moveCost > spots->moveCost) {
				lowestCostSpace = spots;
			}
		}

		//then that character is moved from that enemy's open list to its closed list
		enemyToMove->closedList.push_back(lowestCostSpace);
		enemyToMove->openList.erase(find(enemyToMove->openList.begin(), enemyToMove->openList.end(), lowestCostSpace));

		//and we continue the while loop with our new current character being the one with the lowest move cost
		current = lowestCostSpace;
	}

	if (!canKillPlayer) {
		//once the path is established the while loop exits and we trace our way back to a character
		//which has our start as its parent 
		while (current->parent != start) {
			current = current->parent;
		}

		//then we move our enemy to that position
		updateBoard(current->xPos, current->yPos, enemyToMove);
	}

	//clearing memory 
	goal = nullptr;
	start = nullptr;
	current = nullptr;
	lowestCostSpace = nullptr;

	delete goal;
	delete start;
	delete current;
	delete lowestCostSpace;
}