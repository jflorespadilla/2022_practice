#pragma once
#include <iostream>
#include <string>

class Enemy {
	public:
		Enemy();
		Enemy(const Enemy& createdEnemy);
		Enemy(std::string nameVal, std::string abilityVal, int healthVal, int attackDamageVal);
		~Enemy();
		
		std::string getName();
		std::string getAbility();
		int getHealth();
		int getAttackDamage();

		void setName(std::string nameVal);
		void setAbility(std::string abilityVal);
		void setHealth(int healthVal);
		void setAttackDamage(int attackDamageVal);

	private:
		std::string name;
		std::string ability;
		int health;
		int attackDamage;
};

