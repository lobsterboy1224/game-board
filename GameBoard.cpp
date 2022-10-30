/*******************************************************************************

	GameBoard
	CS360

	Programmer:	Blake Leitch
	Date:		5/9/2022

*******************************************************************************/
#include "GameBoard.h"
#include <iostream>
#include <sstream>
using namespace std;
//class constructor
GameBoard::GameBoard(int xLen,int yLen) {
	xMax = xLen;
	yMax = yLen;
}
void GameBoard::addGamePiece(Enemy*& e){
	enemyAmount++;
	enemyList[e->getId()] = e;
}
void GameBoard::printBoard(){
	int xPos[enemyAmount];
	int yPos[enemyAmount];
	int desireLoc = 0;
	bool little = false;
	//stops enemies fom moving off the grid
	for(int m = 0; m<enemyAmount; m++){
		if (enemyList[m]->getX() > xMax){
			enemyList[m]->setX(xMax);
			cout<<"\tOops! That would have stepped off the X grid1!"<<endl;
		}	
		else if (enemyList[m]->getX() < -xMax){
			enemyList[m]->setX(-xMax);
			cout<<"\tOops! That would have stepped off the X grid2!"<<endl;
		}
		if (enemyList[m]->getY() > yMax){
			enemyList[m]->setY(yMax);
			cout<<"\tOops! That would have stepped off the Y grid1!"<<endl;
		}	
		else if (enemyList[m]->getY() < -yMax){
			enemyList[m]->setY(-yMax);
			cout<<"\tOops! That would have stepped off the Y grid2!"<<endl;
		}
		xPos[m] = enemyList[m]->getX();
		yPos[m] = enemyList[m]->getY();		
	}
	//warns that two game pieces are going to move to the same spot
	for(int n = 0; n<enemyAmount; n++){
			for (int o = n; o<enemyAmount; o++){
				if (xPos[n] == xPos[o] & yPos[n] == yPos[o] && o != n)
					cout<<"\tBeware, someone is already in this space!"<<endl;
			}
	}
	
	for (int k = -yMax; k < yMax+1; k++){
		for(int j = -xMax; j<xMax+1; j++){
			little = false;
			for(int m = 0; m<enemyAmount; m++){
				if (j == xPos[m] & k == -yPos[m]){
					little = true;
					desireLoc = m;
				}
			}					
			if(little)
				cout<<enemyList[desireLoc]->getDisplayChar();			
			else if (j == 0)
				cout<<"|";
			else if (k == 0)
				cout<<"—";
			else
				cout<<".";
			if (j+1 == xMax+1)
				cout<<endl;
		}
	}
}
void GameBoard::resetBoard(){
	for(int i = 0; i<enemyAmount; i++)
		enemyList[i] = NULL;
	enemyAmount = 0;
}

