#pragma once

#include <iostream>
#include <array>

#include "Characters.h"
#include "Space.h"
#include "Player.h"
#include "Enemy.h"
#include "Wall.h"

#include <string>
#include <vector>
#include <random>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Board
{
private:
	unsigned short boardLength;
	unsigned short boardHeight;
	vector<vector<Characters*>> board;
	vector<Characters*> holdingSpot;
	Player* playerPtr;

	bool alive;

	char previousKeyPress;
	char currentKeyPress;
public:
	Board();
	Board(int length, int height);
	~Board();
	void movePlayer();
	void moveEnemies();
	void updateBoard(int x, int y);
	void displayBoard();
	void populateBoard();
	void assignCosts();
	bool isPlayerAlive();
	void moveEnemy(Enemy* enemyToMove);
	bool enemyMoveCheck(int x, int y);
};