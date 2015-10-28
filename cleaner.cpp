//Programmer: Martha Winger-Bearskin   Date:4/26/13
//File Name: cleaner.cpp                  Class:CS 53 A
//Purpose: This file contains the function definitions for the member functions
// in the cleaner class

#include <iostream>
#include "cleaner.h"
#include "house.h"
using namespace std;

class trash;
int cleaner::calcStress(house &H)
{
  short countT=0;
  short countFM=0;
  
  for (short i=0; i< H.m_size; i++)
  {
    for(short j= 0; j< H.m_size; j++)
    {
      if (H.m_floor[i][j].icon== TRASH)
        countT++;
      if (H.m_floor[i][j].icon != TRASH && H.m_floor[i][j].icon != EMPTY &&
          H.m_floor[i][j].icon != m_name[0])
          countFM++;
    }
  }
  m_stressLevel =(static_cast<float>(countT)/(H.m_size * H.m_size)*100.0 +
                  2*(countFM));
  return countT;
}
void cleaner::setLocation(const int x, const int y)
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
void cleaner::setName(char name[])
{
  if (strlen(name) <= MAX_NAME)
    strcpy(m_name,name);
  else
    exit(8);
}

void cleaner:: step(house& simHouse)
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
          trash newTrash;
          m_vac.vac(newTrash);
          if (m_vac.getExplode() || m_vac.getShort())
            alive = false;
        }
    if (simHouse.getIcon(moveX, moveY) == TRASH_CAN)
    {
      chooseCell = true;
      setLocation(moveX, moveY);
      m_vac.emptyBag();
    }
    if (simHouse.getIcon(moveX, moveY)== WINDOW)
    {
      chooseCell = true;
    	setLocation(moveX, moveY);
    	alive = false;
    }
    if (simHouse.getIcon(moveX, moveY) == EMPTY)
    {
      chooseCell = true;
      setLocation(moveX, moveY);
    }
      
	}
}

//Non Memeber
ostream& operator<<(ostream& display, const cleaner& C)
{
  display << C.m_name << " is at (" << C.m_xCoord << "," << C.m_yCoord << ")"
  << " has a stress level of " << C.m_stressLevel << endl;
  return display;
}