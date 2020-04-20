#include "Characters.h"
#include <iostream>

Characters::Characters()
{
	character_name = "None";
	strength = 0;
	health = 0;
	armor = 0;
	potion = 0;
	coin = 50;
	specialSkill = 1;
}

Characters::Characters(std::string name, int str, int hp, int amr)
{
	character_name = name;
	strength = str;
	health = hp;
	armor = amr;
	potion = 0;
	coin = 50;
	specialSkill = 1;
}


