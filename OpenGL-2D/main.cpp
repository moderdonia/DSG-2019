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
	

	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//test objects
	Player *pPlayer= new Player("player1");
	pPlayer->setColor(255, 0, 0);
	pPlayer->setPosition(0.9, 0);
	//pSprite1->setRotation(0.0);
	//pSprite1->setSize(1);
	pPlayer->setDepth(1.5);
	//pSprite1->draw();
	renderer.addObject(pPlayer);

	Player *pPlayer2 = new Player("player2");
	pPlayer2->setColor(0, 255, 0);
	pPlayer2->setPosition(-0.9, 0);
	//pSprite2->setRotation(0.0);
	//pSprite2->setSize(1);
	pPlayer2->setDepth(1.5);
	//pSprite2->draw();
	renderer.addObject(pPlayer2);

	Ball *pBall = new Ball("ball");
	pBall->setColor(255, 255, 0);
	pBall->setPosition(0, 0);
	//pBall->setRotation(0.0);
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
		
		((Ball*)renderer.getObjectByName("ball"))->move(-0.0001, 0.0001);
		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
   
	return 0;

}