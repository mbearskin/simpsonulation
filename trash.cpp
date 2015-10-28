//Programmer: Martha Winger-Bearskin   Date:5/08/13
//File Name: trash.cpp                  Class:CS 53 A
//Purpose: This file that contains the trash class implementation

#include "trash.h"
#include <fstream>

trash :: trash()
{
  ifstream in("trashFile.txt");
  int count = 0;
  while(in >> m_sparky >> m_name)
    count++;
  
	short randNum = rand() % (count +1);
  for (int i=0; i < randNum ; i++)
  	in >> m_sparky >> m_name;
  
  in.close();
  
  //m_sparky = 15;
  //m_name = "trashy";
}