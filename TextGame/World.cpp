#include "stdafx.h"
#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <fstream>
#include "System.h"
#include "stdafx.h"
#include <stdio.h>
#include <istream>

World::World(std::string nameFile)
{
	System::hideCursor();

	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//TODO: initalize everything else
	//...
}

World::World(int height, int width)
{
	System::hideCursor();

	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	vector<char> m_cells = vector<char>(all);
	//TODO: initalize everything else
	//...
	//crear las celdas en si 
	all = height * width;
	//for (int i = 0; i < height; i ++) {
	//	for (int j = 0; j < width; j++) {			
	//		if (j == 3) {
	//			cout << '-' + '\n';
	//		}
	//		else {
	//			cout << '-';
	//		}
	//	}
	//	cout << '-';
	//}

}

World::~World()
{
}


void World::draw()
{
	drawMaze();

	//TODO: -write the points each player has
	

	//TODO: -write the time elapsed since the beginning
	//		-set the proper position/color
	std::cout << m_timer.getElapsedTime() << "   ";
}


void World::drawMaze()
{
	System::clear();

	//TODO: -draw the maze: walls and each of the cells
	// escribir por dentro
	
	
	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}