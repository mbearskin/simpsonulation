//Programmer: Martha Winger-Bearskin   Date:5/08/13
//File Name: vacuum.h                  Class:CS 53 A
//Purpose: This is a header file that contains the cell struct function implementation

#include "cell.h"


ostream& operator <<(ostream & out, const cell &c)
{
  out << c.icon;
  return out;
}