#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"
#include <time.h>

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
			//m_player1.moveLeft();
			m_world.checkMove(0, 1);
			break;
		case 's':
			//Do whatever needs to be done when 's' is pressed
			//m_player1.moveDown();
			m_world.checkMove(3, 1);
			break;
		case 'w':
			//m_player1.moveUp();
			m_world.checkMove(1, 1);
			break;
		case 'd':
			m_world.checkMove(2, 1);
			//m_player1.moveRight();
			break;
		case '4':
			//m_player2.moveLeft();
			m_world.checkMove(0, 2);
			break;
		case '8':
			//m_player2.moveUp();
			m_world.checkMove(1, 2);
			break;
		case '6':
			//m_player2.moveRight();
			m_world.checkMove(2, 2);
			break;
		case '5':
			//m_player2.moveDown();
			m_world.checkMove(3, 2);
			break;
		case 27:
			//'Esc' key pressed. Exit the game
			esc = true;
		default:
			gameHasEnded();
			
		}
	}
}

bool GameLogic::gameHasEnded()
{	
	System::clear();
	if (m_world.getcoins() == 0) {
		if (m_world.getWinner() != 0) {
			std::cout << "Juego terminado, ha ganado el jugador " << m_world.getWinner() << endl;
		}
		else {
			std::cout << "Juego terminado, ha habido un empate" << endl;
		}

		return true;
	}
	return false;
}