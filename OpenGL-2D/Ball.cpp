#include "Ball.h"
#include "stdafx.h"
#include "Player.h"
#include "TextureManager.h"

Renderer m_renderer;

Ball::Ball(string pName)
{
	this->name = pName;
	this->hasBeenGoal = false;
	m_timer.start();
	TextureManager::getInstance()->create2DTexture("img/ball.png");
}


Ball::~Ball()
{
}

int Ball::addPoint()
{
	if (this->m_x <= -0.975) {
		this->hasBeenGoal = true;
		return 2;
	}
	else if (this->m_x >= 0.975) {
		this->hasBeenGoal = true;
		return 1;
	}
	else {
		return 0;
	}
}

void Ball::initializeDirection()
{
	//////////////////////////////////////////////
	//RANDOM BALL INITIAL DIRECTION///////////////
	srand((unsigned)time(0));
	int a = rand() % 100;
	float x, y;

	if (a >= 75)
	{//x and y positive
		x = rand() % 7 + 6;
		y = rand() % 7 + 6;
		this->setInitialDirection(1);
	}
	else if (a < 75 && a >= 50)
	{//x and y negative
		x = -(rand() % 7 + 6);
		y = -(rand() % 7 + 6);
		this->setInitialDirection(0);
	}
	else if (a < 75 && a >= 50)
	{//x positive y negative
		x = rand() % 7 + 6;
		y = -(rand() % 7 + 6);
		this->setInitialDirection(1);
	}
	else
	{//x negative y positive
		x = -(rand() % 7 + 6);
		y = rand() % 7 + 6;
		this->setInitialDirection(0);
	}
	//////////////////////////////////////////////
	this->setDir(x * 0.038, y * 0.038);
}

void Ball::updateBall() {
	
}

void Ball::setInitialDirection(int dir)
{
	this->dir_first_player = dir;
}



void Ball::draw()
{
	TextureManager::getInstance()->useTexture("img/ball.png");
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
	glTexCoord2f(1, 1);
	glVertex3f(-0.025, -0.025, -1);
	glTexCoord2f(0, 1);
	glVertex3f(0.025, -0.025, -1);
	glTexCoord2f(0, 0);
	glVertex3f(0.025, 0.025, -1);
	glTexCoord2f(1, 0);
	glVertex3f(-0.025, 0.025, -1);
	glEnd();
	//5. Restore the transformation matrix
	glPopMatrix();

	Sprite::draw();
	this->move();
	if (this->addPoint() == 1) {
		((Player*)m_renderer.get()->getObjectByName("player1"))->addPoint();
	}
	else if (this->addPoint() == 2) {
		((Player*)m_renderer.get()->getObjectByName("player2"))->addPoint();
	}
}

void Ball::move()
{
	double t = m_timer.getElapsedTime(true);
	this->getCollision();
	this->m_x += this->dx*t;
	this->m_y += this->dy*t;
	//((Player*)m_renderer.get()->getObjectByName("player2"))->setY(this->m_y);
	//((Player*)m_renderer.get()->getObjectByName("player1"))->setY(this->m_y);
}

void Ball::getCollision() {
	if (m_y >= 0.975 || m_y <= -0.975) {
		this->setDir(this->dx, -(this->dy));
	}

	if (this->hit_counter % 2 != this->dir_first_player &&((m_x >= (((Player*)m_renderer.get()->getObjectByName("player2"))->getX() - 0.025) && m_x <= (((Player*)m_renderer.get()->getObjectByName("player2"))->getX() + 0.025) &&
		(m_y >= ((Player*)m_renderer.get()->getObjectByName("player2"))->getY() - 0.2) &&
		(m_y <= ((Player*)m_renderer.get()->getObjectByName("player2"))->getY() + 0.2))))
	{
		Beep(900, 50);
		this->setDir(-(this->dx), this->dy);
		this->setDir(this->dx * 1.1, this->dy * 1.054484884);
		this->hit_counter++;
	}
	if(this->hit_counter % 2 == this->dir_first_player && ((m_x <= (((Player*)m_renderer.get()->getObjectByName("player1"))->getX() + 0.025) && m_x <= (((Player*)m_renderer.get()->getObjectByName("player1"))->getX() + 0.025) &&
			(m_y >= ((Player*)m_renderer.get()->getObjectByName("player1"))->getY() - 0.2) && 
			(m_y <= ((Player*)m_renderer.get()->getObjectByName("player1"))->getY() + 0.2)))) 
	{
		Beep(900, 50);
		this->setDir(-(this->dx), this->dy);
		this->setDir(this->dx * 1.1, this->dy * 1.054484884);
		this->hit_counter++;
	}
}


void Ball::resetHitCounter()
{
	this->hit_counter = 0;
}

void Ball::resetGoal()
{
	this->hasBeenGoal = false;
}

void Ball::setDir(float pDx, float pDy)
{
	this->dx = pDx;
	this->dy = pDy;
}