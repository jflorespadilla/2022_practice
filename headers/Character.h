#pragma once
#include <iostream>
#include <string>

class Character {
public:
	virtual std::string getName() { return name; };
	virtual std::string getAbility() { return ability; };
	virtual int getHealth() { return health; };
	virtual int getAttackDamage() { return attackDamage; };

	virtual void setName(std::string nameVal) { name = nameVal; };
	virtual void setAbility(std::string abilityVal) { ability = abilityVal; };
	virtual void setHealth(int healthVal) { health = healthVal; };
	virtual void setAttackDamage(int attackDamageVal) { attackDamage = attackDamageVal; };
	virtual bool checkIfAlive() { return true; };

private:
	std::string name;
	std::string ability;
	int health;
	int attackDamage;
};

