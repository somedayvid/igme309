#pragma once

#include <iostream>
#include <array>
using namespace std;

class Board
{
private:
	unsigned short boardLength;
	unsigned short boardHeight;
	char** board;
public:
	Board();
	Board(int length, int height);
	~Board();
	void displayBoard();
	void populateBoard();
};