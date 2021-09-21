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
#define KEY2 2252

struct msgbuff {  
	long mtype;
	char mtext[SIZE];
}; 

main(){
	int msgid, msgid2, *ptr;
	char answer[SIZE];
	msgid = msgget(KEY, 0777);
	msgid2 = msgget(KEY2, 0777);
	struct msgbuff msg; 
	msg.mtype = 1;
	for(int i=0; i<5; i++){
		msgrcv(msgid, &msg, SIZE, msg.mtype, 0);
		cout << msg.mtext << endl;
	}
	while(1){
		cout << "What would you like to send?" << endl;
		cin >> answer;
		strcpy(msg.mtext, answer);
		msgsnd(msgid2, &msg, SIZE, 0);
		msgrcv(msgid, &msg, SIZE, msg.mtype, 0);
	}
}

