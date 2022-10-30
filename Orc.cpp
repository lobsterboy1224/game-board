/*******************************************************************************

	Orc

	Programmer:	Blake Leitch
	Date:		4/11/2022

*******************************************************************************/
#include "Orc.h"
#include "Enemy.h"
#include <iostream>
#include <sstream> 
#include <string>
#include <random>
using namespace std;
//class constructor
Orc::Orc(int h, int s, int c, int x, int y): Enemy(h,s,c,x,y){
	print();
}
void Orc::update (){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(-5, 5);
	int movement = distr(gen);
	setX(getX() + movement);
	setY(getY() + movement);
}
void Orc::attack () const{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distAttack(1,6);
	int attackStrength = distAttack(gen) + getStr();
	cout << "Orc " << getId() << " attacks a random passerby for " << attackStrength << " damage!" << endl;
}
void Orc::injure (int value){
	int attackStrength = value - getCon();
	if (attackStrength > 0){
		health = getHealth()-attackStrength;
		if(getHealth() > 0)
			cout << "Orc takes " << attackStrength << " damage! Current hp = " << getHealth() << endl;
		else{
			cout << "Orc " << getId() << " takes " << attackStrength << " damage!" << endl << "Orc " << getId() << " has been slain!" << endl;
			alive = false;
		}
	}
	else
		cout << "The passerby tries to attack Orc " << getId() << ", but it's not very effective..." << endl;
}
void Orc::print () const{
	cout << "Orc " << getId() << " @ (" << getX() << ", " << getY() << ") hp = " << getHealth() << endl;
}

const char Orc::getDisplayChar() const{
	if (alive)
		return 'O';
	return 'o';
}
