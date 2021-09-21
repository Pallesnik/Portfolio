#include "Developer.h"

Developer::Developer(){
	DevName="";
	games=0;
	salary=0;
}

Developer::Developer(string a){
	DevName=a;
	games=0;
	salary=0;
}

void Developer::setDeveloperName(string n){
     DevName = n;
     }

void Developer::setnofGamesReleased(int s){
     games = s;
     }

void Developer::setSalaryEarned(float se){
	int x=1;
	while(x==1){
	if (se>=0){
     salary = se;
     x=0;
	}
	else{
		cout << "Please enter a valid salray: ";
		cin >> se;
	}
	}
     }

string Developer::getDeveloperName(){return DevName;}
int Developer::getnofGamesReleased(){return games;}
float Developer::getSalaryEarned(){return salary;}

void Developer::DeveloperDisplay(){
	cout << DevName << " has produced " << games << " amount of games and has earned a total of "
			<< salary << " euro." << endl;
}

int Developer::calcSalary(){
    cout<<salary;
    return salary;
}




