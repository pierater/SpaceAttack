// ***********************************************************************
// Driver.cpp
// ***********************************************************************


#include <ncurses.h>
#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Laser_blast.h"
#include <cstdlib>
#include <string>
#include <fstream>


using namespace std;

// Main functions to manipulate the game

void create_enemies();
void setupMap();
void shoot();
int collision();
void endGame();
void highScores();
void resetGame();
void resetScores();
void checkBonus();
void pause();

// Global variables
Laser_blast lazers[100];
Enemy enemies[100];
int ENEMIES = 0;
int numLazers = 0;
Player ship;
int counter = 0;
int HIGHSCORE = 0;
int DIFFICULTY = 1;


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
	
	
    

    // initialize player object so that it starts the game
    ship.setShape('A');
    ship.setXcoor(10);
    ship.setYcoor(22);
    

    initscr(); // changes screen to ncurses mode
    keypad(stdscr, TRUE); // allow the use of special keys (arrow keys)
	setupMap();
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
    while(!quit & ship.getHealth() != 0)
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
				shoot();
				break;       
            case 'q':               
                quit = true;        
                break;
			case KEY_BACKSPACE:
				pause();
				break;
				          
        }                           
    clear();
	// Here is where the difficulty of the game is implemented
	// As DIFFICULTY goes up, more enemies spawn
	if(ENEMIES <= DIFFICULTY)
		create_enemies();
	collision(); // Collision tracking of all objects
	checkBonus(); // This gives the player bonuses and changes difficulty based on the score

	// All object movement that isnt the main player
	for(int i = 0; i < numLazers; i++)
		lazers[i].shiftUp();
	for(int i = 0; i < ENEMIES; i++)
		enemies[i].shiftDown();
	
	setupMap(); // Sets up the map for each frame, prints all objects
    move(22, ship.getXcoor());
    printw("A");
    refresh();

    } // this stuff happens in the game.

    // after game events happen from this point forward.
	timeout(500);
	endGame();
    getch();  
    refresh(); // actually display stuff
	timeout(-1);
    endwin();  // end curses mode
    return 0;
}

void create_enemies()
{
	
	// A random number of enemies is created
	srand(time(NULL));
	int random;
	ENEMIES = rand() % 20;
	
	// For each enemy created, they are assigned a random x value, and set to the top of the screen
	for(int i = 0; i < ENEMIES; i++)
	{
		random = (rand() % 19) + 1;
		for(int j = 0; j < ENEMIES; j++)
		{
			if(enemies[j].getXcoor() == random)
			{
				//j = 0;
				random = (rand() % 19) + 1;
			}

		}
		
		enemies[i].setXcoor(random);
		enemies[i].setYcoor(1);
	}
	
}

void setupMap()
{
	
	move(22, 24);

	int score = ship.getScore();
	printw("Score: %i", score); // Prints score
	move(23, 24);
	printw("Lives: ");
	for(int i = 0; i < ship.getHealth(); i++) // A loop that displays an actual number of lives as "A"
		mvprintw(23,i+31,"A");


	// Actually prints all the objects
	for(int i = 0; i <= numLazers; i++)
		mvprintw(lazers[i].getY(), lazers[i].getX(), "|");
	for(int i = 0; i < ENEMIES; i++)
		mvprintw(enemies[i].getYcoor(), enemies[i].getXcoor(), "v");
	
	// Prints the border for the game
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


void shoot()
{
	// Sets the lazers to shoot starting from the current players x pos
	if(numLazers + 1 < 99)
	{
		
		lazers[numLazers].setPositionY(21);
		lazers[numLazers].setPositionX(ship.getXcoor());
		numLazers++;
		//mvprintw(1,30,"|%i", lazers[numLazers].getX());
		return;
	}
	else
		return;

}

int collision()
{
	
	// These three loops check for collisions in a certain order
	// First, lazers are checked if they have reached the edge of the screen\
	// Then, Enemies are tracked and checked with lazers, because they should be shot down first
	// Finally the enemy on the ship is tracked only if the enemy isnt shot down from the lazer
	// Each loop takes the object out of the array and puts it at the end of the array, then decreases 	
	// 		the total amount of objects by one and shifts all other objects down
	for(int i = 0; i < numLazers; i++)
	{
		if(lazers[i].getY() == 0)
		{
			lazers[numLazers] = lazers[i];
			for(int j = numLazers; j > i; j--)
				lazers[j] = lazers[j-1];
			numLazers--;
		}	
	}
	
	for(int i = 0; i < ENEMIES; i++)
	{
		
		for(int k = 0; k < numLazers; k++)
		{
			if(lazers[k].getY() == enemies[i].getYcoor() && lazers[k].getX() == enemies[i].getXcoor())
			{
				ship.increaseScore(enemies[i].getAward());
				enemies[ENEMIES] = enemies[i];
				for(int j = ENEMIES; j > i; j--)
					enemies[j] = enemies[j-1];
				ENEMIES--;
			}
		
		}
	}

	for(int i = 0; i < ENEMIES; i++)
	{
		if(enemies[i].getXcoor() == ship.getXcoor() && enemies[i].getYcoor() == 22)
		{
			ship.reduceHealth();
			enemies[ENEMIES] = enemies[i];
			for(int j = ENEMIES; j > i; j--)
				enemies[j] = enemies[j-1];
			ENEMIES--;
		}
		else if(enemies[i].getYcoor() == 23)
		{
			
			enemies[ENEMIES] = enemies[i];
			for(int j = ENEMIES; j > i; j--)
				enemies[j] = enemies[j-1];
			ENEMIES--;
		}
		
	}
}

void endGame()
{
	
	// This is endgame screen
	// Displays score that is taken from a txt file and our creators and galliga logo
	int ch = getch();
	clear();
	highScores();
	
	while(ch != 'q')
	{
		ch = getch();
		
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
		mvprintw(10,6,"GAME OVER");
		mvprintw(11,6,"Score: %i", ship.getScore());
	
		mvprintw(8,27,"  ________       .__  .__  .__              ");
		mvprintw(9,27," /  _____/_____  |  | |  | |__| _________   ");
		mvprintw(10,27,"/   \\  ___\\__  \\ |  | |  | |  |/ ___\\__  \\  ");
		mvprintw(11,27,"\\    \\_\\  \\/ __ \\|  |_|  |_|  / /_/  > __ \\_");
		mvprintw(12,27," \\______  (____  /____/____/__\\___  (____  /");
		mvprintw(13,27,"        \\/     \\/            /_____/     \\/ ");
		
		mvprintw(14,27,"  _____________________________________________");
		mvprintw(15,27," /                   Creators:                 \\");
		mvprintw(16,27,"|         Martin Almaraz	Juan E. Garcia     |");
		mvprintw(17,27," \\__________________Jose Cortez________________/");
		mvprintw(23,58,"q) Quit  r) Restart :");
		if(ch == 'r')
			resetGame();
		// Our secret menu options...shhh
		else if(ch == '`')
			resetScores();
		else if(ch == '1')
		{
			ship.setHealth(100);
			ship.increaseScore(-1 * ship.getScore());
			DIFFICULTY = 1;
			main();
		}

	}
	

	
	
}

void highScores()
{
	// Opens the high score txt file and checks to see if your score is greater than any of them
	// If so, then the score is inputed and old scores are moved down
	ifstream in;
	in.open("Scores.txt");
	int scores[5];
	
	for(int i = 0; i < 5; i++)
		in >> scores[i];
	
	in.close();
	
	
	
	
	
	for(int i = 0; i < 5; i++)
	{
		if(ship.getScore() > scores[i])
		{
			for(int j = 5; j > i; j--)
				scores[j] = scores[j - 1];
			scores[i] = ship.getScore();
			i = 5;
		}
	}
	
	ofstream out;
	out.open("Scores.txt");
	for(int i = 0; i < 5; i++)
	{
		out << scores[i] << endl;
	}
	
	out.close();
	
	in.open("Scores.txt");
	mvprintw(14,5,"HIGH SCORES:");
	for(int i = 0; i < 5; i++)
	{
		mvprintw(16+i, 5, "%i) %i", i+1, scores[i]);
	}
	move(40,40);
	in.close();

}

void resetGame()
{

	// Resets the game and its variables
	ship.setHealth(3);
	ship.increaseScore(-1 * ship.getScore());
	DIFFICULTY = 1;
	main();
	


}

void resetScores()
{
	// SHHH...secret menu option that resets all scores to 0
	ofstream out;
	out.open("Scores.txt");
	out.close();
}

void checkBonus()
{
	// Checks to see if the player has scored enough points to increase the difficulty and give bonus 
	// lives
	if(ship.getScore() % 1000 == 0 && ship.getScore() != 0)
	{
		ship.increaseScore(50);
		DIFFICULTY++;
		ship.increaseHealth();
	}
}

void pause()
{
	int ch = getch();
	clear();

	while(ch != KEY_BACKSPACE)
	{
		ch = getch();
		
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
		mvprintw(10,6,"PAUSED");
		mvprintw(11,6,"Score: %i", ship.getScore());
	
		mvprintw(8,27,"  ________       .__  .__  .__              ");
		mvprintw(9,27," /  _____/_____  |  | |  | |__| _________   ");
		mvprintw(10,27,"/   \\  ___\\__  \\ |  | |  | |  |/ ___\\__  \\  ");
		mvprintw(11,27,"\\    \\_\\  \\/ __ \\|  |_|  |_|  / /_/  > __ \\_");
		mvprintw(12,27," \\______  (____  /____/____/__\\___  (____  /");
		mvprintw(13,27,"        \\/     \\/            /_____/     \\/ ");
		
		mvprintw(14,27,"  _____________________________________________");
		mvprintw(15,27," /                   Creators:                 \\");
		mvprintw(16,27,"|         Martin Almaraz	Juan E. Garcia     |");
		mvprintw(17,27," \\__________________Jose Cortez________________/");
		if(ch == 'r')
			resetGame();
		// Our secret menu options...shhh
		else if(ch == '`')
			resetScores();
		else if(ch == '1')
			ship.setHealth(100);

	}

}

































