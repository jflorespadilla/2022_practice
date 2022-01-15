#pragma once
#include <iostream>
#include <string>
#include "Character.h"

class hero: public Character {
public:
	hero();
	hero(std::string name, std::string ability, int health, int defense, int attackDamage);
	hero(const hero& createdHero);
	~hero();

	std::string getName();
	std::string getAbility();
	int getHealth();
	int getDefense();
	int getAttackDamage();

	void setName(std::string nameVal);
	void setAbility(std::string abilityVal);
	void setHealth(int healthVal);
	void setDefense(int defenseVal);
	void setAttackDamage(int attackDamageVal);

	void attackCharacter( Character& otherCharacter);
	bool checkIfAlive();

private:
	std::string name;
	std::string ability;
	int health;
	int defense;
	int attackDamage;
	bool isAlive;
};

