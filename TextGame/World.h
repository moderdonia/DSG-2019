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

public:
	World(string nameFile);
	World(int height, int width);
	~World();

	void draw();
};