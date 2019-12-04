#pragma once
#include "Sprite.h"
#include "Renderer.h"

class Ball : public Sprite
{
public:
	int const PLAYER_1_GOAL = 1;
	int const PLAYER_2_GOAL = 2;
	float dx = 0.000112, dy = 0.0000841;
	Ball(string pName);
	~Ball();
	void updateBall();
	virtual void draw();
	int move();
	int checkGoal();
	void getCollision();
	void setDir(float pDx, float pDy);
};

