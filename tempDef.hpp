//Programmer: Martha Winger-Bearskin   Date:4/25/13
//File Name: tempDef.h                  Class:CS 53 A
//Purpose: This is file contains the template definition for a templated
// function used by the house class.

#ifndef TEMPDEF_H
#define TEMPDEF_H



template <typename T>
void house::placeObject(T &object)
{
  bool placed = false;
  short x,y;
  
  while(!placed)
  {
    x = rand() % m_size +1;
    y = rand() % m_size + 1;
    if (m_floor[x][y].icon== EMPTY)
    {
      m_floor[x][y].icon = object.getIcon();
      placed = true;
    }
  }
  object.setLocation(x,y);
  return;
}

#endif
