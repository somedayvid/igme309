#include "Player.h"

Player::Player(int x, int y)
{
	xPos = x;
	yPos = y;
	type = "Player";
	priority = 100;
}

Player::~Player()
{
}
