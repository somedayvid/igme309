#include "Wall.h"

Wall::Wall(int x, int y)
{
	xPos = x;
	yPos = y;
	type = "Wall";
	priority = 0;
}

Wall::~Wall()
{
}
