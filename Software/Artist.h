
#include <string>
#include <iostream>
#include <vector>
#ifndef ARTIST_H_
#define ARTIST_H_
using namespace std;

class Artist{
protected:
	string aName;
	int singles;
	float salary;
public:
	Artist();
	Artist(string a);
	void setartistName(string n);
	void setnofSinglesReleased(int nos);
	void setsalaryEarned(float se);
	string getartistName();
	int getnofSinglesReleased();
	float getsalaryEarned();
	void artistDisplay();
};



#endif /* ARTIST_H_ */

