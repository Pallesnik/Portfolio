#ifndef INDIEDEV_H_
#define INDIEDEV_H_

#include "Developer.h"

class IndieDev: public Developer{
public:

	IndieDev(string n);
	bool backedByKickstarter();
	int calcSalary();


};





#endif

