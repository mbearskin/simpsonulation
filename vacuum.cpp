//Programmer: Martha Winger-Bearskin   Date:5/08/13
//File Name: vacuum.h                  Class:CS 53 A
//Purpose: This file that contains the vacuum class implementation

#include "vacuum.h"

void vacuum::vac(const trash &pieceOtrash)
{
  if (isExploded())
    return;
  else
  {
    m_bag[m_trashTally-1]=pieceOtrash;
    isSparky(pieceOtrash.getSparkyness());
  }
  return;
}
void vacuum::emptyBag()
{
  cout << "Emptying bag..." << endl;
	for (int i=0; m_trashTally; i++)
    cout << m_bag[i].getName() << endl;
}
bool vacuum::isExploded()
{
  if (m_trashTally == BAG_CAPACITY)
    m_exploded = true;
  return m_exploded;
}

void vacuum::isSparky(const int sparkNum)
{
  int randNum = rand() % 101;
  if(randNum >= m_bag[m_trashTally -1].getSparkyness())
    m_shortOut = true;
  
}
