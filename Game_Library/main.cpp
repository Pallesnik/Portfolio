#include "Game.h"
#include "IndieDev.h"
#include "Corporation.h"
#include <iostream>
using namespace std;

int main() {
	Game g1("Buddy Holly");
	g1.setGenre("Rock");
	g1.setDuration(3);
	Developer d1("Weazer");
	d1.setnofGamesReleased(5);
	d1.setSalaryEarned(100000);
	g1.setDeveloper(d1);
	Corporation c("Bethesda");
	IndieDev id("Mojang");
	vector <Developer*> devVec;
	devVec.push_back(&c);
	devVec.push_back(&id);
	for(int i=0; i<devVec.size(); i++){
        devVec[i] -> calcSalary();
	}
	return 0;
}
