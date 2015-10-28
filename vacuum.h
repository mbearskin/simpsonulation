//Programmer: Martha Winger-Bearskin   Date:5/08/13
//File Name: vacuum.h                  Class:CS 53 A
//Purpose: This is a header file that contains the vacuum class definition.

#ifndef VACUUM_H
#define VACUUM_H
#include <iostream>
#include "trash.h"

const int BAG_CAPACITY =35;
class vacuum
{
public:
  vacuum():m_trashTally(0),m_shortOut(0),m_exploded(0){}
  void vac(const trash &item);
  void emptyBag();
  bool isExploded();
  void isSparky(const int sparkNum);
  bool getShort(){return m_shortOut;}
  bool getExplode(){return m_exploded;}
  
  
private:
  trash m_bag[BAG_CAPACITY];
  int m_trashTally;
  bool m_shortOut;
  bool m_exploded;
  
};

#endif