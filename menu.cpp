/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: defines menus class
***********************/
#include "menu.hpp"
#include <iostream>

void checkInt(int &value,int min, int max);//gets integer value from user

void intro()//explains the game
{
	std::cout << "You exploring a cave that has hidden treasure!\nThere are pirates " <<
	"throughout the cave that have some keys to the treasure.\nDefeat them to get enough" <<
	" keys to unlock the treasure!\n* = you, X=Pirates, O=Treasure\nYou can interact " <<
	"with spaces. Some give health but some are booby trapped\n";
}

int replay()//checks if user wants to keep playing
{
	int choice = 0;
	std::cout << "Enter 1 to play again and 2 to exit:";
	checkInt(choice,1,2);
	return choice;
}

void options()//displays user input options
{
	std::cout <<"1=Left 2=Right 3=up 4=down\n5=inspect space 6=display inventory 7=exit"<< std::endl;
}

//validates input
void checkInt(int &value, int min, int max)//check user input
{
	while(value < min ||value > max)
	{
		while(!(std::cin>>value))
		{	
			std::cin.clear();
			std::cin.ignore(100,'\n');
			std::cout << "Please enter valid input" << std::endl;
		}	
	}
	std::cin.ignore(100,'\n');
}


