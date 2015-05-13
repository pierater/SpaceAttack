// ***********************************************************************
// Player.h
// ***********************************************************************


#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"

class Player : public Character
{
    public:
		int score;
        Player();

        // method
        void Shoot(int x_position);
		void increaseScore(int amount);
		int getScore() const {return score;}

};
#endif // class definition ends here
