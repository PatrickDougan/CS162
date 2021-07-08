/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: declares pirate spaces
***********************/

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "space.hpp"

class enemy : public space
{
public:
	int inspect();
	enemy();
	int get_drop();
	void set_drop(int);


};

#endif
