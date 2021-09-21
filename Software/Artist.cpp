#include "Artist.h"

Artist::Artist(){
	aName="";
	singles=0;
	salary=0;
}

Artist::Artist(string a){
	aName=a;
	singles=0;
	salary=0;
}

void Artist::setartistName(string n){
     aName = n;
     }

void Artist::setnofSinglesReleased(int s){
     singles = s;
     }

void Artist::setsalaryEarned(float se){
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

string Artist::getartistName(){return aName;}
int Artist::getnofSinglesReleased(){return singles;}
float Artist::getsalaryEarned(){return salary;}

void Artist::artistDisplay(){
	cout << aName << " has produced " << singles << " amount of singles and has earned a total of "
			<< salary << " euro." << endl;
}




