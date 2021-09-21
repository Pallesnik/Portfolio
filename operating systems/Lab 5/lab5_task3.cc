#include <iostream>
#include <unistd.h>
#include <pthread.h> /* POSIX threads */
using namespace std;
void *thread_routine1 (void *arg1 )
{
   int *x = (int *)arg1; 
   cout << "Hello World (thread "<< *x <<")" << endl;
   pthread_exit(NULL);
} 

void *thread_routine2 (void *arg2 )
{ 
   int *x = (int *)arg2;
   cout << "Hello World (thread "<< *x <<")" << endl;
   pthread_exit(NULL);
} 

void *thread_routine3 (void *arg3 )
{ 
   int *x = (int *)arg3;
   cout << "Hello World (thread "<< *x <<")" << endl;
   pthread_exit(NULL);
} 

void *thread_routine4 (void *arg4 )
{ 
   int *x = (int *)arg4;
   cout << "Hello World (thread "<< *x <<")" << endl;
   pthread_exit(NULL);
} 

void *thread_routine5 (void *arg5 )
{ 
   int *x = (int *)arg5;
   cout << "Hello World (thread "<< *x <<")" << endl;
   pthread_exit(NULL);
} 

void *thread_routine6 (void *arg6 )
{ 
   int *x = (int *)arg6;
   cout << "Hello World (thread "<< *x <<")" << endl;
   pthread_exit(NULL);
} 

void *thread_routine7 (void *arg7 )
{ 
   int *x = (int *)arg7;
   cout << "Hello World (thread "<< *x <<")" << endl;
   pthread_exit(NULL);
} 

void *thread_routine8 (void *arg8 )
{ 
   int *x = (int *)arg8;
   cout << "Hello World (thread "<< *x <<")" << endl;
   pthread_exit(NULL);
} 

void *thread_routine9 (void *arg9 )
{ 
   int *x = (int *)arg9;
   cout << "Hello World (thread "<< *x <<")" << endl;
   pthread_exit(NULL);
} 

void *thread_routine10 (void *arg10 )
{ 
   int *x = (int *)arg10;
   cout << "Hello World (thread "<< *x <<")" << endl;
   pthread_exit(NULL);
} 

int main ()
{ 
        int r1,r2,r3,r4,r5,r6,r7,r8,r9,r10;
        pthread_t thread1,thread2,thread3,thread4,thread5,thread6,thread7,thread8,thread9,thread10;
        pthread_t thread_array[10] = {thread1,thread2,thread3,thread4,thread5,thread6,thread7,thread8,thread9,thread10};
        int *ptr;
	int x[10] = {1,2,3,4,5,6,7,8,9,10};
	ptr = x;
	cout <<"main process has PID="<< getpid()<<endl;
        /* create thread  */
        r1=pthread_create(&thread1, NULL,thread_routine1,(void *)ptr);
        if (r1==1){
                cout <<"Thread1 creation failed"<<endl;
        }
        pthread_join(thread1,NULL);
	ptr++;
        r2=pthread_create(&thread2, NULL,thread_routine2,(void *)ptr);
        if (r2==1){
                cout <<"Thread2 creation failed"<<endl;
        }
        pthread_join(thread2,NULL);
	ptr++;
	r3=pthread_create(&thread3, NULL,thread_routine3,(void *)ptr);
        if (r3==1){
                cout <<"Thread3 creation failed"<<endl;
        }
        pthread_join(thread3,NULL);
	ptr++;
        r4=pthread_create(&thread4, NULL,thread_routine4,(void *)ptr);
        if (r4==1){
                cout <<"Thread4 creation failed"<<endl;
        }
        pthread_join(thread4,NULL);
	ptr++; 
	r5=pthread_create(&thread5, NULL,thread_routine5,(void *)ptr);
        if (r5==1){
                cout <<"Thread5 creation failed"<<endl;
        }
        pthread_join(thread5,NULL);
	ptr++;
        r6=pthread_create(&thread6, NULL,thread_routine6,(void *)ptr);
        if (r6==1){
                cout <<"Thread6 creation failed"<<endl;
        }
        pthread_join(thread6,NULL);
	ptr++;
	r7=pthread_create(&thread7, NULL,thread_routine7,(void *)ptr);
        if (r7==1){
                cout <<"Thread7 creation failed"<<endl;
        }
        pthread_join(thread7,NULL);
	ptr++;
        r8=pthread_create(&thread8, NULL,thread_routine8,(void *)ptr);
        if (r8==1){
                cout <<"Thread8 creation failed"<<endl;
        }
        pthread_join(thread8,NULL);
	ptr++; 
        r9=pthread_create(&thread9, NULL,thread_routine9,(void *)ptr);
        if (r9==1){
                cout <<"Thread9 creation failed"<<endl;
        }
        pthread_join(thread9,NULL);
	ptr++;
        r10=pthread_create(&thread10, NULL,thread_routine10,(void *)ptr);
        if (r10==1){
                cout <<"Thread10 creation failed"<<endl;
        }
        pthread_join(thread10,NULL);  
        cout <<"main thread is finished"<<endl;
        pthread_exit(NULL);
} 


