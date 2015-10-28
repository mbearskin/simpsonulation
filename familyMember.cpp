//Programmer: Martha Winger-Bearskin   Date:4/26/13
//File Name: familyMember.cpp          Class:CS 53 A
//Purpose: This file contains the function definitions for the member functions
// in the familyMember class


#include "familyMember.h"
#include <fstream>
#include "house.h"

familyMember::familyMember():m_xCoord(0), m_yCoord(0),alive(true)
{
  ifstream in("fmFILE.txt");
  
  short randNum = rand() % 5;
  for (int i=0; i < randNum ; i++)
  	in >> m_name >> m_sloppy;
  
  in.close();
}


ostream& operator<<(ostream& display, const familyMember &FM)
{
  display << FM.m_name << " is at (" << FM.m_xCoord << "," << FM.m_yCoord << ")"
  << " has sloppiness of " << FM.m_sloppy << endl;
  return display;
}


void familyMember::setLocation(const short x, const short y)
{
  {
    if (x >= 0 && x <= 100)
      m_xCoord = x;
    else
      exit(7);
    if (y >= 0 && y <= 100)
      m_yCoord = y;
    else
      exit(6);
  }
}

bool familyMember:: dropTrash()
{
  bool drop = false;
  int randNum = rand() % 101;
  if (randNum >= m_sloppy)
    drop = true;
  return drop;
  
}
void familyMember:: step(house& simHouse)
{
  short moveX;
	short moveY;
	bool chooseCell= false;
  
  
	while (!chooseCell)
	{
  	moveX = rand() % 4;
    switch(moveX)
  	{
    	case 0:
      	moveX = m_xCoord;
        moveY = (m_yCoord -1);
      	break;
    	case 1:
      	moveX = m_xCoord;
      	moveY = (m_yCoord +1);
      	break;
    	case 2:
      	moveX = (m_xCoord +1);
      	moveY = m_yCoord;
      	break;
    	case 3:
      	moveX = (m_xCoord -1);
      	moveY = m_yCoord;
      	break;
  	}
		if (simHouse.getIcon(moveX, moveY) == TRASH)
    {
      chooseCell = true;
      setLocation(moveX, moveY);
    }
        
    if (simHouse.getIcon(moveX, moveY) == EMPTY)
    {
      chooseCell = true;
      setLocation(moveX, moveY);
      //leave trash 
    }
  	if (simHouse.getIcon(moveX, moveY) == WINDOW)
    {
      chooseCell = true;
      setLocation(moveX, moveY);
      alive = false;
      
    }
   
    
  }
    
  
  
}