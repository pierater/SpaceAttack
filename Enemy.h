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

    public:
        Enemy();
        Enemy(string name);

        //accessors
        string getName()const{return name;}
        
        //mutators
        void setName(string name);

        //methods
        // ???
};
#endif // class definition ends here
