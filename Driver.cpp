// ***********************************************************************
// Driver.cpp
// ***********************************************************************

#include <iostream>
#include <string>
#include <ncurses.h>
#include "Board.h"
#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Laser_blast.h"
#include <cstdlib>
#include <string>

using namespace std;
void create_enemies(Enemy *enemies);
void setupMap(Player &ship, Laser_blast lazers[100], int numLazers);
int shoot(int numLazers, Player &ship);
int collision(Player &ship, int numLazers);

Laser_blast lazers[100];

int main()
{
// ********************************************************************
// Things to implement:
// > use ncurses to grab the size of the terminal and adjust the game
// using this information.
// > use colors to represent the health of the player and enemies.
// ********************************************************************


    // variables
    bool quit = false; // continue while false.
    int ch; // variable for user input
    int dir; // used to select the direction of the ship.
	int ENEMIES;
	int numLazers = 0;
	Enemy enemies[5];
    

    // objects
    Player ship;
    ship.setShape('A');
    ship.setXcoor(10);
    ship.setYcoor(22);
    

    initscr(); // changes screen to ncurses mode
    keypad(stdscr, TRUE); // allow the use of special keys (arrow keys)
	setupMap(ship, lazers, numLazers);
    refresh();
    // make the cursor invisible
    curs_set(0);
	timeout(100);
    // place the player in the screen
    move(22, ship.getXcoor());
    printw("A");
    refresh();

    // crate enemies!!!


    // start the game!!!
    while(!quit)
    {
		//for(int i = 0; i < numLazers; i++)
			//		lazers[i].shiftUp();
		ch = 'L';
        ch = getch();
		mvprintw(0,30,"%i", ch);             
        switch(ch)                  
        {                           
            case KEY_RIGHT:         
                ship.moveRight();
                break;              
                                    
            case KEY_LEFT:          
                ship.moveLeft();
                break;              
            case ' ':
				numLazers=  shoot(numLazers, ship);
				break;       
            case 'q':               
                quit = true;        
                break;
			case 'L':
				for(int i = 0; i < numLazers; i++)
					lazers[i].shiftUp();
				          
        }                           
    clear();
	numLazers = collision(ship, numLazers);
	for(int i = 0; i < numLazers; i++)
					lazers[i].shiftUp();
	
	setupMap(ship, lazers, numLazers);
    move(22, ship.getXcoor());
    printw("A");
    refresh();

    } // this stuff happens in the game.

    // after game events happen from this point forward.
    getch();  
    refresh(); // actually display stuff
	timeout(-1);
    endwin();  // end curses mode
    return 0;
}

void create_enemies(Enemy *enemies)
{
    srand(time(NULL));
	int random = rand() % 5;
	
	//for()
	
}

void setupMap(Player &ship, Laser_blast lazers[100], int numLazers)
{
	
	move(22, 24);

	int score = ship.getScore();
	printw("Score: %i", score);
	move(23, 24);
	printw("Lives: ");
	for(int i = 0; i < ship.getHealth(); i++)
		mvprintw(23,i+31,"A");
	//mvprintw(0, 30, "|%i %i %i %i", lazers[numLazers].getY(), ship.getXcoor(), numLazers, lazers[numLazers].getX());
	for(int i = 0; i <= numLazers; i++)
		mvprintw(lazers[i].getY(), lazers[i].getX(), "|");

	for(int i = 1; i <= 22; i++)
	{
		move(i, 0);
		printw("#");
		move(i, 21);
		printw("#");
		
	}
		
	for(int i = 0; i < 22; i++)
	{
		move(23, i);
		printw("#");
	}
	
	for(int i = 0; i < 22; i++)
	{
		move(0, i);
		printw("#");
	}
	

}


int shoot(int numLazers, Player &ship)
{
	if(numLazers + 1 < 99)
	{
		
		lazers[numLazers].setPositionY(21);
		lazers[numLazers].setPositionX(ship.getXcoor());
		numLazers++;
		//mvprintw(1,30,"|%i", lazers[numLazers].getX());
		return numLazers;
	}
	else
		return numLazers;

}

int collision(Player &ship, int numLazers)
{
	for(int i = 0; i < numLazers; i++)
	{
		if(lazers[i].getY() == 0)
		{
			lazers[numLazers] = lazers[i];
			for(int i = 0; i < numLazers-1; i++)
				lazers[i] = lazers[i+1];
			return numLazers--;
		}
		
				
	}

}
















