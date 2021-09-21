
#include <string>
#include <iostream>
#include <vector>
#ifndef DEVELOPER_H_
#define DEVELOPER_H_
using namespace std;

class Developer{
protected:
	string DevName;
	int games;
	float salary;
public:
	Developer();
	Developer(string a);
	void setDeveloperName(string n);
	void setnofGamesReleased(int nog);
	void setSalaryEarned(float se);
	string getDeveloperName();
	int getnofGamesReleased();
	float getSalaryEarned();
	void DeveloperDisplay();
	virtual int calcSalary();
};



#endif


