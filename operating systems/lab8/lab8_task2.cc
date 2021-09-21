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
	char answer;
	msgid = msgget(KEY, 0777|IPC_CREAT);
	msgid2 = msgget(KEY2, 0777|IPC_CREAT);
	struct msgbuff msg; 
	msg.mtype = 1;
	 for(int i=0; i<5; i++){
		strcpy(msg.mtext,"");
		msgsnd(msgid, &msg, SIZE, 0);
	}
	while(1){
		msgrcv(msgid2, &msg, SIZE, msg.mtype, 0);
		cout << "Would you like to view the message? Enter Y or N: ";
		cin >> answer;
		if(answer == 'Y'){
			cout << msg.mtext << endl;
		}
		else{}
		strcpy(msg.mtext,"");
		msgsnd(msgid, &msg, SIZE, 0);
	}
}
