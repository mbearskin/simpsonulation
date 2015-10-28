//Programmer: Martha Winger-Bearskin   Date:5/08/13
//File Name: vacuum.h                  Class:CS 53 A
//Purpose: This is a header file that contains the cell struct prototype and
//helper function prototypes


#ifndef CELL_H
#define CELL_H

#include <iostream>
using namespace std;

struct cell
{
  char icon;
  bool hasTrash;
  bool person;
  bool can;
  cell():hasTrash(false),person(false),can(false){}
};

//overload << operator to display this
ostream& operator <<(ostream & out, cell &c);

#endif 
