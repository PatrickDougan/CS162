/***********************
*Program: Final
*Author: Patrick Dougan
*:Date 12/10/2019
*Description: declares key class
***********************/
#ifndef KEY_HPP
#define KEY_HPP

class key
{	
	key *next;
	key *prev;
public:
	key *getNext();
	key *getPrev();
	void setNext(key*);
	void setPrev(key*);
	key();		


};
#endif
