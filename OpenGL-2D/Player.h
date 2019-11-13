#pragma once
#include "Sprite.h"

class Player: public Sprite
{
public:
	Player();
	~Player();


	virtual void draw();
	void moveUp();
	void moveDown();
};

