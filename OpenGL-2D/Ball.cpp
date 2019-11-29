#include "Ball.h"
#include "stdafx.h"
#include "Player.h"

Renderer m_renderer;

Ball::Ball(string pName)
{
	this->name = pName;
}


Ball::~Ball()
{
}

void Ball::updateBall() {
	
}

void Ball::draw()
{
	//update
//update
	//1. Pass the object's color to OpenGL
	glColor3f(this->m_r, this->m_g, this->m_b);
	//2. Save the current transformation matrix
	glPushMatrix();
	//3. Set the transformation matrix of the quad using position, size and angle
	glTranslatef(this->m_x, this->m_y, 0);
	//glRotatef(0, 0, 0, 0);
	//glScalef(m_size, 1, 1);
	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
	glBegin(GL_QUADS);
	glVertex3f(-0.025, -0.025, -1);
	glVertex3f(0.025, -0.025, -1);
	glVertex3f(0.025, 0.025, -1);
	glVertex3f(-0.025, 0.025, -1);
	glEnd();
	//5. Restore the transformation matrix
	glPopMatrix();

	Sprite::draw();
}

void Ball::move()
{
	this->getCollision();
	this->m_x += this->dx;
	this->m_y += this->dy;
}

void Ball::getCollision() {
	if (m_y >= 0.975 || m_y <= -0.975) {
		this->setDir(this->dx, -(this->dy));
	}

	if ((m_x >= (((Player*)m_renderer.get()->getObjectByName("player2"))->getX() - 0.025) && m_x <= (((Player*)m_renderer.get()->getObjectByName("player2"))->getX() + 0.025) &&
			m_y >= ((Player*)m_renderer.get()->getObjectByName("player2"))->getY() - 0.2 &&
			m_y <= ((Player*)m_renderer.get()->getObjectByName("player2"))->getY() + 0.2) 
		||
		(m_x <= (((Player*)m_renderer.get()->getObjectByName("player1"))->getX() + 0.025) && m_x <= (((Player*)m_renderer.get()->getObjectByName("player1"))->getX() + 0.025) &&
			(m_y >= ((Player*)m_renderer.get()->getObjectByName("player1"))->getY() - 0.2) && 
			(m_y <= ((Player*)m_renderer.get()->getObjectByName("player1"))->getY() + 0.2))) {
		this->setDir(-(this->dx), this->dy);
		this->setDir(this->dx * 1.1, this->dy * 1.054484884);
	}
}

void Ball::setDir(float pDx, float pDy)
{
	this->dx = pDx;
	this->dy = pDy;
}