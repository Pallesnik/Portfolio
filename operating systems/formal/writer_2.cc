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
#define SEMKEY3 153
#define SEMKEY4 154

struct sembuf Ssembuf,Wsembuf,S1sembuf,W1sembuf,S2sembuf,W2sembuf,S3sembuf,W3sembuf;

main()
{
	
	int semid, semid2, semid3, semid4, write_count = 0;
	char line[256];
	char answer;

	semid=semget(SEMKEY,1,0777|IPC_CREAT);                // Creating 4 semaphores
	semid2=semget(SEMKEY2,1,0777|IPC_CREAT);
	semid3=semget(SEMKEY3,1,0777|IPC_CREAT);
	semid4=semget(SEMKEY4,1,0777|IPC_CREAT);

	Wsembuf.sem_num=0;                                    // Setting up waits and signals for each
	Wsembuf.sem_op=-1;                                    // semaphore
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

	W2sembuf.sem_num=2;
	W2sembuf.sem_op=-1; 
	W2sembuf.sem_flg=SEM_UNDO;

	S2sembuf.sem_num=2;
	S2sembuf.sem_op=1;
	S2sembuf.sem_flg=SEM_UNDO;

	W3sembuf.sem_num=3;
	W3sembuf.sem_op=-1; 
	W3sembuf.sem_flg=SEM_UNDO;

	S3sembuf.sem_num=3;
	S3sembuf.sem_op=1;
	S3sembuf.sem_flg=SEM_UNDO;

	ofstream myfile("formal.txt");                        // Setting up file to write to

	while(1){

		// Entry Section
		semop(semid3,&W2sembuf,1);                    // Down on writing semaphore
		// Entry Critical Section
		write_count = semctl(semid3,0,GETVAL);
		if(write_count == 0){                         // If no other writers then
			semop(semid4, &W3sembuf, 1);          // Lock out readers
		}
		
		semop(semid3,&S2sembuf,1);                    // Up on writing semaphore

		// Writing Section
		semop(semid,&Wsembuf,1);                      // Locking out all other processes
		myfile.open("formal.txt", ios::app);          // Open file to append to
		if(myfile.is_open())
		{
			cout << "What do you want to input: ";
			cin.getline(line,256);                // Get user input to write to file
			myfile << line << endl;
		}
		else{
			cout << "Unable to open file!" << endl;
		}
		myfile.close();                                // Close file 
		semop(semid,&Ssembuf,1);                       // Unlock semaphore for other processes

		// Exit Section
		semop(semid3,&W2sembuf,1);		       // Down on writing semaphore
		// Exit Critical Section
		write_count = semctl(semid3,0,GETVAL);
		if(write_count == 0){                          // If no more writers
			semop(semid4, &S3sembuf, 1);           // Unlock semaphore for readers
		}
		semop(semid3,&S2sembuf,1);                     // Up on writing semaphore

	}
	return 0;
}
