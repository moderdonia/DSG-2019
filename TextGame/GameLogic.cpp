#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"

GameLogic::GameLogic(Player& player1, Player& player2, World& world)
	: m_player1(player1), m_player2(player2), m_world(world)
{
	
}


GameLogic::~GameLogic()
{
}

void GameLogic::processInput()
{
	if (!System::keyHit())
		return; //no keyboard event to be processed


	while (System::keyHit())
	{
		char c = System::getNextKey();
		switch (c)
		{

		case 'a':
			//Do whatever needs to be done when 'a' is pressed
			m_world.checkMove(0, m_player1);
			//m_player1.moveLeft();
			break;
		case 's':
			//Do whatever needs to be done when 's' is pressed
			m_player1.moveDown();
			break;
		case 'w':
			m_player1.moveUp();
			break;
		case 'd':
			m_world.checkMove(2, m_player1);
			//m_player1.moveRight();
			break;
		case '4':
			m_player2.moveLeft();
			break;
		case '8':
			m_player2.moveUp();
			break;
		case '6':
			m_player2.moveRight();
			break;
		case '2':
			m_player2.moveDown();
			break;
		case 27:
			//'Esc' key pressed. Exit the game
			esc = true;
			return;
		}
	}
}

bool GameLogic::gameHasEnded()
{	
	//si quedan monedas no acaba
	//if () {
	//	return false;
	//}
	//si no quedan monedas
	/*else if () {
		return true;
	}
	else if (esc) {
		return true;
	}*/
	return false;
}