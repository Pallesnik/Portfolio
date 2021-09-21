#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<sys/sem.h>
#include <iostream>
#include <unistd.h>
using namespace std;
#define SHM_KEY 9878
#define SEMKEY 151

main()
{
	string bob; 
	struct sembuf Ssembuf,Wsembuf;
	int semid,i;
	semid=semget(SEMKEY,1,0777|IPC_CREAT);
	int shmid, *ptr;
	string *ptr1;
	/*  create a 256 byte block of shared memory */
	shmid = shmget(SHM_KEY, 256, 0777|IPC_CREAT);
	/*  attach the process to the shared memory area  */
	ptr = (int *)shmat(shmid, 0, 0);
	/* ptr now holds the address of the first location in shared memory  */
	
	Wsembuf.sem_num=0;
	Wsembuf.sem_op=-1; 
	Wsembuf.sem_flg=SEM_UNDO;
	Ssembuf.sem_num=0;
	Ssembuf.sem_op=1;
	Ssembuf.sem_flg=SEM_UNDO;
	while(1){
		semop(semid,&Wsembuf,1);
		if (*ptr == 0){
			*ptr = 1;
		}
		else{
			*ptr = 0;
		}
		semop(semid,&Ssembuf,1);
	}
} 
