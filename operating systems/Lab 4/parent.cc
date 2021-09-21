#include <iostream>
#include <unistd.h>
using namespace std;
main() {
        int childid; /* holds process-id in parent*/
        childid=fork(); /* create new process*/
	if(childid == 0){
		for(int j=0;j<=99;j++){
			cout<< endl<<"hello from child";
		}
	}
	if(childid != 0){
                for(int j=0;j<=99;j++){
                        cout<< endl<<"hello from parent";
                }
        }

}
