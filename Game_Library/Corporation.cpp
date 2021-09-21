#include "Corporation.h"


Corporation::Corporation(string n):Developer(n){
	DevName=n;
	nofOffices=0;
	salary=0;
}

void Corporation::setOfficeLocation(string mn){officeLocation=mn;}
string Corporation::getOfficeLocation(){return officeLocation;}
void Corporation::setNofOffices(int n){nofOffices=n;}
int Corporation::getNofOffices(){return nofOffices;}

void Corporation::addOffice(string m){
	CorporationOffices.push_back(m);
}

void Corporation::CorporationDisplay(){

	cout << "The Corporation " << DevName << " has " << nofOffices << " offices"<<endl;
}

int Corporation::calcSalary(){
    salary=1000000;
    cout<<salary<<endl;
    return salary;
}








