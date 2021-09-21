#include "Artist.h"

#ifndef BAND_H_
#define BAND_H_

class Band: public Artist{
public:
	Band(string n);
	void addMember(string m);
	void setMemberName(string mn);
	string getMemberName();
	void setNofMembers(int n);
	int getNofMembers();
	void bandDisplay();


private:
	vector <string> bandMembers;
	int nofMembers;
	string memberName;




};



#endif /* BAND_H_ */

