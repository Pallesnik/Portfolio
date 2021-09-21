
#include "Library.h"

Library::Library(){
	LibName= "Default";
}

Library::Library(string l){
	LibName=l;
}

void Library::setLName(string l){
	LibName=l;
}

string Library::getLName(){return LibName;}

void Library::addGame(Game g1){
	if (myLibrary.size() <= maxNofGames) {
    	myLibrary.push_back(g1);
    } else {
    	cout<<"Library is full"<<endl;
    }
}




