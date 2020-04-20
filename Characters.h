#ifndef __CHARACTERS_H_
#define __CHARACTERS_H_
#include <string>

class Characters {
public:
	std::string character_name;
	int strength;
	int health;
	int armor;
	int potion;
	int coin;
	int specialSkill;

	Characters();
	Characters(std::string name, int str, int hp, int amr);

};

#endif 
