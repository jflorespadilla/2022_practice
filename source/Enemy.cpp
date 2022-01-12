#include "..\headers\Enemy.h"

Enemy::Enemy() {
	name = "default";
	ability = "Melee";
	health = 5;
	attackDamage = 3;
}

Enemy::Enemy(const Enemy& createdEnemy)	{
	name = createdEnemy.name;
	ability = createdEnemy.ability;
	health = createdEnemy.health;
	attackDamage = createdEnemy.attackDamage;
}

Enemy::Enemy(std::string nameVal, std::string abilityVal, int healthVal, int attackDamageVal) {
	name = nameVal;
	ability = abilityVal;
	health = healthVal;
	attackDamage = attackDamageVal;
}

Enemy::~Enemy() {
	name = "default";
	ability = "none";
	health = 0;
	attackDamage = 0;
}

std::string Enemy::getName() {
	return name;
}

std::string Enemy::getAbility() {
	return ability;
}

int Enemy::getHealth() {
	return health;
}

int Enemy::getAttackDamage() {
	return attackDamage;
}

void Enemy::setName(std::string nameVal) {
	name = nameVal;
}

void Enemy::setAbility(std::string abilityVal) {
	ability = abilityVal;
}

void Enemy::setHealth(int healthVal) {
	health = healthVal;
}

void Enemy::setAttackDamage(int attackDamageVal) {
	attackDamage = attackDamageVal;
}
