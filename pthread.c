#include<stdio.h>
#include<cstdlib.h>
#include<pthread.h>
#define NUM_THREADS 5

void *PrintHello(void *tid)
{
	long tid;
	tid = (long)threadid;
	printf("Hi \n", tid);
	pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for(t=0; t<NUM_THREADS; t++)
	{
		printf("In main: creating thread %1d\n",t);
		rc = pthread_create(&threads[t], NULL,PrintHello,(void)*t);
		if(rc){
			printf("ERROR: return code from pthread_create() is %d\n", rc);
			exit(-1);
			
		}
		}
		pthread_exit(NULL);
}
