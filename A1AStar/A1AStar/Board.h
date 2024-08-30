#pragma once

#include <iostream>
#include <array>
#include "Characters.h"
#include "Space.h"

#include <string>
#include <vector>

using namespace std;

class Board
{
private:
	unsigned short boardLength;
	unsigned short boardHeight;
	vector<vector<Characters*>> board;
public:
	Board();
	Board(int length, int height);
	~Board();
	void displayBoard();
	void populateBoard();
};