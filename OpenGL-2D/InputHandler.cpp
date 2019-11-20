#include "stdafx.h"
#include "InputHandler.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "./Player.h"
#include "Renderer.h"

InputHandler* InputHandler::m_pInputHandler = nullptr;

InputHandler::InputHandler(Renderer& renderer): m_renderer(renderer)
{
	m_pInputHandler = this;
}


InputHandler::~InputHandler()
{
}

void InputHandler::initialize()
{
	glutKeyboardFunc(__processKeyboard);
	//glutKeyboardUpFunc
}

void setPlayers(Player& player1, Player& player2) {

}

void InputHandler::processKeyboard(unsigned char key, int x, int y)
{
	//keyboard callback function
	switch (key)
	{
	case 'w':
		//p1 up
		((Player*)m_renderer.getObjectByName("player1"))->moveUp();
		
		break;
	case 's':
		//p1 down
		((Player*)m_renderer.getObjectByName("player1"))->moveDown();
		break;
	case '8':
		//p2 up 
		((Player*)m_renderer.getObjectByName("player2"))->moveUp();
		break;
	case '5':
		//p2 down
		((Player*)m_renderer.getObjectByName("player2"))->moveDown();
		break;
	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}