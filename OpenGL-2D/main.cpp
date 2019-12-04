#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "Ball.h"
#include <iostream>
using namespace std;
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

void PlayGame(int argc, char **argv)
{
	Renderer *renderer = new Renderer();
	InputHandler inputHandler(*renderer);

	renderer->getPlayer1();
	renderer->getPlayer2();

	renderer->initialize(argc, argv);
	inputHandler.initialize();


	//test objects


	renderer->getPlayer1().setColor(255, 0, 0);
	renderer->getPlayer1().setPosition(0.9, 0.6);
	//pSprite1->setRotation(0.0);
	//pSprite1->setSize(1);
	renderer->getPlayer1().setDepth(1.5);
	//pSprite1->draw();
	renderer->addObject(&renderer->getPlayer1());

	renderer->getPlayer2().setColor(0, 255, 0);
	renderer->getPlayer2().setPosition(-0.9, -0.6);
	//pSprite2->setRotation(0.0);
	//pSprite2->setSize(1);
	renderer->getPlayer2().setDepth(1.5);
	//pSprite2->draw();
	renderer->addObject(&renderer->getPlayer2());

	Ball *pBall = new Ball();
	pBall->setColor(255, 255, 0);
	pBall->setPosition(0, 0);
	pBall->setRotation(0.0);
	pBall->setSize(0.05);
	pBall->setDepth(1.5);
	//pSprite3->draw();
	renderer->addObject(pBall);



	while (1)
	{
		renderer->drawScene();
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();


		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
}

int main(int argc, char** argv)
{
	int m;
	do {
		
		//Hacer menu 
		cout << "__________________________________________________________________________________________________________		\n\n";
		cout << "::::::::::: :::    ::: :::::::::  :::::::::   ::::::::        :::::::::   ::::::::  ::::    :::  ::::::::		\n";
		cout << "    :+:     :+:    :+: :+:    :+: :+:    :+: :+:    :+:       :+:    :+: :+:    :+: :+:+:   :+: :+:    :+:		\n";
		cout << "    +:+     +:+    +:+ +:+    +:+ +:+    +:+ +:+    +:+       +:+    +:+ +:+    +:+ :+:+:+  +:+ +:+			\n";
		cout << "    +#+     +#+    +:+ +#++:++#:  +#++:++#+  +#+    +:+       +#++:++#+  +#+    +:+ +#+ +:+ +#+ :#:			\n";
		cout << "    +#+     +#+    +#+ +#+    +#+ +#+    +#+ +#+    +#+       +#+        +#+    +#+ +#+  +#+#+# +#+   +#+#		\n";
		cout << "    #+#     #+#    #+# #+#    #+# #+#    #+# #+#    #+#       #+#        #+#    #+# #+#   #+#+# #+#    #+#		\n";
		cout << "    ###      ########  ###    ### #########   ########        ###         ########  ###    ####  ########		\n";
		cout << "__________________________________________________________________________________________________________		\n";
		cout << "\n Que quieres hacer?\n\n";
		cout << "	1  Jugar\n";
		cout << "	2  Creditos\n";
		cout << "	3  Salir\n";

		cin >> m;
		//para el switch de jugar
		switch (m) {
		case 1:
			PlayGame(argc, argv);
			break;
		case 2:

			cout << "Jugar";
			break;

		}
	} while (m != 3);

	
   //switch de jugar

	//switch informacion 
	return 0;

}