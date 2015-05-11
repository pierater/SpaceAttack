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

using namespace std;


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
    

    // objects
    Player ship;
    ship.setShape('A');
    ship.setXcoor(10);
    ship.setYcoor(10);
    

    initscr(); // changes screen to ncurses mode
    keypad(stdscr, TRUE); // allow the use of special keys (arrow keys)
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

void create_enemies()
{
    
}
