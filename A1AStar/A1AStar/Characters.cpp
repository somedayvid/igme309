#include "Characters.h"
#include <crtdbg.h>
#include <stdlib.h>

Characters::Characters()
{
	xPos = 0;
	yPos = 0;
	moveCost = 0;
	parent = nullptr;
	hCost = 0;
}

void Characters::updatePosition(int x, int y)
{
	xPos = x;
	yPos = y;
}

