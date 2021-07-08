/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: declares space class
***********************/
#ifndef TREASURE_HPP
#define TREASURE_HPP

#include "space.hpp"

class treasure : public space
{
public:
	void print_space();
	treasure();
	int inspect();
};

#endif
