#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "Ball.h"
#include <iostream>
#include <stdlib.h>
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
			cout << "Videojuego creado para la asignatura Desarrollo de Sistemas Gráficos\n";
			cout << "Por Unai Gonzalez, Daniel Hormilla, Arkaitz Merino e Iker Nicolas\n";
			cout << "Agradecimientos a nuestras familias\n";
			cout << "GORA MODERDONIA ASKATUTA\n";
			cout << "Pulsa 0 para volver al Menu\n";
			
		}
		if (aux) {
			aux = false;
		}
		else {
			aux = true;
		}
		if (aux2) {
			aux2 = false;
		}
		else {
			aux2 = true;
		}
		
		cin >> m;
		//para el switch de jugar
		switch (m) {
		case 0:
			aux = true;
			aux2 = false;
			break;

		case 1:
			PlayGame(argc, argv);
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