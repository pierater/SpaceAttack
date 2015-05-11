// ***********************************************************************
// Laser_blast.cpp
// ***********************************************************************

#include <string>
#include <cassert>
#include "Laser_blast.h"

Laser_blast::Laser_blast()
{
    direction = "up";
}

Laser_blast::Laser_blast(string direction, int x_position, int max_x)
{
    assert(direction == "up" || direction == "down");
    this->direction = direction;

    assert(x_position >= 0 && x_position <= max_x);
    this->x_position = x_position;
}

void Laser_blast::setDirection(string direction)
{
    assert(direction == "up" || direction == "down");
    this->direction = direction;
}

void Laser_blast::setPositionX(int position_x, int max_x)
{
    assert(x_position >= 0 && x_position <= max_x);
    this->x_position = x_position;
}

void Laser_blast::move()
{
    // move from ship to enemies or the other way around
}
