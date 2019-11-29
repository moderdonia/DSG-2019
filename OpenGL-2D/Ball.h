#pragma once
#include "Sprite.h"
#include "Renderer.h"

class Ball : public Sprite
{
public:
	float dx = 0.000112, dy = 0.0000841;
	Ball(string pName);
	~Ball();
	void updateBall();
	virtual void draw();
	void move();
	void getCollision();
	void setDir(float pDx, float pDy);
};

