//Programmer: Martha Winger-Bearskin   Date:4/25/13
//File Name: house.h                  Class:CS 53 A
//Purpose: This is a header file that contains the house class definition.

/**************************function documentation***************************
 The house() is a contructor for the house class.
 Pre: none
 Post: a house object is created.
 
 The getSize() returns the size for the game board.
 Pre: none
 Post: size of the floor of the house is returned.
 
 The operator<<() is a friend of the house class. It overloads the << operator 
 to diplay the house class (gameboard).
 Pre: none
 Post: a house object is set up to be displayed as a gameboard.
 
 The setSize() this sets the size of the gameboard.
 Pre: none
 Post: m_size is set to the size passed if it is smaller than the max size of 
 gameboard.
 
 The setTrash() this sets number of trash items 
 Pre: none
 Post: m_trash is set to the number passed if it is smaller than the max size of
 gameboard and positve.
 
 The emptyboard() places a space in each element of the 2D array representing 
 gameboard.
 Pre: none
 Post: each element of m_floor is a ' '.
 
 The scatterTrash() places trash on gamesboard randomly, according to the amount
 of trash items in m_trash.
 Pre: none
 Post: 'T' character is placed on game board randomly.
 
 The setSize() this sets the size of the gameboard.
 Pre: none
 Post: m_size is set to the size passed if it is smaller than the max size of
 gameboard.
 
 The placeObject() is a templated function that is used by the house class to
 place a cleaner object and a family member object on the gameboard
 Pre: accessor functions for the name and location of object must be defined.
 Post: a object is placed on the game board
**************************************************************************/

#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <cstdlib>
#include "cleaner.h"
#include "familyMember.h"
#include "cell.h"
using namespace std;

//Constants
const short MAX_SIZE = 25;
const char EMPTY = ' ';
const char TRASH = 'T';
const char WINDOW = 'W';
const char WALL = 'b';
const char TRASH_CAN = 'C';

class cleaner;
class familyMember;
class house
{
  public:
  
    house (unsigned short size, unsigned short trash, cleaner &C,
         	familyMember &FM);//add windows/walls/can
  	short getSize() const {return m_size;};
   	friend ostream& operator<<(ostream& display, const house& h);
  	friend int cleaner::calcStress(house &H); // calcStress function of cleaner
                                            		// friended to access "gameplan"
  	char getIcon(const short i, const short j){return m_floor[i][j].icon;}
   
  
  private:
  
    //variables
    cell m_floor[MAX_SIZE][MAX_SIZE];
    unsigned short m_size;
    unsigned short m_trash;
  	
  
    //functions
  	void setSize(const unsigned short s);
  	void setTrash(const unsigned short t);
    void emptyFloor();
    void scatterTrash();
    template <typename T>
    void placeObject(T &object);
  	
    
  
};

#include "tempDef.hpp"
#endif 

