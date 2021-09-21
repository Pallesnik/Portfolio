#include <iostream>
#include <unistd.h>
#include <pthread.h> /* POSIX threads */
using namespace std;
void *thread_routine1 (void *arg1 )
{ 
   cout <<"Hello"<<endl;
   pthread_exit(NULL);
} 

void *thread_routine2 (void *arg2 )
{ 
   cout <<"world"<<endl;
   pthread_exit(NULL);
} 

int main ()
{ 
        pthread_t thread1,thread2;
	//pthread_t thread2;
        cout <<"main process has PID="<< getpid()<<endl;
    	/* create thread  */
        pthread_create(&thread1, NULL,thread_routine1,NULL); 
	pthread_create(&thread2, NULL,thread_routine2,NULL); 
	cout <<"main thread is finished"<<endl;
	pthread_exit(NULL);
} 
