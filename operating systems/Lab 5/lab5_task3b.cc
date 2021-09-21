#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h> /* POSIX threads */
using namespace std;
void *thread_routine1 (void *arg1 )
{ 
   string *x = (string *)arg1;
   cout <<*x<<endl;
   pthread_exit(NULL);
} 

void *thread_routine2 (void *arg2 )
{ 
   string *x = (string *)arg2;
   cout <<*x<<endl;
   pthread_exit(NULL);
} 

int main ()
{
	string array[2] = {"Hello","World"};
	string *ptr;
	ptr = array;
        int rc,cr;
        pthread_t thread1,thread2;
        //pthread_t thread2;
        cout <<"main process has PID="<< getpid()<<endl;
        /* create thread  */
        rc=pthread_create(&thread1, NULL,thread_routine1,(void *)ptr);
        if (rc==1){
                cout <<"Thread1 creation failed"<<endl;
        }
        pthread_join(thread1,NULL);
	ptr++;
        cr=pthread_create(&thread2, NULL,thread_routine2,(void *)ptr);
        if (cr==1){
                cout <<"Thread2 creation failed"<<endl;
        }
        pthread_join(thread2,NULL); 
        cout <<"main thread is finished"<<endl;
        pthread_exit(NULL);
} 

