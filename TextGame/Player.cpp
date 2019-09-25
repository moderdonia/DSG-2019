#include "stdafx.h"
#include "Player.h"
/*
	Metodo para mover jugador en las 4 direcciones
	Guardar puntos que lleva
	Saber posición actual y saber si puede moverse en la dirección deseada

*/
Player::Player()
{
	this->coins = 0;
}


Player::~Player()
{
}


void Player::moveUp()
{
	this->c_y--;
}

void Player::moveDown()
{ 
	this->c_y++;
}

void Player::moveRight()
{
	this->c_x++;
}

void Player::moveLeft()
{
	this->c_x--;
}

int Player::getX()
{
	return this->c_x;
}

int Player::getY()
{
	return this->c_y;
}

int Player::getcoin()
{
	return this->coins;
}

void Player::addcoin()
{
	this->coins++;
}

void Player::setPosition(int x, int y)
{
	this->c_x = x;
	this->c_y = y;
}
