
#ifndef SONG_H_
#define SONG_H_

#include "Artist.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Song{
	private:
		string name;
		string genre;
		int duration;
		Artist art1;

	public:
		Song();
		Song(string n);
		void setName(string n);
		void setGenre(string g);
		void setDuration(int d);
		void setArtist(Artist a1);
		string getName();
		string getGenre();
		int getDuration();
		Artist getArtist();
		void display();

};

#endif /* SONG_H_ */


