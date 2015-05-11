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
}

Character::Character(int x_coor, int y_coor, int health, char shape)
{
    assert(health >= 0);
    this->health = health;

    assert(x_coor >= 0);
    this->x_coor = x_coor;

    assert(y_coor >= 0);
    this->y_coor = y_coor;

    // check the shape input here...
    this->shape = shape;
}


// mutators
void Character::setHealth(int health)
{
    assert(health >= 0 && health <= 6);
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


// move() will go here
