/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: declares map class
***********************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include "character.hpp"

class space
{
private:
	space *up;
	space *down;
	space *left;
	space *right;
protected:	
	character *position;
	int drop;
public:
	space();
	~space();
	virtual int inspect();
	space *get_right();
	space *get_left();
	space *get_down();
	space *get_up();
	character *get_character();
	void set_up(space*);
	void set_down(space*);
	void set_left(space*);
	void set_right(space*);
	void set_hor(space*,space*);
	void set_ver(space*,space*);
	virtual void print_space();
	void set_character(character*);
};

#endif
