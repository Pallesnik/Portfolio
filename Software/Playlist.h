#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"

class Playlist{
private:
	vector <Song> myPlaylist;
	string pName;


public:
	Playlist();
	Playlist(string pl);
	void addSong(Song);
	static const int maxNofSongs = 10;
	void setpName(string p);
	string getpName();
};



#endif /* PLAYLIST_H_ */
