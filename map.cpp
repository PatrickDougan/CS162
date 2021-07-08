/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: defines map class
***********************/
#include "map.hpp"
#include "space.hpp"
#include "empty.hpp"
#include "character.hpp"
#include "trap.hpp"
#include "enemy.hpp"
#include "die.hpp"
#include "treasure.hpp"

#include <iostream>

space *locate(space*);//used for randomizing spaces on the map


void fight(character *hero, character *villain)//Runs through the fight when character steps on a pirate space
{
	int att_roll, def_roll;
	while(hero->get_health() > 0 && villain->get_health() > 0)//while neither has lost
	{
		att_roll = roll(hero->get_off(),1);
		def_roll = roll(villain->get_def(),1);
		std::cout << "Hero attacks for:" << att_roll << std::endl;
		std::cout << "Pirate defends:" << def_roll << std::endl;
		if(def_roll > att_roll)//Stops player from healing from over defense
		{
			def_roll = att_roll;
		}
		std::cout << "Pirate health:" << (villain->get_health() - att_roll + def_roll)<<std::endl;		
		villain->set_health(villain->get_health() - att_roll + def_roll);//sets new pirate health
		if(villain->get_health() < 0)//stops the fight if pirate lost
		{
			delete villain;//frees heap
			break;
		}
		att_roll = roll(villain->get_off(),1);
		def_roll = roll(hero->get_def(),1);
		std::cout << "Pirate attacks for:" << att_roll << std::endl;
		std::cout << "Hero defends:" << def_roll << std::endl;
		if(def_roll > att_roll)//Stops overhealing
		{
			def_roll = att_roll;
		}
		std::cout << "Hero health:" << (hero->get_health() - att_roll + def_roll)<< std::endl;
		hero->set_health(hero->get_health() - att_roll + def_roll);
	}
			
}


void swap(space *new_space, space *removed)//Used for adding trap, enemy, and treasure spaces
{
	//Each checks if original space holds a pointer and sets new space to point to the same for each direction
	if(removed->get_up() != nullptr)
	{
		removed->get_up()->set_down(new_space);
		new_space->set_up(removed->get_up());
	}
	if(removed->get_left() != nullptr)
	{
		removed->get_left()->set_right(new_space);
		new_space->set_left(removed->get_left());
	}
	if(removed->get_right() != nullptr)
	{
		removed->get_right()->set_left(new_space);
		new_space->set_right(removed->get_right());
	}
	if(removed->get_down() != nullptr)
	{
		removed->get_down()->set_up(new_space);
		new_space->set_down(removed->get_down());
	}
	delete removed;//deletes removed space
}

void map::print()
{
	space *ptr = map::start;
	for(int x = 0; x < 5; x++)//loops through each row
	{	
		for(int y = 0; y < 5; y++)//loops through each column
		{
			ptr->print_space();
			if(ptr->get_right() != nullptr)
			{	
				ptr = ptr->get_right();//gets next column
			}	
		}
		std::cout << std::endl;	
		ptr = ptr->get_left()->get_left()->get_left()->get_left()->get_down();
		//sets pointer to the next row first column
	}
}

void map::move(int &dir)//Moves character around map
{
	if(map::player->get_character()->get_health() <= 0)
	{
		std::cout << "You've died" << std::endl;
		dir = 7;
	}
	map::steps -= 1;//Step counter limit
	if(map::steps <= 0)
	{
		dir = 7;
	}
	switch (dir)
	{
		case 1://Player moves left
			if(map::player->get_left() == nullptr)//Checks if valid space
			{
				break;//Exits if it is not
			}
			if(map::player->get_left()->get_character() != nullptr)//if space occupied by enemy
			{
				fight(map::player->get_character(), map::player->get_left()->get_character());//fights
			}
			map::player->get_left()->set_character(map::player->get_character());//moves player to space
			map::player->set_character(nullptr);//clears player from previous space
			map::player = map::player->get_left();//sets map value to character
			break;
		case 2://Same flow as case 1 for Right
			if(map::player->get_right() == nullptr)
			{
				break;
			}
			if(map::player->get_right()->get_character() != nullptr)
			{
				fight(map::player->get_character(), map::player->get_right()->get_character());
			}
			map::player->get_right()->set_character(map::player->get_character());
			map::player->set_character(nullptr);
			map::player = map::player->get_right();
			break;			 
		case 3://Same flow as case 1 for Up
			if(map::player->get_up() == nullptr)
			{
				break;
			}
			if(map::player->get_up()->get_character() != nullptr)
			{
				fight(map::player->get_character(), map::player->get_up()->get_character());
			}
			map::player->get_up()->set_character(map::player->get_character());
			map::player->set_character(nullptr);
			map::player = map::player->get_up();
			break;

		case 4://Same flow as case 1 for Down
			if(map::player->get_down() == nullptr)
			{
				break;
			}
			if(map::player->get_down()->get_character() != nullptr)
			{
				fight(map::player->get_character(), map::player->get_down()->get_character());
			}
			map::player->get_down()->set_character(map::player->get_character());
			map::player->set_character(nullptr);
			map::player = map::player->get_down();
			break;
		case 5:
			dir = map::player->inspect();//inspects space
			break;
		case 6:
			map::steps += 1;//doesn't count against counter since no movement
			map::player->get_character()->print_inv();//Displays inventory
			std::cout << "steps remaining:" << map::steps << std::endl;
			break;	
	}
}

map::map()
{
	map::steps = 30;//sets step limit to 30
	space *temp_ver = nullptr;
	space *temp_hor = nullptr;
	space *ptr = nullptr;
	for(int x = 0; x < 5; x++)//sets each row
	{
		for(int y = 0; y < 5; y++)//for each column
		{
			ptr = new empty;//create space
			ptr->set_left(temp_hor);//points it to space to it's left
			ptr->set_up(temp_ver);//points it to space above
			if(temp_hor != nullptr)//if left space isn't empty
			{
				temp_hor->set_right(ptr);//point left space's right pointer to new space
			}
			if(temp_ver != nullptr)//if above space isn't empty
			{
				temp_ver->set_down(ptr);//sets space below pointer
				temp_ver = temp_ver->get_right();//move above pointer to the right
			}
			temp_hor = ptr;
			if(ptr->get_up() == nullptr && ptr->get_left() == nullptr)//sets map head value for first tile
			{
				map::start = ptr;
			}		
		}	
		//moves pointer over to first column of just completed row
		temp_ver = temp_hor->get_left()->get_left()->get_left()->get_left();
		temp_hor = nullptr;//sets new left off map
	}
	map::player = map::start;//starts player at first space
	map::player->set_character(new character);//add character
	for(int x = 0; x < 8; x++)//randomly sets trap spaces
	{
		swap(new trap, locate(map::start));
	}
	for(int x = 0; x < 4; x++)//randomly sets pirate locations
	{
		swap(new enemy,locate(map::start));
	}
	//sets treasure to bottom right of map
	swap(new treasure, map::start->get_down()->get_down()->get_down()->get_right()->get_right()->get_right()->get_down()->get_right());
}

map::~map()//removes all spaces
{
	space *temp;
	space *ptr = map::start->get_right()->get_right()->get_right()->get_right();
	ptr = ptr->get_down()->get_down()->get_down()->get_down();
	for(int x = 0; x < 5; x++)
	{
		for(int y =0; y < 5; y++)
		{
			if(ptr->get_left() != nullptr)
			{
				temp = ptr->get_left();
			}
			else if(ptr->get_up() != nullptr)
			{
				temp = ptr->get_up()->get_right()->get_right()->get_right()->get_right();	
			}
			else
			{
				temp = nullptr;
			}
			
			delete ptr;
			ptr = temp;
			
		}
	}

}

space *locate(space *start)//randomly returns locatoin of space to swap
{
	space *ptr = start;
	int x = 1, y = 1;
	
	while((x == 1 && y == 1) || (x == 5 && y == 5))//stops from returning start or treasure locations
	{
		x = roll(5,1);//chooses x coordinate
		y = roll(5,1);//chooses y coordinate
	}
	while((x-1) != 0)//loops to correct x coordinate
	{
		ptr = ptr->get_right();
		x -= 1;
	}
	while((y-1) != 0)//loops to correct y coordinate starting from correct x coordinate
	{
		ptr = ptr->get_down();
		y -= 1;
	}
	return ptr;
}

