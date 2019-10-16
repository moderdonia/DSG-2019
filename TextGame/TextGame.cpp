// TextGame.cpp : Main program entry point
//


#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"
#include "../SoundManager/SoundManager.h" //relative path to the main header 

int main()
{
	SoundManager soundManager;
	World world("maze.txt");
	Player player1, player2;
	GameLogic gameLogic(player1, player2, world);

	//SoundManager* pSoundManager = soundManager.getInstance();

	soundManager.load("../snd/soundtrack-01.wav");
	soundManager.load("../snd/FFVic.ogg");
	soundManager.load("../snd/coin.wav");
	soundManager.play("../snd/soundtrack-01.wav");


	while (!gameLogic.gameHasEnded())
	{

		world.draw();

		gameLogic.processInput();
	}
	
	system("PAUSE");
	return 0;
}