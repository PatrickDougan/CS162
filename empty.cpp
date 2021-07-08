/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: defines empty space for empty class
***********************/
#include "empty.hpp"
#include <iostream>

int empty::inspect()
{
	if(empty::drop <= 0)
	{
		std::cout << "There's nothing here" << std::endl;
		return 0;
	}
	std::cout << "You've found a potion!" << std::endl;
	empty::position->set_health(empty::position->get_health() + 5);
	empty::drop -= 1;
	return 0;
}

empty::empty()
{
	empty::drop = 1;
}	
