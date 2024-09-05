// A1AStar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Board.h"

using namespace std;

void wrapper() {
	srand(time(NULL));

	cout << "Welcome to Mini-Rogue!" << endl;

	Board* gameBoard = new Board(10, 10);

	while (gameBoard->isPlayerAlive()) {
		gameBoard->displayBoard();
		gameBoard->movePlayer();
	}

	gameBoard = nullptr;
	delete gameBoard;
}

int main()
{
	wrapper();
	_CrtDumpMemoryLeaks();
}

