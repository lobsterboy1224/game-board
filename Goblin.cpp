/*******************************************************************************

	Goblin

	Programmer:	Blake Leitch
	Date:		4/11/2022

*******************************************************************************/
#include "Goblin.h"
#include "Enemy.h"
#include <iostream>
#include <sstream> 
#include <string>
#include <random>
using namespace std;
//class constructor
Goblin::Goblin(int h, int s, int c, int x, int y): Enemy(h,s,c,x,y){
	print();
	
}
void Goblin::update (){	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distX(-3,3);
	setX(distX(gen) + getX());
	uniform_int_distribution<> distY(-2,2);
	setY(distY(gen) + getY());
}
void Goblin::attack () const{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distAttack(1,4);
	int attackStrength = distAttack(gen) + getStr();
	cout << "Goblin " << getId() << " attacks a random passerby for " << attackStrength << " damage!" << endl;
}
void Goblin::injure (int value){
	int attackStrength = value - getCon()/2;
	if (attackStrength > 0){
		health = getHealth()-attackStrength;
		if(getHealth() > 0)
			cout << "Goblin " << getId() << " takes " << attackStrength << " damage! Current hp = " << getHealth() << endl;
		else{
			cout << "Goblin " << getId() << " takes " << attackStrength << " damage!" << endl << "Goblin " << getId() << " has been slain!" << endl;
			alive = false;
		}
	}
	else
		cout << "The passerby tries to attack Goblin " << getId() << ", but it's not very effective..." << endl;
}
void Goblin::print () const{
	cout << "Goblin " << getId() << " @ (" << getX() << ", " << getY() << ") hp = " << getHealth() << endl;
}

const char Goblin::getDisplayChar() const{
	if (alive)
		return 'G';
	return 'g';
}
