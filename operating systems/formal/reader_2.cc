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
	
	int semid, semid2, semid3, semid4, read_count = 0;
	string line;
	char answer;

	semid=semget(SEMKEY,1,0777|IPC_CREAT);                // Creating 4 semaphores
	semid2=semget(SEMKEY2,1,0777|IPC_CREAT);
	semid3=semget(SEMKEY3,1,0777|IPC_CREAT);
	semid3=semget(SEMKEY4,1,0777|IPC_CREAT);

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

	ifstream myfile("formal.txt", ios::in);              // Setting up file to read from

	while(1){
		cout << "Do you want to read? Enter y or n:";// Asking user if they want to read
		cin >> answer;
		
		if(answer == 'y'){
			// Entry Section
			semop(semid4,&W3sembuf,1);           // Down on writers counting semaphore
			semop(semid2,&W1sembuf,1);           // Down on readers semaphore
			// Entry Critical Section
			read_count = semctl(semid2,0,GETVAL);// Checking value of readers semaphore
			if(read_count == 0){                 // if no readers then
				semop(semid, &Wsembuf, 1);   // Lock out writers
			}
			
			semop(semid2,&S1sembuf,1);           // Up on readers semaphore
			semop(semid4,&S3sembuf,1);           // Up on writers counting semaphore 

			// Reading Section
			myfile.open("formal.txt");           // Open shared file
			if(myfile.is_open())
			{
				while(getline(myfile,line))  // Read in lines from file and print to
				{	                     // terminal
					cout << line << endl;
				}
				myfile.close();              // Close file
			}

			// Exit Section
			semop(semid2,&W1sembuf,1);           // Down on readers semaphore
			// Exit Critical Section
			read_count = semctl(semid2,0,GETVAL);
			if(read_count == 0){                 // if no readers then
				semop(semid, &Ssembuf, 1);   // Unlock file for writers
			}
			semop(semid2,&S1sembuf,1);           // Up on readers semaphore
		}
		answer = 'n';                                // Reset input
	}
	return 0;
}
