#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <unistd.h>
using namespace std;
#define SHM_KEY 9876
 
main()
{ 
	int shmid, *ptr;
	/*  create a 256 byte block of shared memory */
	shmid = shmget(SHM_KEY, 256, 0777|IPC_CREAT);
	/*  attach the process to the shared memory area  */
	ptr = (int *)shmat(shmid, 0, 0);
	/* ptr now holds the address of the first location in shared memory  */
	*ptr = 0;
	cout << "Terminating process 2" << endl;
	return 0;
} 
