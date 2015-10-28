//Programmer: Martha Winger-Bearskin   Date:4/25/13
//File Name: cleaner.h                  Class:CS 53 A
//Purpose: This is a header file that contains the cleaner class definition.

/**************************function documentation***************************
 The cleaner() is a contructor for the cleaner class.
 Pre: none
 Post: a cleaner object is created. It's member variables for x and y 
 coordinates as well as stress level is initailzed to 0.
 
 The getIcon() returns the first letter of the name of the cleaner to be used to 
 represent this character on the board.
 Pre: none
 Post: first letter of name returned.
 
 The calcStress() calculates the cleaners stress level
 Pre: this function must be a friend of the house object.
 Post: stress level variable is set.
 
 The setLocation() sets the location of the cleaner.
 Pre: none
 Post: x and y coordinates are set/updated.
 
 The operator<<() overloads << to display the cleaner
 Pre: none
 Post: The cleaners name, location and stress level are displayed to screen
 
 The setName() sets the name of cleaner (does range check).
 Pre: none
 Post: name is set.
 
 **************************************************************************/

#ifndef CLEANER_H
#define CLEANER_H

#include <iostream>
#include <cstdlib>
#include "vacuum.h"
using namespace std;


//constants
const short MAX_NAME = 25;

class house;
class cleaner
{
  public:
  	cleaner(char name[]):
  	m_xCoord(0), m_yCoord(0), m_stressLevel(0), alive(true){setName(name);};
  
  	char getIcon() {return m_name[0];};
  	int 	calcStress(house &H);
  	void setLocation(const int x, const int y);
  	void step(house& simHouse);
  	bool living(){return alive;}
  	short getStress() {return m_stressLevel;}
  
  	friend ostream& operator<<(ostream& display, const cleaner& C);
  
  private:
  
  	char m_name[MAX_NAME];
    short m_stressLevel;
    short m_xCoord;
  	short m_yCoord;
  	vacuum m_vac;
  	bool alive;
  
  	void setName(char name[]);
  
};
#endif 
