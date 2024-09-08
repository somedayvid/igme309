#pragma once
#include <string>
#include <crtdbg.h>
#include <stdlib.h>
class Characters
{
public:
	unsigned short xPos;
	unsigned short yPos;
	int hCost;
	std::string type;
	int moveCost;
	Characters* parent;

	Characters();
	void updatePosition(int x, int y);
};

