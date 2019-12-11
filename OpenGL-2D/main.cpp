#include "stdafx.h"
#include <iostream>
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "Ball.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include <chrono>
#include <time.h>
#include "Timer.h"

using namespace std;

int playGame(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);

	renderer.initialize(argc, argv);
	inputHandler.initialize();

	Timer *timer = new Timer();
	timer->start();

	//test objects
	Player *pPlayer= new Player("player2");
	pPlayer->setColor(255, 0, 0);
	pPlayer->setPosition(0.9, 0);
	//pSprite1->setRotation(0.0);
	//pSprite1->setSize(1);
	pPlayer->setDepth(1.5);
	//pSprite1->draw();
	renderer.addObject(pPlayer);

	Player *pPlayer2 = new Player("player1");
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
	pBall->initializeDirection();
	//pSprite3->draw();
	renderer.addObject(pBall);

	bool stop = false;
	

	while (!stop)
	{
		renderer.drawScene();
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();
		
		if (pPlayer->getPoints() == 3){
			stop = true;
			cout << "Ha ganado el jugador 2";
		}
		if (pPlayer2->getPoints() == 3) {
			stop = true;
			cout << "Ha ganado el jugador 1";
		}

		if (pBall->hasBeenGoal) {
			pBall->resetHitCounter();
			pBall->setPosition(0, 0);
			pBall->initializeDirection();
			pBall->resetGoal();
			cout << pPlayer->getPoints();
			cout << pPlayer->getPoints();
		}

		//((Ball*)renderer.getObjectByName("ball"))->move();
		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}

	return 0;
}

int main(int argc, char** argv)
{
	int m;
	bool aux = true;
	bool aux2 = false;
	do {
		system("CLS");
		//Hacer menu 
		cout << "__________________________________________________________________________________________________________\n";
		cout << "::::::::::: :::    ::: :::::::::  :::::::::   ::::::::        :::::::::   ::::::::  ::::    :::  ::::::::\n";
		cout << "    :+:     :+:    :+: :+:    :+: :+:    :+: :+:    :+:       :+:    :+: :+:    :+: :+:+:   :+: :+:    :+:\n";
		cout << "    +:+     +:+    +:+ +:+    +:+ +:+    +:+ +:+    +:+       +:+    +:+ +:+    +:+ :+:+:+  +:+ +:+\n";
		cout << "    +#+     +#+    +:+ +#++:++#:  +#++:++#+  +#+    +:+       +#++:++#+  +#+    +:+ +#+ +:+ +#+ :#:\n";
		cout << "    +#+     +#+    +#+ +#+    +#+ +#+    +#+ +#+    +#+       +#+        +#+    +#+ +#+  +#+#+# +#+   +#+#\n";
		cout << "    #+#     #+#    #+# #+#    #+# #+#    #+# #+#    #+#       #+#        #+#    #+# #+#   #+#+# #+#    #+#\n";
		cout << "    ###      ########  ###    ### #########   ########        ###         ########  ###    ####  ########\n";
		cout << "__________________________________________________________________________________________________________		\n";
		if (aux) {
			cout << "\n Que quieres hacer?\n\n";
			cout << "	1  Jugar\n";
			cout << "	2  Creditos\n";
			cout << "	3  Salir\n";
		}
		if (aux2) {
			cout << "Videojuego creado para la asignatura Desarrollo de Sistemas Gr�ficos\n";
			cout << "Por Unai Gonzalez, Daniel Hormilla, Arkaitz Merino e Iker Nicolas\n";
			cout << "Agradecimientos a nuestras familias\n";
			cout << "GORA MODERDONIA ASKATUTA\n";
			cout << "Pulsa 0 para volver al Menu\n";
			
		}
		
		
		cin >> m;
		//para el switch de jugar
		switch (m) {
		case 0:
			aux = true;
			aux2 = false;
			break;

		case 1:
			playGame(argc, argv);
			break;
		case 2:
			
			aux = false;
			aux2 = true;
			break;

		}
	} while (m != 3);

	
   //switch de jugar

	//switch informacion 
	return 0;

}