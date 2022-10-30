/*******************************************************************************

	Enemy

	Programmer:	Blake Leitch
	Date:		4/11/2022

*******************************************************************************/
#include "Enemy.h"
#include <iostream>
#include <sstream> 
#include <string>
using namespace std;
//class constructor
Enemy::Enemy(int h, int s, int c, int x, int y) {
	health = h;
	str = s;
	con = c;
	xPosition = x;
	yPosition = y;
	alive = true;
/* 
	Unique ID Explanation
	I created a static ID variable that is iterated every time the constructor is called,
	guarenteeing a new ID value for each enemy created.
*/
	static int idGenerator = 0;
	id = idGenerator++;
}
int Enemy::getHealth() const{
	return health;
}
int Enemy::getStr()const{
	return str;
}
int Enemy::getCon()const{
	return con;
}
int Enemy::getX()const{
	return xPosition;
}
int Enemy::getY()const{
	return yPosition;
}
int Enemy::getId()const{
	return id;
}
bool Enemy::isAlive() const{
	return alive;
}
void Enemy::setX(int x){
	xPosition = x;
}
void Enemy::setY(int y){
	yPosition = y;
}


