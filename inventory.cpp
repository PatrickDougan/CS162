/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: defines inventory class
***********************/
#include "key.hpp"
#include "inventory.hpp"


int inventory::count()//prints out number of keys in inventory
{
	int count = 0;
	key *temp = inventory::head;
	while(temp != nullptr)//loops through inventory to count number of keys
	{
		count += 1;
		temp = temp->getNext();
	}
	return count;
}

key *create()//creates a new key
{
	key *ptr = new key;
	return ptr;
}

inventory::inventory()
{
	inventory::head = nullptr;
}

inventory::~inventory()
{
	while(inventory::head != nullptr)
	{
		inventory::remove_head();
	}
}

void inventory::remove_head()//removes first key from inventory
{
	if(inventory::head == nullptr)
	{
		return;
	}
	key *ptrNext;
	ptrNext = inventory::head->getNext();
	delete inventory::head;
	inventory::head = ptrNext;
	if(inventory::head != nullptr)
	{
		inventory::head->setPrev(nullptr);
	}

}

void inventory::add_head()//adds key to head of inventory
{
	key *temp;
	temp = inventory::head;
	inventory::head = create();
	inventory::head->setNext(temp);
	if(temp != nullptr)//if not first key in inventory
	{
		temp->setPrev(inventory::head);//set previous pointer for prevous head
	}

}
