#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
using namespace std;
#define SEMKEY 151
#define SEMKEY2 152


struct sembuf Ssembuf,Wsembuf,S1sembuf,W1sembuf;

main()
{ 
	int semid, semid2;
	char line[256];

	semid=semget(SEMKEY,1,0777|IPC_CREAT);                   // Creating 2 semaphores
	semid2=semget(SEMKEY2,1,0777|IPC_CREAT);

	semctl(semid, 0, SETVAL, 1);                             // Initialising semaphores
	semctl(semid, 1, SETVAL, 1);

	Wsembuf.sem_num=0;                                       // Setting up semaphore waits and 
	Wsembuf.sem_op=-1;                                       // signals
	Wsembuf.sem_flg=SEM_UNDO;

	Ssembuf.sem_num=0;
	Ssembuf.sem_op=1;
	Ssembuf.sem_flg=SEM_UNDO;
	
	W1sembuf.sem_num=1;
	W1sembuf.sem_op=-1; 
	W1sembuf.sem_flg=SEM_UNDO;

	S1sembuf.sem_num=1;
	S1sembuf.sem_op=1;
	S1sembuf.sem_flg=SEM_UNDO;

	ofstream myfile("formal.txt");                           // Setting up file to write to
	
	while(1){
		//Entry Section		
		semop(semid,&Wsembuf,1);                         // Locking semaphore for shared file
		
		// Critical Section
		myfile.open("formal.txt", ios::app);             // Opening file for appending input
		if(myfile.is_open())
		{
			cout << "What would you like to write: ";
			cin.getline(line,256);                   // Taking input
			myfile << line << endl;                  // Writing to file
		}
		else
		{
			cout << "Unable to open file!" << endl;
		}
		myfile.close();                                  // closing file

		// Exit Section
		semop(semid,&Ssembuf,1);                         // Unlocking shared file semaphore
	}
	return 0;
}
