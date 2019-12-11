#pragma once
#include "Sprite.h"
#include "TextureManager.h"

class Ball : public Sprite
{
public:
	Ball(string pName);
	
	~Ball();
	
	void updateBall();
	virtual void draw();
	void move(float vx, float vy);
};

