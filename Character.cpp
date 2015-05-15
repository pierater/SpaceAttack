// ***********************************************************************
// Character.cpp
// ***********************************************************************

#include "Character.h"
#include <cassert>

using namespace std;

Character::Character()
{
    health = 3;
    x_coor = 0;
    y_coor = 10;
    shape = 'X';
	isAlive = true;
}

Character::Character(int x_coor, int y_coor, int health, char shape, bool isAlive)
{
    assert(health >= 0);
    this->health = health;

    assert(x_coor >= 0);
    this->x_coor = x_coor;

    assert(y_coor >= 0);
    this->y_coor = y_coor;

    // check the shape input here...
    this->shape = shape;

	this->isAlive = isAlive;
}


// mutators
void Character::setHealth(int health)
{
    assert(health >= 0);
    this->health = health;
}

void Character::setXcoor(int x_coor /*int max_x*/)
{
    assert(x_coor >= 0 /*&& x_coor <= max_x*/);
    this->x_coor = x_coor;
}

void Character::setYcoor(int y_coor /*int max_y*/)
{
    assert(x_coor >= 0 /*&& x_coor <= max_y*/);
    this->x_coor = x_coor;
}

void Character::setShape(char shape)
{
    // check the shape input...
    this->shape = shape;
}

void Character::reduceHealth()
{
	if(health - 1 >= 0)
		health--;
	else
		isAlive = false;
}
//move will go here
void Character::moveRight()
{
    if(x_coor >= 20)
	return;
    else
        x_coor = x_coor + 1;
}
void Character::moveLeft()
{
    if(x_coor <= 1)
        return;
    else
        x_coor = x_coor - 1;
}
void Character::moveDown()
{
    if(y_coor >= 22)
        return;
    else
        y_coor = y_coor + 1;
}

void Character::shiftDown()
{
	if(y_coor + 1 >= 24)
		y_coor = 1;
	else
		y_coor++;
}

void Character::increaseScore(int amount)
{
	score += amount;
}

void Character::increaseHealth()
{
	health++;
}

