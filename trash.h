//Programmer: Martha Winger-Bearskin   Date:5/08/13
//File Name: trash.h                  Class:CS 53 A
//Purpose: This is a header file that contains the trash class definition.

#ifndef TRASH_H
#define TRASH_H

#include <iostream>
using namespace std;

class trash
{
	public:
  	trash();
  string getName()const{return m_name;}
  int getSparkyness()const{return m_sparky;}
  
  
	private:
  	string m_name;
  	int m_sparky;
};


#endif 