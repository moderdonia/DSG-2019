#pragma once

class Player
{
	int c_x;
	int c_y;
	int coins;

public:
	Player();
	~Player();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	int getX();
	int getY();
	int getcoin();
	void addcoin();
	void setPosition(int x, int y);

};

