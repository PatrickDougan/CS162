/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: declare trap class
***********************/
#ifndef TRAP_HPP
#define TRAP_HPP

#include "space.hpp"

class trap : public space
{
public:
	int inspect();
	trap();
};

#endif
