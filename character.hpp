/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: Declares the character class
***********************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "inventory.hpp"

class character
{
private:
	int health;
	int offense_sides;	
	int defense_sides;
	char id;
	inventory inv;
public:
	character();
	~character();
	int key_count();
	void print_inv();
	char get_id();
	void set_stats(int,int,int,char);
	int get_health();
	int get_off();
	int get_def();
	void set_health(int);
	void add_key();
};

#endif
