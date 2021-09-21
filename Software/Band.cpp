#include "Band.h"


Band::Band(string n):Artist(n){
	aName=n;
	nofMembers=0;
}

void Band::setMemberName(string mn){memberName=mn;}
string Band::getMemberName(){return memberName;}
void Band::setNofMembers(int n){nofMembers=n;}
int Band::getNofMembers(){return nofMembers;}

void Band::addMember(string m){
	bandMembers.push_back(m);
}

void Band::bandDisplay(){

	cout << "The band " << aName << " has " << nofMembers << " members"<<endl;
}







