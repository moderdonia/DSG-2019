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
	if (this->m_y < 0.75) {
		this->m_y += 0.08;
	}
	
}

void Player::moveDown() {
	if (this->m_y > -0.75) {
		this->m_y -= 0.08  ;
	}
}