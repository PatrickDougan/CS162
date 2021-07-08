/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: declares the empty class
***********************/
#ifndef EMPTY_HPP
#define EMPTY_HPP

#include "space.hpp"

class empty : public space
{
public:
	empty();
	int inspect();
};
#endif
