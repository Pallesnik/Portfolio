#include <iostream>
#include <unistd.h>
using namespace std;
main(){
        cout<<"executing parent2"<<endl;
        execl("/home/student/parent2","./parent2",NULL);
        /* if execl returns, the call has failed so*/
        cout <<"execl failed to run ls";
}

