//CS 360 Gameboard.h
//Blake Leitch May 9 2022
#include "Enemy.h"
#ifndef GAMEBOARD_H
#define	GAMEBOARD_H
class GameBoard {
	private:
		int xMax;
		int yMax;
		Enemy **enemyList;
		int enemyAmount = 0;
	public:
		GameBoard(int, int);
		void addGamePiece(Enemy*&);
		void printBoard();
		void resetBoard();	
};
#endif
