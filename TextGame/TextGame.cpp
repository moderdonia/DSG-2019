// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"


int main()
{
	World world("maze.txt");
	Player player1, player2;
	GameLogic gameLogic(player1, player2, world);

	while (!gameLogic.gameHasEnded())
	{
		world.draw();

		gameLogic.processInput();
	}
	
	system("PAUSE");
	return 0;
}