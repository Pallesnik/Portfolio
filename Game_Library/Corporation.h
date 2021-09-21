#include "Developer.h"

#ifndef CORPORATION_H_
#define CORPORATION_H_

class Corporation: public Developer{
public:
	Corporation(string n);
	void addOffice(string m);
	void setOfficeLocation(string mn);
	string getOfficeLocation();
	void setNofOffices(int n);
	int getNofOffices();
	void CorporationDisplay();
	int calcSalary();


private:
	vector <string> CorporationOffices;
	int nofOffices;
	string officeLocation;




};



#endif


