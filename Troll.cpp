/*******************************************************************************

	Troll

	Programmer:	Blake Leitch
	Date:		4/11/2022

*******************************************************************************/
#include "Troll.h"
#include "Enemy.h"
#include <iostream>
#include <sstream> 
#include <string>
#include <random>
using namespace std;
//class constructor
Troll::Troll(int h, int s, int c, int x, int y): Enemy(h,s,c,x,y){
	print();
	maxHealth = h;
}
void Troll::update (){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, 2);
	if (distr(gen) == 1){
		uniform_int_distribution<> distX(7,10);
		setX(distr(gen)+getX());
	}
	else{
		uniform_int_distribution<> distX(-10,-7);
		setX(distr(gen)+getX());
	}
	if (health + getCon() < maxHealth){
		health = getCon() + getHealth();
		cout << "Troll healed " << getCon() << " health! New health: " << getHealth() << " HP" << endl;
	}
	else{
		health = maxHealth;
		cout << "Troll healed to full! New Health: " << getHealth() << " HP" << endl;
	}
}
void Troll::attack () const{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distAttack(1,8);
	int attackStrength = distAttack(gen) + getStr();
	cout << "Troll " << getId() << " attacks a random passerby for " << attackStrength << " damage!" << endl;
}
void Troll::injure (int value){
	int attackStrength = value - getCon()*1.5;
	if (attackStrength > 0){
		health = getHealth() - attackStrength;
		if(getHealth() > 0)
			cout << "Troll " << getId() << " takes " << attackStrength << " damage! Current hp = " << getHealth() << endl;
		else{
			cout << "Troll " << getId() << " takes " << attackStrength << " damage!" << endl << "Troll " << getId() << " has been slain!" << endl;
			alive = false;
		}
	}
	else
		cout << "The passerby tries to attack Troll " << getId() << ", but it's not very effective..." << endl;
}
void Troll::print () const{
	cout << "Troll " << getId() << " @ (" << getX() << ", " << getY() << ") hp = " << getHealth() << endl;
}

const char Troll::getDisplayChar() const{
	if (alive)
		return 'T';
	return 't';
}

