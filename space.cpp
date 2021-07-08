/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: defines space class
***********************/
#include "space.hpp"
#include "character.hpp"
#include <iostream>

space::space()
{
	space::up = nullptr;
	space::down = nullptr;
	space::left = nullptr;
	space::right = nullptr;
	space::position = nullptr;
}
void space::set_character(character *ptr)
{
	space::position = ptr;
}
character *space::get_character()
{
	return space::position;
}

space::~space()
{
	if(position != nullptr)
	{
		delete position;
	}
}

void space::print_space()
{
	if(space::position == nullptr)//default space is #
	{
		std::cout << "#";
	}
	if(space::position != nullptr)//character is *
	{
		std::cout <<position->get_id();
	}
	

}

int space::inspect()
{
	std::cout << "just a space. Move along" << std::endl;
}

space* space::get_up()
{
	return space::up;
}

space* space::get_down()
{
	return space::down;
}

space* space::get_left()
{
	return space::left;
}

space* space::get_right()
{
	return space::right;
}
void space::set_hor(space *left, space *right)
{
	left->set_right(right);
	right->set_left(left);
}
void space::set_ver(space *up, space *down)
{
	up->set_down(down);
	down->set_up(up);
}

void space::set_down(space *ptr)
{
	space::down = ptr;
}
void space::set_up(space *ptr)
{
	space::up = ptr;
}
void space::set_left(space *ptr)
{
	space::left = ptr;
}
void space::set_right(space *ptr)
{
	space::right = ptr;
}
