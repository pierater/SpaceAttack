// ***********************************************************************
// Enemy.h
// ***********************************************************************


#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "Character.h"

using namespace std;

class Enemy : public Character
{
    protected:
        string name;
		int award;

    public:
        Enemy();
        Enemy(string name, int x_coor, int y_coor, int health, char shape, bool isAlive);

        //accessors
        string getName()const{return name;}
		int getAward() const {return award;}
        
        //mutators
        void setName(string name);

        //methods
        // ???
};
#endif // class definition ends here
