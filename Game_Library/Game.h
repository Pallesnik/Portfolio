
#ifndef GAME_H_
#define GAME_H_

#include "Developer.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Game{
	private:
		string name;
		string genre;
		int duration;
		Developer dev1;

	public:
		Game();
		Game(string n);
		void setName(string n);
		void setGenre(string g);
		void setDuration(int d);
		void setDeveloper(Developer d1);
		string getName();
		string getGenre();
		int getDuration();
		Developer getDeveloper();
		void display();

};

#endif



