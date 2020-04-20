#ifndef __GAMEPLAY_H_
#define __GAMEPLAY_H_
#include "Characters.h"
#include <fstream>

class Gameplay: public Characters {
private:
	Characters player;
	Characters enemy;
	int playerOption{ -1 };
	int playerClass;
	int playerStage;
	std::string question_answer;

	// Save and Load process
	std::string text_line;
	std::ofstream save_file;


	int action_selection;
	int enemy_action_selection;

public:
	Gameplay();
	void playGame();
	void gameMenu();
	void saveTheGame();
	void loadTheGame();

	void stage_one();
	void stage_two();
	void boss_stage();
	// Player stage selection function
	void stage_selection();
	void character_selection();

	// Player or Enemy's action function
	void attack_char(Characters &attacker, Characters &defender);
	void defense_char(Characters &attacker, Characters &defender);
	void special_char(Characters &attacker, Characters &defender);
	void perry_char(Characters &attacker, Characters &defender);
	void enemy_special(Characters& enemy, Characters& player);

	// Trade shop function
	void buy_potion(Characters &player);
	void use_potion(Characters &player);

	// User Guide

};
#endif