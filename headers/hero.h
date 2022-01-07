#pragma once
#include <iostream>
#include <string>

class hero {
public:
	hero();
	hero(std::string name, std::string ability, int health, int defense, int attackDamage);
	hero(hero& createdHero);
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

private:
	std::string name;
	std::string ability;
	int health;
	int defense;
	int attackDamage;
};

