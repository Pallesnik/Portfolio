#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "Game.h"

class Library{
private:
	vector <Game> myLibrary;
	string LibName;


public:
	Library();
	Library(string l);
	void addGame(Game);
	static const int maxNofGames = 10;
	void setLName(string p);
	string getLName();
};



#endif

