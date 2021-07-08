/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: Main function
***********************/

#include <iostream>
#include "space.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "trap.hpp"
#include "key.hpp"
#include "inventory.hpp"
#include "character.hpp"

using std::cout;
using std::endl;

int main()
{
	map x;
	int y = 0;
	intro();//explains the game
	while( y != 7)
	{
		x.print();//displays map
		options();//displays player options
		y = 0;	
		checkInt(y,1,7);//checks user input_iterator
		x.move(y);//moves character
	}
	return 0;
}
