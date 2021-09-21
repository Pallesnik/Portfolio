#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<sys/sem.h>
#include <iostream>
#include <unistd.h>
using namespace std;
#define SHM_KEY 151

main()
{
	string bob; 
	struct sembuf Ssembuf,Wsembuf;
	int semid,i;
	semid=semget(SHM_KEY,1,0777|IPC_CREAT);
	semctl(semid,0,SETVAL,1);
	
	Wsembuf.sem_num=0;
	Wsembuf.sem_op=-1; 
	Wsembuf.sem_flg=SEM_UNDO;
	Ssembuf.sem_num=0;
	Ssembuf.sem_op=1;
	Ssembuf.sem_flg=SEM_UNDO;
	semop(semid,&Wsembuf,1);
	cout << "Enter a message: ";
	cin >> bob;
	cout << "\ngo away" << endl;
	semop(semid,&Ssembuf,1);
} 
