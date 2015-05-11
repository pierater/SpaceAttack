// ***********************************************************************
// Laser_blast.h
// ***********************************************************************


#ifndef LASER_BLAST_H
#define LASER_BLAST_H
#include <string>

using namespace std;

class Laser_blast
{
    private:
        string direction;
        int x_position;

    public:
        Laser_blast();
        Laser_blast(string direction, int x_position, int max_x);

        //accessors
        string getDirection()const{return direction;}

        //mutators
        void setDirection(string direction);
        void setPositionX(int position_x, int max_x);

        //methods
        void move();
};
#endif // end class definition
