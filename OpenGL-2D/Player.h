#pragma once
#include "Sprite.h"

class Player: public Sprite
{

public:
	Player(string pName);
	~Player();

	void moveUp();
	void moveDown();
};

