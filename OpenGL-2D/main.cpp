#include "stdafx.h"
#include <iostream>
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "Ball.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include <chrono>
#include <time.h>
#include "Timer.h"
#include "Text.h"
#include <chrono>
#include <thread>


using namespace std;
string play(int argc, char** argv) {
	Renderer renderer;
	InputHandler inputHandler(renderer);
	string contador = "";
	renderer.initialize(argc, argv);
	inputHandler.initialize();

	Timer *timer = new Timer();
	timer->start();

	Text2D *text = new Text2D("Contador",-0.05,0.7,1);
	text->setColor(255, 255, 255);

	//pSprite1->setRotation(0.0);
	//pSprite1->setSize(1);
	//pSprite1->draw();
	renderer.addObject(text);

	//test objects
	Player *pPlayer = new Player("player2");
	pPlayer->setColor(255, 255, 255);
	pPlayer->setPosition(0.9, 0);
	//pSprite1->setRotation(0.0);
	//pSprite1->setSize(1);
	pPlayer->setDepth(1.5);
	//pSprite1->draw();
	renderer.addObject(pPlayer);

	Player *pPlayer2 = new Player("player1");
	pPlayer2->setColor(255, 255, 255);
	pPlayer2->setPosition(-0.9, 0);
	//pSprite2->setRotation(0.0);
	//pSprite2->setSize(1);
	pPlayer2->setDepth(1.5);
	//pSprite2->draw();
	renderer.addObject(pPlayer2);

	Ball *pBall = new Ball("ball");
	pBall->setColor(255, 255, 255);
	pBall->setPosition(0, 0);
	//pBall->setRotation(0.0);
	pBall->setSize(0.05);
	pBall->setDepth(1.5);
	pBall->initializeDirection();
	//pSprite3->draw();
	renderer.addObject(pBall);

	bool stop = false;
	string victoria;
	contador = "0 : 0" ;


	
	while (!stop)
	{
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();
		text->setText(contador);

		if (pPlayer->getPoints() == 3) {
			stop = true;
			victoria = "Ha ganado el jugador 2";
			renderer.destroyW();	
			
		}
		if (pPlayer2->getPoints() == 3) {
			stop = true;
			victoria =  "Ha ganado el jugador 1";
			renderer.destroyW();
			
		}

		if (pBall->hasBeenGoal) {
			contador = to_string(pPlayer2->getPoints()) +  " : " + to_string(pPlayer->getPoints());
			pBall->resetHitCounter();
			pBall->setPosition(0, 0);
			pBall->initializeDirection();
			pBall->resetGoal();
			Beep(523, 200);
			Beep(784, 500);
		}

		//((Ball*)renderer.getObjectByName("ball"))->move();
		//RENDER////////////////////
		////////////////////////////
		if (!stop) {
			glutPostRedisplay();
			glutSwapBuffers();
		}
	}
	//renderer.~Renderer();
	return victoria;
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
			cout << "Videojuego creado para la asignatura Desarrollo de Sistemas Graficos\n";
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
			system("CLS");
			cout << play(argc, argv);
			Beep(523, 200);  // 523 hertz (C5) for 500 milliseconds
			Beep(587, 200);
			Beep(659, 200);
			Beep(698, 200);
			Beep(784, 200);
			this_thread::sleep_for(std::chrono::milliseconds(5000));
			break;
		case 2:

			aux = false;
			aux2 = true;
			break;

		}
		
	} while (m != 3);


	//switch de jugar

	 //switch informacion 

	
}

