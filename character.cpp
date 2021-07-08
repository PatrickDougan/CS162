/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: defines character class
***********************/
#include "character.hpp"
#include <iostream>

character::character()
{
	character::offense_sides = 10;
	character::defense_sides = 5;
	character::health = 100;
	character::id = '*';
}

character::~character()
{
}
int character::key_count()
{
	return character::inv.count();
}
void character::print_inv()
{
	std::cout << "Keys:" << character::inv.count() << std::endl;	
	std::cout << "Health:" << character::health << std::endl;
}

void character::add_key()//Adds key to inventory
{
	character::inv.add_head();
}

char character::get_id()//Gives the character to represent the player on the map
{
	return character::id;
}

int character::get_off()
{
	return character::offense_sides;
}	

int character::get_def()
{
	return character::defense_sides;
}

int character::get_health()
{
	return character::health;
}
void character::set_health(int hp)
{
	character::health = hp;
}

void character::set_stats(int str, int def, int hp, char sign)//sets character stats
{
	character::offense_sides = str;
	character::defense_sides = def;
	character::health = hp;
	character::id = sign;
}
