//Programmer: Martha Winger-Bearskin   Date:4/26/13
//File Name: house.cpp                  Class:CS 53 A
//Purpose: This file contains the function definitions for the member functions
// in the house class

#include "house.h"
using namespace std;

house::house(unsigned short size, unsigned short trash, cleaner &C,
       familyMember &FM)
{
  setTrash(trash);
  setSize(size);
  emptyFloor();
  placeObject(C);
  placeObject(FM);
  scatterTrash();
}
//Private Functions
void house::setSize(const unsigned short s)
{
  if (s >= 0 && s < MAX_SIZE)
    m_size = s;
  else
    exit (9);
}
void house::setTrash(const unsigned short t)
{
  if (t >= 0 && t < (MAX_SIZE * MAX_SIZE) - 6)//leave room for people and can
    m_trash = t;
  else
    exit (9);
}
void house::emptyFloor()
{
  for (int i = 0; i < m_size; i++)
    for (int j = 0; j < m_size; j++)
      m_floor[i][j].icon = EMPTY;
  return;
}

void house::scatterTrash()
{
  unsigned short numTrash = m_trash;
  short x,y;
  while(numTrash > 0)
  {
    x = rand() % m_size;
    y = rand() % m_size;
    if (m_floor[x][y].icon == EMPTY)
    {
      m_floor[x][y].icon = TRASH;
      m_floor[x][y].hasTrash= true;
      numTrash--;
    }
  }
    return;
}

// Non Member
ostream& operator <<(ostream &display, const house &h)
{
  display << "+";
  for (short i = 0; i < h.m_size; i++) //displays top "line"
    display << "--+";
  display << endl;
  
  for(short i = 0; i < h.m_size; i++)
  {
    for(short j = 0; j < h.m_size; j++)
    {
      display << "| ";
      display << &h.m_floor[i][j];
    }
    display << "|" << endl;
    display << "+";
    for (short i = 0; i < h.m_size; i++) //displays bottom "line"
      display << "--+";
    display << endl;
  }
  return display;
}




