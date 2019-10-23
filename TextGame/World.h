#pragma once
#include "Timer.h"
#include <string>
#include <vector>
#include "../SoundManager/SoundManager.h"
using namespace std;

class World
{
	Timer m_timer;
	vector<char> m_cells;
	int all;
	void drawMaze();
	string maze;
	string sampleMaze;
	string size;
	int pos1;
	int pos2;
	int height;
	int width;
	int coins1;
	int coins2;
	int coins;

public:
	World(string nameFile);
	//World(int height, int width);
	~World();

	void draw();
	bool checkMove(int direction, int numPlayer);
	string getMaze();
	int getcoins();
	int getWinner();
	int getCoinsPlayer1();
	int getCoinsPlayer2();
	string createMaze(int x, int y);
};