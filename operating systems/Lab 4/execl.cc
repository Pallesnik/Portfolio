#include <iostream>
#include <unistd.h>
using namespace std;
main(){
	cout<<"executing ls"<<endl;
	execl("/bin/ls","ls",NULL);
	/* if execl returns, the call has failed so*/
	cout <<"execl failed to run ls";
}
