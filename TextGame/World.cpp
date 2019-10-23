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
#include <cstdlib>
#include <windows.h>
#include "../SoundManager/SoundManager.h" //relative path to the main header 

using namespace std;

World::World()
{
	coins1 = 0;
	coins2 = 0;
	coins = 0;
}


World::World(string nameFile)
{

		//Code to import maze from file----------------------------------
	ifstream inFile;
	inFile.open("maze.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile";
		exit(1);
	}
	string line;

	bool firstLine = false;
	while (getline(inFile, line))
	{
		if (!firstLine) {
			size = line;
			firstLine = true;
		}
		else {
			maze = line;
		}
	}

	bool first = true;
	string firstNumber = "";
	string secondNumber = "";

	//To separate height and width, with a comma between them
	for (int i = 0; i < size.length(); i++) {
		if (size[i] != ',') {
			if (first) {
				firstNumber += size[i];
			}
			else {
				secondNumber += size[i];
			}
			continue;
		}
		first = false;
	}
	//---------------------------------------------------------

	//this->height = stoi(secondNumber);
	//this->width = stoi(firstNumber);
	
	height = 15;
	width = 5;

	System::hideCursor();
	all = height * width;
	m_cells = vector<char>(all);
	coins1 = 0;
	coins2 = 0;
	coins = 0;
	//sampleMaze = "#,#,#,#,#,#,1, ,?,#,#,?, , ,#,#,?,#,2,#,#,#,#,#,#";

	m_timer.start();
	maze = createMaze(height, width); //to create random maze
	//crear las celdas en si 
	//sampleMaze.erase(remove(sampleMaze.begin(), sampleMaze.end(), ','), sampleMaze.end());
	//maze.erase(remove(maze.begin(), maze.end(), ','), maze.end());
	for (int i = 0; i < maze.size(); i++)
	{
		m_cells[i] = maze.at(i);

		if (maze.at(i) == '1') {
			pos1 = i;
		}
		else if (maze.at(i) == '2') {
			pos2 = i;
		}
		else if (maze.at(i) == '?') {
			coins++;
		}
	}
}

World::~World()
{
}

void World::draw()
{
	drawMaze();

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
			SoundManager::getInstance()->play("../snd/coin.wav");
			//Beep(900, 50);
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
	string maze = "";
	for (int i = 0; i < height * width; i++)
	{
		maze += m_cells[i];
		if ((i + 1) % (width) == 0) {
			maze += '\n';
		}
	}
	return maze;
}
void World::moneda2() {
	coins2++;
}
int World::getcoins()
{
	if (coins == 0) {
		SoundManager::getInstance()->play("../snd/FFVic.ogg");
	}
	return coins;
}
void World::moneda1() {
	coins1++;
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

int World::getCoinsPlayer1()
{
	return coins1;
}

int World::getCoinsPlayer2()
{
	return coins2;
}


void World::drawMaze()
{
	System::clear();
	cout << getMaze();

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

//Code to create a random maze
string World::createMaze(int x, int y) {

	width = x;
	height = y;
	all = x * y;
	m_cells = vector<char>(all);
	for (int i = 0; i < all; i++) m_cells[i] = ' ';

	string maze = "";
	srand(time(0));

	int r;
	int counter = 0;

	bool player1 = false;
	bool player2 = false;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			//If the position is a point of the wall, we add #
			if (i == 0 || j == y - 1 || j == 0 || i == x - 1) {
				maze += "#";
			}
			else {
				//We create both players next to each other
				if (!player1) {
					maze += "1";
					player1 = true;
					continue;
				}
				else if (!player2)
				{
					maze += "2";
					player2 = true;
					continue;
				}

				//Based on a random number between 0 and 100, we add a wall, a coin or a blank space
				r = rand() % 100;
				if (r < 60) {
					//Condition to avoid wall brick next to another one so any player or any coin will be locked
					if (maze[counter + 1] != '#' && maze[counter - y + 3] != '#' && maze[counter - y + 1] != '#' && maze[counter - y + 2] != '#') {
						maze += "#";
					}
					else {
						maze += " ";
					}
				}
				else if (61 < r && r < 80) {
					maze += "?";
				}
				else {
					maze += " ";
				}
			}
			counter++;
		}
	}
	return maze;
}