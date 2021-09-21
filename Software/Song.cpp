
#include "Song.h"
using namespace std;

Song::Song(){
	name="";
	genre="";
	duration=0;
}

Song::Song(string n){
	name = n;
	genre = "";
	duration = 0;
     }

void Song::setName(string n){
     name = n;
     }

void Song::setGenre(string g){
     genre = g;
     }

void Song::setDuration(int d){
     duration = d;
     }

void Song::setArtist(Artist a){
	art1=a;
}

string Song::getName(){return name;}
string Song::getGenre(){return genre;}
int Song::getDuration(){return duration;}
Artist Song::getArtist(){return art1;}

void Song::display(){
     cout << name << " is a " << genre << " song, is " << duration << " minutes long and is performed by " << art1.getartistName() << "." << endl;
     }







