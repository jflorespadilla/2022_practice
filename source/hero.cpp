#include "../headers/hero.h"

hero::hero() {
	name = "default";
	ability = "none";
	health = 10;
	defesne = 20;
	attackDamage = 5;
}

hero::hero(hero& createdHero) {
	name = createdHero.getName();
	ability = createdHero.getAbility();
	health = createdHero.getHealth();
	defesne = createdHero.getDefense();
	attackDamage = createdHero.getAttackDamage();
}

hero::~hero() {
	name = "";
	ability = "";
	health = 0;
	defesne = 0;
	attackDamage = 0;
}

std::string hero::getName() {
	return name;
}

std::string hero::getAbility() {
	return ability;
}

int hero::getHealth() {
	return health;
}

int hero::getDefense() {
	return defesne;
}

int hero::getAttackDamage() {
	return attackDamage;
}
