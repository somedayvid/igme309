// A1AStar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <cstdlib>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include "Board.h"

using namespace std;

void wrapper() {
	srand(time(NULL));

	int level = 1;

	cout << "Welcome to Mini-Rogue!" << endl << endl;
	cout << "The game will present you with the current state of the board and then you can input: " << endl;
	cout << "	      w(up)" << endl;
	cout << "     a(left) s(down) d(right)" << endl;
	cout << "In order to traverse around the board." << endl << endl;
	cout << "Kill \033[1;31menemies\033[1;0m when \033[1;32myou\033[1;0m are next to them, but be careful as you stay in place when you attack!" << endl;
	cout << "In addition enemies move immediately after you do so plan ahead accordingly!" << endl << endl; 
	

	Board* gameBoard = new Board(level);

	cout << "Level: " << level << endl;

	while (gameBoard->isPlayerAlive()) {
		gameBoard->displayBoard();
		gameBoard->movePlayer();
		if (gameBoard->allEnemiesDead) {
			delete gameBoard;
			gameBoard = nullptr;

			++level;
			gameBoard = new Board(level);
			cout << endl << endl;
			cout << "Level: " << level << endl;
		}
	}
	gameBoard->displayBoard();
	cout << "\033[1;32mYOU HAVE DIED! GAME OVER\033[1;0m" << endl;
	cout << "\033[1;32mYOU MADE IT TO ROOM " << level << "!" << "\033[1; 0m" << endl;

	delete gameBoard;
	gameBoard = nullptr;
}

int main()
{
	wrapper();
	_CrtDumpMemoryLeaks();
}

