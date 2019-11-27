#include "Ball.h"
#include "stdafx.h"


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

void Ball::move(float vx, float vy)
{
	this->m_x += vx;
	this->m_y += vy;
}


/*
atributos dirección en bola que actualizan el move, metodos para definir el vector de movimiento, posición anterior, interfaz collider


*/