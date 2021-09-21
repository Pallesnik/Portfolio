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
	
	int semid, semid2, read_count = 0;
	string line;
	char answer;

	semid=semget(SEMKEY,1,0777|IPC_CREAT);               // Creating 2 semaphores
	semid2=semget(SEMKEY2,1,0777|IPC_CREAT);

	Wsembuf.sem_num=0;                                   // Setting up waits and signals for each
	Wsembuf.sem_op=-1;                                   // semaphore
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

	ifstream myfile("formal.txt", ios::in);              // Setting up file for being read from

	while(1){
		cout << "Do you want to read? Enter y or n:";// Asking if user wants to read
		cin >> answer;
		
		if(answer == 'y'){

			// Entry Section
			semop(semid2,&W1sembuf,1);           // Locks out other readers
			read_count = semctl(semid2,0,GETVAL);// Gets value of counting semaphore
			// Entry Critical Section
			if(read_count == 0){                 // If no other reader then
				semop(semid, &Wsembuf, 1);   // Locks out writer
			}
			
			semop(semid2,&S1sembuf,1);           // Unlocks semaphore for other readers
			
			// Reading process
			myfile.open("formal.txt");           // Opens file
			if(myfile.is_open())
			{
				while(getline(myfile,line))  // Gets each line from file and prints
				{	                     // line to the terminal
					cout << line << endl;
				}
				myfile.close();              // Closes file
			}

			// Exit Section
			semop(semid2,&W1sembuf,1);           // Down on counting semaphore
			read_count = semctl(semid2,0,GETVAL);// Gets value of counting semaphore
			// Exit Critical Section
			if(read_count == 0){                 // If no more readers then
				semop(semid, &Ssembuf, 1);   // Unlock semaphore for writer
			}
			semop(semid2,&S1sembuf,1);           // Up on counting semaphore
		}
		answer = 'n';                                // Reset input
	}
	return 0;
}
