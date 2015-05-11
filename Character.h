// ***********************************************************************
// Character.h
// ***********************************************************************


#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>


using namespace std;

class Character
{
    protected:
        int health,
            x_coor,
            y_coor;
        char shape;

    public:
        Character();
        Character(int x_coor, int y_coor, int health, char shape);

        //accessors
        int getHealth()const{return health;}
        int getXcoor()const{return x_coor;}
        int getYcoor()const{return y_coor;}
        char getShape()const{return shape;}

        //mutators
        void setHealth(int health);
        void setXcoor(int x_coor /* int max_x*/);
        void setYcoor(int y_coor /* int max_y*/);
        void setShape(char shape);

        //methods
        // move(); -> wasd, a for left, d for right or direction arrows
        //
};
#endif // end class definition
