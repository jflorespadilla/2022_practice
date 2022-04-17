#pragma once
#include <iostream>
#include <string>

class Character {
public:
	virtual std::string getName() = 0;
	virtual std::string getAbility() = 0;
	virtual int getHealth() = 0;
	virtual int getAttackDamage() = 0;

	virtual void setName(std::string nameVal) = 0;
	virtual void setAbility(std::string abilityVal) = 0;
	virtual void setHealth(int healthVal) = 0;
	virtual void setAttackDamage(int attackDamageVal) = 0;
	virtual bool checkIfAlive() = 0;

private:
	std::string name;
	std::string ability;
	int health;
	int attackDamage;
};

