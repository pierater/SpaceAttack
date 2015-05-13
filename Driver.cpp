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

using namespace std;
void create_enemies(Enemy *enemies);
void setupMap();

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
	Enemy *enemies = new Enemy[5];
    

    // objects
    Player ship;
    ship.setShape('A');
    ship.setXcoor(10);
    ship.setYcoor(10);
    

    initscr(); // changes screen to ncurses mode
    keypad(stdscr, TRUE); // allow the use of special keys (arrow keys)
	setupMap();
    refresh();
    // make the cursor invisible
    curs_set(0);

    // place the player in the screen
    move(ship.getYcoor(), ship.getXcoor());
    printw("A");
    refresh();

    // crate enemies!!!


    // start the game!!!
    while(!quit)
    {
        ch = getch();               
        switch(ch)                  
        {                           
            case KEY_RIGHT:         
                ship.setXcoor(ship.getXcoor() + 1);
                break;              
                                    
            case KEY_LEFT:          
                ship.setXcoor(ship.getXcoor() - 1);
                break;              
                                    
            case 'q':               
                quit = true;        
                break;              
        }                           
    clear();
	setupMap();
    move(ship.getYcoor(), ship.getXcoor());
    printw("A");
    refresh();

    } // this stuff happens in the game.

    // after game events happen from this point forward.
    getch();  
    refresh(); // actually display stuff
    endwin();  // end curses mode
    return 0;
}

void create_enemies(Enemy *enemies)
{
    srand(time(NULL));
	int random = rand() % 5;
	
	//for()
	
}

void setupMap()
{
	for(int i = 1; i <= 22; i++)
	{
		move(i, 1);
		printw("w");
		move(i, 21);
		printw("t");
		
	}
		
	for(int i = 0; i < 21; i++)
	{
		move(23, i);
		printw("g");
	}

}


















