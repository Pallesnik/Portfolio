
#include "Playlist.h"

Playlist::Playlist(){
	pName= "Default";
}

Playlist::Playlist(string pl){
	pName=pl;
}

void Playlist::setpName(string p){
	pName=p;
}

string Playlist::getpName(){return pName;}

void Playlist::addSong(Song s1){
	if (myPlaylist.size() <= maxNofSongs) {
    	myPlaylist.push_back(s1);
    } else {
    	cout<<"Playlist is full"<<endl;
    }
}



