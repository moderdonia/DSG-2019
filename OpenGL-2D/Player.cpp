#include "Player.h"
#include "stdafx.h"
using namespace std;

Player::Player(string pName)
{
	this->name = pName;
}


Player::~Player()
{
}




void Player::moveUp() {
	this->m_y += 0.1;
}

void Player::moveDown() {
	this->m_y -= 0.1;
}