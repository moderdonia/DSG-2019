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
{	//cell(x,y) = width * y + x para saber la posicion de una casilla en una matriz
	System::hideCursor();
	maze = "";
	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();
	ifstream infile;
	infile.open(nameFile);


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
	this->height = height;
	this->width = width;
	System::hideCursor();
	all = height * width;
	m_cells = vector<char>(all);
	coins1 = 0;
	coins2 = 0;
	coins = 0;
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

		if (sampleMaze.at(i) == '1') {
			pos1 = i;
		}
		else if (sampleMaze.at(i) == '2') {
			pos2 = i;
		}
		else if (sampleMaze.at(i) == '?') {
			coins++;
		}
	}

	//getMaze();

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


bool World::checkMove(int direction, int numPlayer) //0 == left ; 1 == up ; 2 == rigth ; 3 == down
{
	int i; //Índice de la casilla del jugador
	int x; //Índice de la casilla a la que se quiere mover

	if (numPlayer == 1) {
		i = pos1;
	}
	else {
		i = pos2;
	}

	switch (direction)
	{
	case 0:
		x = i - 1;
		break;
	case 1:
		x = i - width;
		break;
	case 2:
		x = i + 1;
		break;
	case 3:
		x = i + width;
		break;
	}

	if (m_cells[x] == '#' || m_cells[x] == '1' || m_cells[x] == '2') {
		return false;
	}
	else {
		if (m_cells[x] == '?') 
		{
			coins--;
			if (numPlayer == 1) 
			{
				coins1++;
				m_cells[x] = '1';
				pos1 = x;
			}
			else 
			{
				coins2++;
				m_cells[x] = '2';
				pos2 = x;
			}
		}
		else 
		{
			if (numPlayer == 1) 
			{
				m_cells[x] = '1';
				pos1 = x;
			}
			else 
			{
				m_cells[x] = '2';
				pos2 = x;
			}
		}
		m_cells[i] = ' ';
	}

	return true;
}

string World::getMaze()
{
	maze = "";
	for (int i = 0; i < height * width; i++)
	{
		maze += m_cells[i];
		if ((i + 1) % (width) == 0) {
			maze += '\n';
		}
	}
	return maze;
}

int World::getcoins()
{
	return coins;
}

int World::getWinner()
{
	if (coins1 > coins2) {
		return 1;
	}
	else if (coins1 < coins2) {
		return 2;
	}
	else {
		return 0;
	}
}


void World::drawMaze()
{
	
	System::clear();
	cout << getMaze();
	
	//TODO: -draw the maze: walls and each of the cells
	// escribir por dentro
	
	
	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

