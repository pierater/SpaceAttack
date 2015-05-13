// ***********************************************************************
// Player.h
// ***********************************************************************


#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

class Player : public Character
{
    public:
		char score;
        Player();

        // method
        void Shoot(int x_position);
		void increaseScore(int amount);
		char getScore() const {return score;}

};
#endif // class definition ends here
