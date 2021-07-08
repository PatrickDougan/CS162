/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: defines key class
***********************/
#include "key.hpp"

key::key()
{
	key::next = nullptr;
	key::prev = nullptr;
}

key *key::getNext()
{
	return key::next;
}

key *key::getPrev()
{
	return key::prev;
}

void key::setNext(key* nex)
{
	key::next = nex;
}

void key::setPrev(key *pre)
{
	key::prev = pre;
}
