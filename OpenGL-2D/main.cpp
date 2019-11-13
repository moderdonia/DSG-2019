#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "Ball.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	Player player1 = renderer.getPlayer1();
	Player player2 = renderer.getPlayer2();

	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//test objects
	
	
	player1.setColor(255, 0, 0);
	player1.setPosition(0.9, 0.6);
	//pSprite1->setRotation(0.0);
	//pSprite1->setSize(1);
	player1.setDepth(1.5);
	//pSprite1->draw();
	renderer.addObject(&player1);

	player2.setColor(0, 255, 0);
	player2.setPosition(-0.9, -0.6);
	//pSprite2->setRotation(0.0);
	//pSprite2->setSize(1);
	player2.setDepth(1.5);
	//pSprite2->draw();
	renderer.addObject(&player2);

	Ball *pBall = new Ball();
	pBall->setColor(255, 255, 0);
	pBall->setPosition(0, 0);
	pBall->setRotation(0.0);
	pBall->setSize(0.05);
	pBall->setDepth(1.5);
	//pSprite3->draw();
	renderer.addObject(pBall);

	

	while (1)
	{
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();


		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
   
	return 0;

}