#pragma once
#include <iostream>
#include <string>

class hero {
public:
	hero();
	hero(hero& createdHero);
	~hero();
	std::string getName();
	std::string getAbility();
	int getHealth();
	int getDefense();
	int getAttackDamage();

private:
	std::string name;
	std::string ability;
	int health;
	int defesne;
	int attackDamage;
};

