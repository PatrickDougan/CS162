/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: Defines the pirate spaces
***********************/
#include "enemy.hpp"
#include <iostream>

enemy::enemy()
{
	enemy::position = new character;
	enemy::position->set_stats(5,2,100,'X');	
	enemy::drop = 1;
}


int enemy::inspect()
{
	if(enemy::drop <= 0)
	{
		std::cout << "There's nothing left here" << std::endl;	
		return 0;
	}
	std::cout << "Looks like the enemy dropped this" << std::endl;
	enemy::position->add_key();
	enemy::position->print_inv();
	drop -= 1;
	return 0;
}
