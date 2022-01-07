#include "../headers/hero.h"

hero::hero() {
	name = "default";
	ability = "none";
	health = 10;
	defense = 20;
	attackDamage = 5;
}

hero::hero(std::string name, std::string ability, int health, int defense, int attackDamage) {
	this->name = name;
	this->ability = ability;
	this->health = health;
	this->defense = defense;
	this->attackDamage = attackDamage;
}

hero::hero(hero& createdHero) {
	name = createdHero.getName();
	ability = createdHero.getAbility();
	health = createdHero.getHealth();
	defense = createdHero.getDefense();
	attackDamage = createdHero.getAttackDamage();
}

hero::~hero() {
	name = "";
	ability = "";
	health = 0;
	defense = 0;
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
	return defense;
}

int hero::getAttackDamage() {
	return attackDamage;
}

void hero::setName(std::string nameVal) {
	name = nameVal;
}

void hero::setAbility(std::string abilityVal) {
	ability = abilityVal;
}

void hero::setHealth(int healthVal) {
	health = healthVal;
}

void hero::setDefense(int defenseVal) {
	defense = defenseVal;
}

void hero::setAttackDamage(int attackDamageVal) {
	attackDamage = attackDamageVal;
}
