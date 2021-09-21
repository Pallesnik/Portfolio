#include <iostream>
#include <unistd.h>
#include <pthread.h> /* POSIX threads */
using namespace std;
void *thread_routine1 (void *arg1 )
{ 
   //string x;
   cout << "Enter a word ";
   //cin >> x >> endl;
   //(string *)arg1 = &x;
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
        int rc,cr;
        pthread_t thread1,thread2;
	string string1;
	string *ptr;
	while(1){
        	cout <<"main process has PID="<< getpid()<<endl;
        	/* create thread  */
        	rc=pthread_create(&thread1, NULL,thread_routine1,NULL);
        	if (rc==1){
                	cout <<"Thread1 creation failed"<<endl;
        	}
        	pthread_join(thread1,NULL);
		cin >> string1;
		//ptr = &string1;
        	cr=pthread_create(&thread2, NULL,thread_routine2,(void *)&string1);
        	if (cr==1){
                	cout <<"Thread2 creation failed"<<endl;
        	}
        	pthread_join(thread2,NULL); 
        	cout <<"main thread is finished"<<endl;
	}
} 


