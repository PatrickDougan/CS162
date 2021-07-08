/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: defines roll for die class
***********************/

#include "die.hpp"
#include <stdlib.h>
#include <time.h>
#include <chrono>

int roll(int faces, int dieRolled)
{
	int sum = 0;//stores value of all rolls
	for(int x = 0; x < dieRolled; x++)
	{
		//rolls a die with x number of sides for y number of rolls
		srand(std::chrono::steady_clock::now().time_since_epoch().count());	//found on cpp reference
		//Needed to give random rolls
		sum += (rand() % faces + 1);
	}	
	return sum;//returns values total rolls
}


