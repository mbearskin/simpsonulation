//
//  main.cpp
//  simpsonulation
//
//  Created by Martha Bearskin on 4/24/13.
//  Copyright (c) 2013 Martha Bearskin. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "house.h"
#include "cleaner.h"
#include "familyMember.h"
using namespace std;

int main()
{
  srand(time(NULL));
  
  char cName[25]= "Marge";
  short boardSize = 15;
  short numTrash = 30;
  bool win;
  bool gameOver= false;
  familyMember fMember;
  cleaner myCleaner(cName);
	house myHouse(boardSize, numTrash ,myCleaner,fMember);
  
	while(!gameOver)
  {
    fMember.step(myHouse);
    if (myCleaner.calcStress(myHouse)==0) // returns trash on floor board
    {
      gameOver = true;
      win = true;
    }
    if (myCleaner.getStress() > 100)
    {
      gameOver = true;
      win = false;
    }
    myCleaner.step(myHouse);
    if (!myCleaner.living())
    {
      gameOver = true;
      win = false;
    }
    cout << myHouse << endl;
  }
  
  cout << "GAME OVER" << endl;
  if (win)
    cout << " congrats you won!" << endl;
  else
    cout << "LOSER you killed Marge!";
  
	return 0;
}

