#include <iostream>
#include <unistd.h>
using namespace std;
main() {
	int childid; 	/* holds process-id in parent*/
	childid=fork(); /* create new process*/
	if(childid == 0){
		cout<< endl<<"Hello from child" << endl;
		execl("/home/student/ls","ls",NULL);
	}
	else{
		cout<<endl<<"Hello from parent" << endl ;// ensure you have endl here //
        	execl("/bin/ls","ls",NULL);
	}
}
