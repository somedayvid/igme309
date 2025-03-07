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
#include <algorithm>

using namespace std;

class Board
{
private:
	unsigned short rows;
	unsigned short columns;
	unsigned short rowMax;
	unsigned short columnMax;

	int maxEnemies;

	vector<vector<Characters*>> board;
	vector<Characters*> holdingSpot;
	vector<Characters*> tempEnemies;
	vector<Enemy*> listOfEnemies;
	Player* playerPtr;
	bool alive;
	int enemiesToSpawn;
public:
	bool allEnemiesDead;
	Board(int level);
	~Board();

	void movePlayer();
	void updateBoard(int x, int y, Characters* characterToMove);
	void displayBoard();
	void populateBoard();
	void assignCosts();
	bool isPlayerAlive();
	void aStarSearch(Enemy* enemyToMove);
};