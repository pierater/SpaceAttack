// ***********************************************************************
// Board.h
// ***********************************************************************


#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Board
{
    private:
        int y_height,
            x_width;
    public:
        Board();
        Board(int y_height, int x_width);

        //accessors
        int getY()const{return y_height;} // lines
        int getX()const{return x_width;}  // characters

        //mutators
        void setY(int y_height);
        void setX(int x_width);

        // methods
        //void display_stats(); -> implement later
        //star simulation
};
#endif // ends class definition
