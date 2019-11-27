#pragma once
#include "Sprite.h"
#include "Renderer.h"

class Ball : public Sprite
{
public:
	float dx = 0.0002, dy = 0.0002;
	Ball(string pName);
	~Ball();
	void updateBall();
	virtual void draw();
	void move();
	void getCollision();
	void setDir(float pDx, float pDy);
};

