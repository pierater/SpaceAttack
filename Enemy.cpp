// ***********************************************************************
// Enemy.cpp
// ***********************************************************************


#include <cassert>
#include "Character.h"
#include "Enemy.h"


using namespace std;

Enemy::Enemy() : Character()
{
    name = "bug";
}

Enemy::Enemy(string name, int x_coor, int y_coor, int health, char shape, bool isAlive) : Character(x_coor, y_coor, health, shape, isAlive)
{
    assert(name != "");
    this->name = name;
}

void Enemy::setName(string name)
{
    assert(name != "");
    this->name = name;
}
