// ***********************************************************************
// Board.cpp
// ***********************************************************************

#include "Board.h"
#include <cassert>

using namespace std;

Board::Board()
{
    y_height = 15;
    x_width = 30;
}

Board::Board(int y_height, int x_width)
{
    assert(y_height > 5 && y_height <= 100);
    this->y_height = y_height;

    assert(x_width >= 10 && x_width <= 400);
    this->x_width = x_width;
}


// mutators
void Board::setY(int y_height)
{
    assert(y_height > 5 && y_height <= 100);
    this->y_height = y_height;
}


void Board::setX(int x_width)
{
    assert(x_width >= 10 && x_width <= 400);
    this->x_width = x_width;
}
