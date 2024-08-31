// A1AStar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <array>
#include <Windows.h>
#include <random>

#include "Board.h"

using namespace std;

int main()
{

	srand(time(NULL));
	Board* gameBoard = new Board(10, 10);

	while (gameBoard->isPlayerAlive()) {
		gameBoard->displayBoard();
		gameBoard->movePlayer();
	}


}