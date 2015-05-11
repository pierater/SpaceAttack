// ***********************************************************************
// Player.h
// ***********************************************************************


#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

class Player : public Character
{
    public:
        Player();

        // method
        void Shoot(int x_position);

};
#endif // class definition ends here
