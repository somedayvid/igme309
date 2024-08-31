#pragma once
#include "Characters.h"
class Player : public Characters
{
public:
	bool canRight;
	bool canLeft;
	bool canDown;
	bool canUp;

	Player(int x, int y);
	~Player();
};

