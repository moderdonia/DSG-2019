#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}

void Sprite::setColor(float r, float g, float b)
{
	//When this method is called, we only store internally what this object's color will be
	//but, we need to pass the color to OpenGL every time the object is drawn
	this->m_r = r;
	this->m_g = g;
	this->m_b = b;
}

void Sprite::setPosition(double x, double y)
{
	//This method only updates internally the object's position. It still needs to be passed to OpenGL before drawing it
	this->m_x = x;
	this->m_y = y;
}

void Sprite::setDepth(double depth)
{
	//This method only updates internally the object's depth. It still needs to be passed to OpenGL before drawing it
	this->m_depth = depth;
}

void Sprite::setRotation(double angle)
{
	//This method only updates internally the object's rotation. It still needs to be passed to OpenGL before drawing it
	this->m_angle = angle;
}

void Sprite::setSize(double size)
{
	//This method only updates internally the object's size. It still needs to be passed to OpenGL before drawing it
	this->m_size = size;
}
double Sprite::getPositionX() {
	return m_x;
}
double Sprite::getPositionY() {
	return m_y;
}

string Sprite::getName()
{
	return this->name;
}

void Sprite::draw()
{
	////update
	////1. Pass the object's color to OpenGL
	//glColor3f(this->m_r, this->m_g, this->m_b);
	////2. Save the current transformation matrix
	//glPushMatrix();
	////3. Set the transformation matrix of the quad using position, size and angle
	//glTranslatef(this->m_x, this->m_y, 0);
	////glRotatef(0, 0, 0, 0);
	//glScalef(m_size, 1, 1);
	////4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
	//glBegin(GL_QUADS);
	//glVertex3f(-0.025, -0.2, -1);
	//glVertex3f(0.025, -0.2, -1);
	//glVertex3f(0.025, 0.2, -1);
	//glVertex3f(-0.025, 0.2, -1);
	//glEnd();
	////5. Restore the transformation matrix
	//glPopMatrix();
}