/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: defines trap class
***********************/
#include "trap.hpp"
#include <iostream>

int trap::inspect()//if trap is inspected it damages the character
{
	if(trap::drop <= 0)
	{
		std::cout << "You're not falling for that again!" << std::endl;
		return 0;
	}
	std::cout << "You've fallen into a trap" << std::endl;
	trap::position->set_health(trap::position->get_health()-25);
	trap::drop -= 1;//trap cannot be fallen into again
	return 0;
}

trap::trap()
{
	trap::drop = 1;
}
