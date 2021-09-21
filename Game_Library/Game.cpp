
#include "Game.h"
using namespace std;

Game::Game(){
	name="";
	genre="";
	duration=0;
}

Game::Game(string n){
	name = n;
	genre = "";
	duration = 0;
     }

void Game::setName(string n){
     name = n;
     }

void Game::setGenre(string g){
     genre = g;
     }

void Game::setDuration(int d){
     duration = d;
     }

void Game::setDeveloper(Developer d){
	dev1=d;
}

string Game::getName(){return name;}
string Game::getGenre(){return genre;}
int Game::getDuration(){return duration;}
Developer Game::getDeveloper(){return dev1;}

void Game::display(){
     cout << name << " is a " << genre << " game, is " << duration << " minutes long and was created by " << dev1.getDeveloperName() << "." << endl;
     }








