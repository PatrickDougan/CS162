/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: declares map class
***********************/
#ifndef MAP_HPP
#define MAP_HPP

#include "space.hpp"

class map
{
private:
	int steps;

public:
	map();
	~map();
	void move(int&);

	space *start;
	space *player;
	void print();
	
};
#endif
