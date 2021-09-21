#include <iostream>
#include <unistd.h>
using namespace std;
main() {
	int childid; /* holds process-id in parent*/
	cout<<endl<<" just one process so far" << endl ;// ensure you have endl here //
	childid=fork(); /* create new process*/
	cout<< endl<<" a process is running here";
}
