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


void Player::draw()
{
	//update
	//1. Pass the object's color to OpenGL
	glColor3f(this->m_r, this->m_g, this->m_b);
	//2. Save the current transformation matrix
	glPushMatrix();
	//3. Set the transformation matrix of the quad using position, size and angle
	glTranslatef(this->m_x, this->m_y, 0);
	//glRotatef(0, 0, 0, 0);
	glScalef(m_size, 1, 1);
	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
	glBegin(GL_QUADS);
	glVertex3f(-0.025, -0.2, -1);
	glVertex3f(0.025, -0.2, -1);
	glVertex3f(0.025, 0.2, -1);
	glVertex3f(-0.025, 0.2, -1);
	glEnd();
	//5. Restore the transformation matrix
	glPopMatrix();

	Sprite::draw();
}

void Player::moveUp() {
	this->m_y += 0.1;
}

void Player::moveDown() {
	this->m_y -= 0.1;
}