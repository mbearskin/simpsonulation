//Programmer: Martha Winger-Bearskin   Date:4/25/13
//File Name: familyMember.h            Class:CS 53 A
//Purpose:This is a header file that contains the familyMember class definition.

/**************************function documentation***************************
 The familyMember() is a construtor for the familyMember class. It initialzes
 x and y coordinates to 0 Then reads in a name and sloppyness factor form a file 
 randomly and sets those variables accordingly.
 Pre: none
 Post: creates object and sets member variables.
 
 The operator<<() overloads << to display the family member object
 Pre: none
 Post: The family member's name, location and sloppiness are displayed to screen
 
 The setLocation() sets the location of the family member.
 Pre: none
 Post: x and y coordinates are set/updated.
 
 The getIcon() returns the first letter of the name of the family member
 to be used to represent this character on the board.
 Pre: none
 Post: first letter of name returned.
 **************************************************************************/

#ifndef FAMILYMEMBER_H
#define FAMILYMEMBER_H

#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX=25;

class house;
class familyMember
{
	public:
  
  	familyMember();
  	friend ostream& operator<<(ostream& display, const familyMember &FM);
  	char getIcon() {return m_name[0];};
  	void setLocation(const short x, const short y);
  	bool dropTrash();
  	void step(house& simHouse);
  	bool living() {return alive;}
  
	private:
  
  	char m_name[MAX];
  	short m_xCoord, m_yCoord;
  	short m_sloppy;
  	bool alive;

  
};









#endif 