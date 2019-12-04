#pragma once
#include "Sprite.h"
#include "Renderer.h"
#include "Timer.h"

class Ball : public Sprite
{
	Timer m_timer;
public:
	float dx = 0.112, dy = 0.0841;
	int hit_counter = 0;
	bool hasBeenGoal;
	//left -> 0, right ->1
	int dir_first_player = 0;
	Ball(string pName);
	~Ball();

	void resetHitCounter();
	void resetGoal();
	int addPoint();
	void initializeDirection();
	void updateBall();
	void setInitialDirection(int dir);
	virtual void draw();
	void move();
	void getCollision();
	void setDir(float pDx, float pDy);
};

