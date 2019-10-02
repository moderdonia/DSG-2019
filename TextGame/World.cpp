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

using namespace std;

World::World(std::string nameFile)
{
	System::hideCursor();
	maze = "";
	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//TODO: initalize everything else
	//...
	/*
		ifstream inputFile("example.txt", fstream::in);
		if(inputFile.is_open())
		{
			for (int i = 0; i< 9; i++)
			{
				inputFile >> datos[i];
				inputFile >> delimiter;
			}
			inputFile.close();
		}
	*/
}

World::World(int height, int width)
{
	System::hideCursor();
	all = height * width;
	vector<char> m_cells = vector<char>(all);
	
	sampleMaze = "#,#,#,#,#,#,1, ,?,#,#,?, , ,#,#,?,#,2,#,#,#,#,#,#";
	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//m_cells = sampleMaze.spl

	//for (int i = 0; i < sampleMaze.size - 1; i++) {

	//}


	//TODO: initalize everything else
	//...
	//crear las celdas en si 
	sampleMaze.erase(remove(sampleMaze.begin(), sampleMaze.end(), ','), sampleMaze.end());
	for (int i = 0; i < sampleMaze.size() ; i ++) 
	{
		m_cells[i] = sampleMaze.at(i);

	}

	for (int i = 0; i < height * width ; i++ ) 
	{
		maze += m_cells[i];
		if ((i+1)%(width) == 0) {
			maze += '\n';
		}
	}



	/*for (int i = 0; i < height; i ++) {
		for (int j = 0; j < width; j++) {			
			if (j == width - 1) {

				maze += '-' + '\n';
			}
			else {

				maze += '-';
			}
		}
	}*/

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

bool World::checkMove(int direction, Player player) //0 == left ; 1 == up ; 2 == rigth ; 3 == down
{
	return false;
}


void World::drawMaze()
{
	
	System::clear();
	cout << maze;
	
	//TODO: -draw the maze: walls and each of the cells
	// escribir por dentro
	
	
	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

