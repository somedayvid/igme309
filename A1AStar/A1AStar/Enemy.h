#pragma once
#include "Characters.h"
#include "Space.h"
#include <vector>

using namespace std;

class Enemy : public Characters
{
public:
	vector<Characters*> closedList;
	vector<Characters*> openList;

	Enemy(int x, int y);
	~Enemy();
};


