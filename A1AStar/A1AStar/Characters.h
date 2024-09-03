#pragma once
#include <string>
class Characters
{
public:
	unsigned short xPos;
	unsigned short yPos;
	int cost;
	std::string type;

	Characters();
	void updatePosition(int x, int y);
	~Characters();

};

