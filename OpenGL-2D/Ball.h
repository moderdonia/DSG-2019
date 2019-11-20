#pragma once
#include "Sprite.h"

class Ball : public Sprite
{
public:
	Ball();
	~Ball();
	void updateBall();
	virtual void draw();
};

