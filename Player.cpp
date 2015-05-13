// ***********************************************************************
// Player.cpp
// ***********************************************************************

#include "Player.h" 
#include "Character.h"

using namespace std;

Player::Player() : Character(/*x_coor, y_coor, health, shape*/)
{
    score = 0;
}

void Player::Shoot(int x_position)
{
    // this part should call a laser
    int x = 0;
}

void Player::increaseScore(int amount)
{
	score += amount;
}
