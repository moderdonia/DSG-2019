#pragma once
#include "Timer.h"
#include <string>
#include <vector>
using namespace std;

class World
{
	Timer m_timer;
	vector<char> m_cells;
	int all;
	void drawMaze();
	string maze;
	string sampleMaze;
	int pos1;
	int pos2;
	int height;
	int width;
	int coins1;
	int coins2;
	int coins;

public:
	World(string nameFile);
	World(int height, int width);
	~World();

	void draw();
	bool checkMove(int direction, int numPlayer);
	string getMaze();
	int getcoins();
	int getWinner();
	string createMaze(int x, int y);
};