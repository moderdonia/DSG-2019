#pragma once
#include "Sprite.h"

class Player: public Sprite
{

public:
	Player(string pName);
	~Player();

	double getX();
	double getY();
	void moveLeftPlayer1();
	void moveRightPlayer1();
	
	void moveLeftPlayer2();
	void moveRightPlayer2();


	void moveUp();
	void moveDown();
	virtual void draw();
};