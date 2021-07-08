#Author: Patrick Dougan
#Program: Final
#Date: 12/10/2019
#Description: makes the output file. and clears object names

output: main.o menu.o space.o empty.o map.o character.o trap.o die.o enemy.o treasure.o key.o inventory.o
	g++ -std=c++0x main.o menu.o space.o empty.o map.o character.o trap.o die.o enemy.o treasure.o key.o inventory.o -g -o output
main.o: main.cpp
	g++ -std=c++0x main.cpp -c -g
space.o: space.cpp
	g++ -std=c++0x space.cpp -c -g
empty.o: empty.cpp
	g++ -std=c++0x empty.cpp -c -g
enemy.o: enemy.cpp
	g++ -std=c++0x enemy.cpp -c -g
map.o: map.cpp
	g++ -std=c++0x map.cpp -c -g
character.o: character.cpp
	g++ -std=c++0x character.cpp -c -g
treasure.o: treasure.cpp
	g++ -std=c++0x treasure.cpp -c -g
trap.o: trap.cpp
	g++ -std=c++0x trap.cpp -c -g
menu.o: menu.cpp
	g++ -std=c++0x menu.cpp -c -g
die.o: die.cpp
	g++ -std=c++0x die.cpp -c -g
key.o: key.cpp
	g++ -std=c++0x key.cpp -c -g
inventory.o: inventory.cpp
	g++ -std=c++0x inventory.cpp -c -g
clear:
	rm *.o output

