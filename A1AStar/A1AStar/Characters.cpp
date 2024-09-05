#include "Characters.h"

Characters::Characters()
{
	xPos = 0;
	yPos = 0;
	moveCost = 0;
	parent = nullptr;
}

void Characters::updatePosition(int x, int y)
{
	xPos = x;
	yPos = y;
}

Characters::~Characters()
{
}
