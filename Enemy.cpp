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

Enemy::Enemy(string name) : Character(x_coor, y_coor, health, shape)
{
    assert(name != "");
    this->name = name;
}

void Enemy::setName(string name)
{
    assert(name != "");
    this->name = name;
}
