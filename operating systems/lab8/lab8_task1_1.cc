#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <iostream>
#include <unistd.h>
#include <sys/msg.h>
#include <cstring>

using namespace std;

#define SIZE 100
#define KEY 2251

struct msgbuff {  
	long mtype;
	char mtext[SIZE];
}; 

main(){
	int msgid, *ptr;
	msgid = msgget(KEY, 0777);
	struct msgbuff msg1; 
	msg1.mtype = 1;
	//strcpy(msg.mtext,"hello from sending process");
	msgrcv(msgid, &msg1, SIZE, msg1.mtype, 0);
	cout << msg1.mtext << endl;
}
