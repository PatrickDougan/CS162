/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: declares inventory class
***********************/
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "key.hpp"

class inventory
{
private:
	key *head;
public:	
	inventory();
	~inventory();
	int count();
	void add_head();
	void remove_head();
};

#endif
