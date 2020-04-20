#include "Gameplay.h"
#include "Characters.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>


Gameplay::Gameplay()
{
}

void Gameplay::playGame()
{
	
	std::cout << "Year 2020.. There was a place called 'Demacia'." << std::endl;
	Sleep(2000);
	std::cout << "It was a beautiful place with peace and wealth, and every citizens in Demacia were happy." << std::endl;
	Sleep(2000);
	std::cout << "But the peaceful time has gone because of the pirates of Bilgewaters.." << std::endl;
	Sleep(2000);
	std::cout << "Gangplank, the Captain of the Bilgewater invade the Demacia with two beast creatures..!" << std::endl;
	Sleep(2000);
	std::cout << "Defeat the beasts and Gangplank and save the Demacia!!" << std::endl;
	Sleep(3000);
	std::cout << "********************Welcome to Fantasy Fight Game********************" << std::endl;
	//Sleep(3000);
	std::cout << "Please select the options below.." << std::endl;
	//Sleep(1500);
	

	gameMenu();

}

void Gameplay::gameMenu()
{
	printf("1. New Game");
	printf("\n");
	printf("2. Load the Game");
	printf("\n");
	printf("3. Exit");
	printf("\n");

	std::cin >> playerOption;
	system("cls");
	switch (playerOption) {
	case 1:
		stage_one();
		break;
	case 2:
		loadTheGame();
		break;
	case 3:
		std::cout << "Thank you for playing Fantasy Fight Game!" << std::endl;
		break;
	}
}

void Gameplay::saveTheGame()
{
	save_file.open("FFsave.txt");
	save_file << playerStage;
	save_file.close();
}

void Gameplay::loadTheGame()
{
	std::ifstream load_file("FFsave.txt");
	if (load_file.is_open()) {
		while (getline(load_file, text_line)) {
			if (text_line == "1") {
				stage_one();
			}
			else if (text_line == "2") {
				stage_two();
			}
			else if (text_line == "3") {
				boss_stage();
			}
			else if (text_line == "") {
				std::cout << "You don't have a saved file" << std::endl;
			}
			else {
				std::cout << "You don't have a saved data" << std::endl;
			}
		}
	}
}

void Gameplay::stage_one()
{
	playerStage = 1;
	stage_selection();
	saveTheGame();

	std::cout << "Welcome! My hero! I heard you are here to fight against the beasts!" << std::endl;
	//Sleep(3000);
	std::cout << "Before you go out to fight against beast, please select your class!" << std::endl;
	//Sleep(3000);
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "1. Warrior" << std::endl;
	std::cout << "2. Mage" << std::endl;
	std::cout << "3. Gunaman" << std::endl;
	std::cin >> playerClass;

	character_selection();
	system("cls");

	std::cout << "Alright! You have choosed.. " << player.character_name << " class!" << std::endl;
	std::cout << "Do you need potions before fight?" << std::endl;
	std::cout << "Y/N" << std::endl;
	std::cin >> question_answer;
	if (question_answer == "y") {
		buy_potion(player);
		Sleep(3000);
	}
	else if (question_answer == "n") {
		std::cout << "Alright.. be ready for the fight..!" << std::endl;
		Sleep(3000);
	}
	system("cls");
	std::cout << "Gangplank lives inside the ship that is settled on the shore..!" << std::endl;
	Sleep(3000);
	std::cout << "Please defeat him and find a peace for Demacia!" << std::endl;
	Sleep(3000);
	system("cls");
	std::cout << "..." << std::endl;
	Sleep(3000);
	system("cls");

	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "|              In The Ship of Bilgewater...            |" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "You have faced Tahm Kench...!" << std::endl;
	std::cout << "Tahm Kench is slow, but has a hard skin..!" << std::endl;
	

	while (true) {
		std::cout << "What move are you going to make?" << std::endl;
		std::cout << "1. Attack" << std::endl;
		std::cout << "2. Defense" << std::endl;
		std::cout << "3. Perry" << std::endl;
		std::cout << "4. Special Skill (One time only..!)" << std::endl;
		std::cout << "5. Use Potion" << std::endl;
		printf("\n");

		srand(time(NULL));
		enemy_action_selection = rand() % 3 + 1;
		std::cin >> action_selection;
		printf("---------------------------------------------------");
		printf("\n");
		if (action_selection == 1 && enemy_action_selection == 1){
			attack_char(player, enemy);
			attack_char(enemy, player);
		}
		else if (action_selection == 1 && enemy_action_selection == 2) {
			defense_char(player, enemy);
		}
		else if (action_selection == 1 && enemy_action_selection == 3) {
			attack_char(player, enemy);
			enemy_special(enemy, player);
		}
		else if (action_selection == 2 && enemy_action_selection == 1) {
			defense_char(enemy, player);
		}
		else if (action_selection == 2 && enemy_action_selection == 2) {
			std::cout << "Both are in Defense Position!" << std::endl;
		}
		else if (action_selection == 2 && enemy_action_selection == 2) {
			std::cout << "Cannot Block " << enemy.character_name << "'s special skill..!" << std::endl;
			Sleep(3000);
			enemy_special(enemy, player);
			Sleep(3000);
		}
		else if (action_selection == 3 && enemy_action_selection == 1) {
			perry_char(enemy, player);
		}
		else if (action_selection == 3 && enemy_action_selection == 2) {
			std::cout << "Both are in Defense Position!" << std::endl;
		}
		else if (action_selection == 3 && enemy_action_selection == 3) {
			perry_char(enemy, player);
		}
		else if (action_selection == 4 && enemy_action_selection == 1) {
			std::cout << player.character_name << " is using special skill!" << std::endl;
			Sleep(3000);
			std::cout << "Enemy cannot block this skill..!" << std::endl;
			Sleep(3000);
			if (player.specialSkill == 0) {
				std::cout << "You already used your special skill..!" << std::endl;
				continue;
			}
			special_char(player, enemy);
		}
		else if (action_selection == 4 && enemy_action_selection == 2) {
			std::cout << player.character_name << " is using special skill!" << std::endl;
			Sleep(3000);
			std::cout << "Enemy cannot block this skill..!" << std::endl;
			Sleep(3000);
			if (player.specialSkill == 0) {
				std::cout << "You already used your special skill..!" << std::endl;
				continue;
			}
			special_char(player, enemy);
		}
		else if (action_selection == 4 && enemy_action_selection == 3) {
			std::cout << player.character_name << " is using special skill!" << std::endl;
			Sleep(2000);
			std::cout << "Enemy cannot block this skill..!" << std::endl;
			Sleep(2000);
			if (player.specialSkill == 0) {
				std::cout << "You already used your special skill..!" << std::endl;
				continue;
			}
			special_char(player, enemy);
		}
		else if (action_selection == 5) {
			use_potion(player);
		}
		printf("\n");
		Sleep(3000);
		system("cls");
		if (enemy.health == 0 || enemy.health < 0) {
			std::cout << "Congratulation! You defeated " << enemy.character_name << "!!" << std::endl;
			break;
		}
		if (player.health == 0 || player.health < 0) {
			std::cout << "You lost the fight..! Please try again..! " << std::endl;
			Sleep(3000);
			gameMenu();
		}
	}
	std::cout << "Stage one clear!" << std::endl;
	std::cout << "You have gained 25 gold!" << std::endl;
	player.coin += 25;
	player.specialSkill += 1;
	character_selection();
	Sleep(3000);
	system("cls");

	stage_two();
}

void Gameplay::stage_two()
{
	playerStage = 2;
	stage_selection();
	saveTheGame();

	std::cout << "You have defeated Tahm Kench!! But.. There's stronger enemy called Pyke.." << std::endl;
	Sleep(3000);
	std::cout << "Pyke has higher damage than Tahm Kench..! So, becareful Hero!" << std::endl;
	Sleep(3000);

	system("cls");
	std::cout << "Do you need potions before fight?" << std::endl;
	std::cout << "Y/N" << std::endl;
	std::cin >> question_answer;
	if (question_answer == "y") {
		buy_potion(player);
		Sleep(3000);
	}
	else if (question_answer == "n") {
		std::cout << "Alright.. be ready for the fight..!" << std::endl;
		Sleep(3000);
		system("cls");
	}


	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "|              In The Ship of Bilgewater...            |" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "You have faced Pyke...!" << std::endl;
	std::cout << "Pyke has high damage and fast speed..!" << std::endl;


	while (true) {

		std::cout << "What move are you going to make?" << std::endl;
		std::cout << "1. Attack" << std::endl;
		std::cout << "2. Defense" << std::endl;
		std::cout << "3. Perry" << std::endl;
		std::cout << "4. Special Skill (One time only..!)" << std::endl;
		std::cout << "5. Use Potion" << std::endl;
		printf("\n");

		srand(time(NULL));
		enemy_action_selection = rand() % 3 + 1;
		std::cin >> action_selection;
		printf("---------------------------------------------------");
		printf("\n");
		if (action_selection == 1 && enemy_action_selection == 1) {
			attack_char(player, enemy);
			attack_char(enemy, player);
		}
		else if (action_selection == 1 && enemy_action_selection == 2) {
			defense_char(player, enemy);
		}
		else if (action_selection == 1 && enemy_action_selection == 3) {
			attack_char(player, enemy);
			enemy_special(enemy, player);
		}
		else if (action_selection == 2 && enemy_action_selection == 1) {
			defense_char(enemy, player);
		}
		else if (action_selection == 2 && enemy_action_selection == 2) {
			std::cout << "Both are in Defense Position!" << std::endl;
		}
		else if (action_selection == 2 && enemy_action_selection == 2) {
			std::cout << "Cannot Block " << enemy.character_name << "'s special skill..!" << std::endl;
			Sleep(2000);
			enemy_special(enemy, player);
			Sleep(2000);
		}
		else if (action_selection == 3 && enemy_action_selection == 1) {
			perry_char(enemy, player);
		}
		else if (action_selection == 3 && enemy_action_selection == 2) {
			std::cout << "Both are in Defense Position!" << std::endl;
		}
		else if (action_selection == 3 && enemy_action_selection == 3) {
			perry_char(enemy, player);
		}
		else if (action_selection == 4 && enemy_action_selection == 1) {
			std::cout << player.character_name << " is using special skill!" << std::endl;
			Sleep(2000);
			std::cout << "Enemy cannot block this skill..!" << std::endl;
			Sleep(2000);
			if (player.specialSkill == 0) {
				std::cout << "You already used your special skill..!" << std::endl;
				continue;
			}
			special_char(player, enemy);
		}
		else if (action_selection == 4 && enemy_action_selection == 2) {
			std::cout << player.character_name << " is using special skill!" << std::endl;
			Sleep(2000);
			std::cout << "Enemy cannot block this skill..!" << std::endl;
			Sleep(2000);
			if (player.specialSkill == 0) {
				std::cout << "You already used your special skill..!" << std::endl;
				continue;
			}
			special_char(player, enemy);
		}
		else if (action_selection == 4 && enemy_action_selection == 3) {
			std::cout << player.character_name << " is using special skill!" << std::endl;
			Sleep(2000);
			std::cout << "Enemy cannot block this skill..!" << std::endl;
			Sleep(2000);
			if (player.specialSkill == 0) {
				std::cout << "You already used your special skill..!" << std::endl;
				continue;
			}
			special_char(player, enemy);
		}
		else if (action_selection == 5) {
			use_potion(player);
		}
		printf("\n");
		Sleep(3000);
		system("cls");
		if (enemy.health == 0 || enemy.health < 0) {
			std::cout << "Congratulation! You defeated " << enemy.character_name << "!!" << std::endl;
			break;
		}
		if (player.health == 0 || player.health < 0) {
			std::cout << "You lost the fight..! Please try again..! " << std::endl;
			Sleep(3000);
			gameMenu();
		}
	}
	std::cout << "Stage two clear!" << std::endl;
	std::cout << "You have gained 25 gold!" << std::endl;
	player.coin += 25;
	player.specialSkill += 1;
	character_selection();
	Sleep(3000);
	system("cls");
	boss_stage();
}

void Gameplay::boss_stage()
{
	playerStage = 3;
	stage_selection();
	saveTheGame();

	std::cout << "You have defeated Pyke!! You are almost there...!" << std::endl;
	Sleep(2000);
	std::cout << "Finally, you come to the center of the Bilgewater ship.." << std::endl;
	Sleep(2000);

	system("cls");
	std::cout << "Do you need potions before fight?" << std::endl;
	std::cout << "Y/N" << std::endl;
	std::cin >> question_answer;
	if (question_answer == "y") {
		buy_potion(player);
		Sleep(2000);
	}
	else if (question_answer == "n") {
		std::cout << "Alright.. be ready for the fight..!" << std::endl;
		Sleep(2000);
		system("cls");
	}


	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "|              In The Room of Gangplank            |" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "You have faced Gangplank...!" << std::endl;
	std::cout << "He is stronger than any creatures..!" << std::endl;
	std::cout << "He is really hard to defeat..! so, be careful!" << std::endl;
	Sleep(2000);


	while (true) {

		std::cout << "What move are you going to make?" << std::endl;
		std::cout << "1. Attack" << std::endl;
		std::cout << "2. Defense" << std::endl;
		std::cout << "3. Perry" << std::endl;
		std::cout << "4. Special Skill (One time only..!)" << std::endl;
		std::cout << "5. Use Potion" << std::endl;
		printf("\n");

		srand(time(NULL));
		enemy_action_selection = rand() % 3 + 1;
		std::cin >> action_selection;
		printf("---------------------------------------------------");
		printf("\n");
		if (action_selection == 1 && enemy_action_selection == 1) {
			attack_char(player, enemy);
			attack_char(enemy, player);
		}
		else if (action_selection == 1 && enemy_action_selection == 2) {
			defense_char(player, enemy);
		}
		else if (action_selection == 1 && enemy_action_selection == 3) {
			attack_char(player, enemy);
			enemy_special(enemy, player);
		}
		else if (action_selection == 2 && enemy_action_selection == 1) {
			defense_char(enemy, player);
		}
		else if (action_selection == 2 && enemy_action_selection == 2) {
			std::cout << "Both are in Defense Position!" << std::endl;
		}
		else if (action_selection == 2 && enemy_action_selection == 2) {
			std::cout << "Cannot Block " << enemy.character_name << "'s special skill..!" << std::endl;
			Sleep(2000);
			enemy_special(enemy, player);
			Sleep(2000);
		}
		else if (action_selection == 3 && enemy_action_selection == 1) {
			perry_char(enemy, player);
		}
		else if (action_selection == 3 && enemy_action_selection == 2) {
			std::cout << "Both are in Defense Position!" << std::endl;
		}
		else if (action_selection == 3 && enemy_action_selection == 3) {
			perry_char(enemy, player);
		}
		else if (action_selection == 4 && enemy_action_selection == 1) {
			std::cout << player.character_name << " is using special skill!" << std::endl;
			Sleep(2000);
			std::cout << "Enemy cannot block this skill..!" << std::endl;
			Sleep(2000);
			if (player.specialSkill == 0) {
				std::cout << "You already used your special skill..!" << std::endl;
				continue;
			}
			special_char(player, enemy);
		}
		else if (action_selection == 4 && enemy_action_selection == 2) {
			std::cout << player.character_name << " is using special skill!" << std::endl;
			Sleep(2000);
			std::cout << "Enemy cannot block this skill..!" << std::endl;
			Sleep(2000);
			if (player.specialSkill == 0) {
				std::cout << "You already used your special skill..!" << std::endl;
				continue;
			}
			special_char(player, enemy);
		}
		else if (action_selection == 4 && enemy_action_selection == 3) {
			std::cout << player.character_name << " is using special skill!" << std::endl;
			Sleep(2000);
			std::cout << "Enemy cannot block this skill..!" << std::endl;
			Sleep(2000);
			if (player.specialSkill == 0) {
				std::cout << "You already used your special skill..!" << std::endl;
				continue;
			}
			special_char(player, enemy);
		}
		else if (action_selection == 5) {
			use_potion(player);
		}
		printf("\n");
		Sleep(3000);
		system("cls");
		if (enemy.health == 0 || enemy.health < 0) {
			std::cout << "Congratulation! You defeated " << enemy.character_name << "!!" << std::endl;
			break;
		}
		if (player.health == 0 || player.health < 0) {
			std::cout << "You lost the fight..! Please try again..! " << std::endl;
			Sleep(2000);
			gameMenu();
		}
	}
	system("cls");
	std::cout << "You saved Demacia from the pirates of Bilgewater!!!" << std::endl;
	std::cout << "Awesome! This is end of the game!" << std::endl;
	Sleep(3000);
	playerStage = 0;
	gameMenu();
}

void Gameplay::stage_selection()
{
	switch (playerStage) {
	case 1:
		enemy.character_name = "Tahm";
		enemy.strength = 5;
		enemy.armor = 20;
		enemy.health = 50;
		break;
	case 2:
		enemy.character_name = "Pyke";
		enemy.strength = 7;
		enemy.armor = 10;
		enemy.health = 40;
		break;
	case 3:
		enemy.character_name = "Gangplank";
		enemy.strength = 10;
		enemy.armor = 20;
		enemy.health = 50;
		break;
	}
}

void Gameplay::character_selection()
{
	switch (playerClass) {
	case 1:
		player.character_name = "Warrior";
		player.strength = 5;
		player.health = 50;
		player.armor = 10;
		break;
	case 2:
		player.character_name = "Mage";
		player.strength = 10;
		player.health = 25;
		player.armor = 10;
		break;
	case 3:
		player.character_name = "Gunman";
		player.strength = 7;
		player.health = 25;
		player.armor = 25;
		break;
	}
}

void Gameplay::attack_char(Characters &attacker, Characters &defender)
{
	std::cout << attacker.character_name << " attacked " << defender.character_name << "!" << std::endl;
	defender.health = defender.health - attacker.strength;
	std::cout << defender.character_name << "'s Hp:" << defender.health << std::endl;
	std::cout << defender.character_name << "'s Armor:" << defender.armor << std::endl;
	printf("\n");
}

void Gameplay::defense_char(Characters &attacker, Characters &defender)
{
	if ((defender.armor - attacker.strength) > 0) {
		std::cout << defender.character_name << " blocked " << attacker.character_name << "'s attack!" << std::endl;
		defender.armor -= attacker.strength;
		std::cout << defender.character_name << "'s Hp:" << defender.health << std::endl;
		std::cout << defender.character_name << "'s Armor:" << defender.armor << std::endl;
		printf("\n");
	}
	else if ((defender.armor - attacker.strength) <= 0) {
		int penetrated_damage = attacker.strength - defender.armor;
		defender.armor = 0;
		defender.health -= penetrated_damage;
		std::cout << defender.character_name << " blocked " << attacker.character_name << "'s attack!" << std::endl;
		std::cout << "But " << defender.character_name << " doesn't have armor, so the damage penetrates!" << std::endl;
		std::cout << defender.character_name << "'s Hp:" << defender.health << std::endl;
		std::cout << defender.character_name << "'s Armor:" << defender.armor << std::endl;
		printf("\n");
	}
	
}

void Gameplay::special_char(Characters &attacker, Characters &defender)
{
	std::cout << attacker.character_name << " used special skill..!" << std::endl;
	if (playerClass == 1) {
		std::cout << "Flame sword!" << std::endl;
		defender.health -= 10;
		attacker.specialSkill -= 1;
	}
	else if (playerClass == 2) {
		std::cout << "Thunderbolt!" << std::endl;
		defender.health -= 25;
		attacker.specialSkill -= 1;
	}
	else if (playerClass == 3) {
		std::cout << "Piercing Bullet!" << std::endl;
		defender.health -= 20;
		attacker.specialSkill -= 1;
	}
	std::cout << defender.character_name << "'s Hp:" << defender.health << std::endl;
	std::cout << defender.character_name << "'s Armor:" << defender.armor << std::endl;
}

void Gameplay::perry_char(Characters &attacker, Characters &defender)
{
	std::cout << defender.character_name << " avoid " << attacker.character_name << "'s attack!" << std::endl;
	std::cout << defender.character_name << "'s Hp:" << defender.health << std::endl;
	std::cout << defender.character_name << "'s Armor:" << defender.armor << std::endl;
}

void Gameplay::enemy_special(Characters& enemy, Characters& player)
{
	std::cout << enemy.character_name << " used special skill..!" << std::endl;
	if (playerStage == 1) {
		std::cout << "Eternal Swamp!" << std::endl;
		player.health -= 5;
	}
	else if (playerStage == 2) {
		std::cout << "Death Grab!" << std::endl;
		player.health -= 7;
	}
	else if (playerStage == 3) {
		std::cout << "Bullet Rain!" << std::endl;
		player.health -= 10;
	}
	std::cout << player.character_name << "'s Hp:" << player.health << std::endl;
	std::cout << player.character_name << "'s Armor:" << player.armor << std::endl;
}


void Gameplay::buy_potion(Characters &player)
{
	if (player.coin > 0) {
		std::cout << "Thank you for purchase!" << std::endl;
		player.potion += 1;
		player.coin -= 25;
	}
	else {
		std::cout << "You don't have enough money!" << std::endl;
	}
}

void Gameplay::use_potion(Characters &player)
{
	if (player.potion > 0) {
		player.potion -= 1;
		player.health += 15;
		std::cout << player.character_name << " recovered 15 hp!" << std::endl;
		std::cout << player.character_name << "'s HP: " << player.health << std::endl;
	}
	else {
		std::cout << "You don't have potion..!" << std::endl;
	}
}

