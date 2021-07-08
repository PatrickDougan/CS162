/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: defines treasure class
***********************/
#include "treasure.hpp"
#include <iostream>

int treasure::inspect()
{
	if(treasure::position->key_count() >= 3)//checks if you have 3 keys
	{
		std::cout << "You've found the treasure and won!" << std::endl;//you win the game
		return 7;
	}
	else
	{
		std::cout << "You need to find more keys" << std::endl;
		return 0;
	}

}

treasure::treasure()
{

}

void treasure::print_space()
{
	std::cout << "O";
}
